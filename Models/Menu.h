//
// Created by jcpremizov on 19.06.23.
//

#ifndef FINAL_PROJECT_MENU_H
#define FINAL_PROJECT_MENU_H

#include <string>
#include <vector>
#include <memory>
#include "Product.h"

class Menu {
private:
    void toJson(json &j) const {
        j["id"] = id;
        j["name"] = name;
        j["description"] = description;
        j["gramming"] = gramming;
        j["cost"] = cost;
        j["hour"] = hour;
        j["min"] = min;
        j["sec"] = sec;

        json jMenuProductList;
        json jMenuItem;

        for (const auto &product: productList) {
            product->toJson(jMenuItem);
            jMenuProductList.push_back(jMenuItem);
        }

        j["productList"] = jMenuProductList;
    }

    static std::shared_ptr<Menu> fromJson(const json &j) {
        std::uint16_t id = j["id"].get<std::uint16_t>();
        std::string name = j["name"].get<std::string>();
        std::string description = j["description"].get<std::string>();
        float gramming = j["gramming"].get<float>();
        float cost = j["cost"].get<float>();
        int hour = j["hour"].get<int>();
        int min = j["min"].get<int>();
        int sec = j["sec"].get<int>();

        std::vector<std::shared_ptr<Product>> menuProductList;

        for (const auto &productData: j["productList"]) {

            std::uint16_t productId = productData["productId"];
            std::string productName = productData["productName"];
            float productCost = productData["productCost"];

            menuProductList.push_back(std::make_shared<Product>(productId, productName, productCost));
        }

        return std::make_shared<Menu>(id, name, description, gramming, cost, hour, min, sec, menuProductList);
    }

public:
    static inline std::vector<std::shared_ptr<Menu>> menuProductList;
    std::uint16_t id;
    int hour, min, sec;
    std::string name, description;
    float gramming, cost;
    std::vector<std::shared_ptr<Product>> productList;

    Menu(const std::uint16_t &id, const std::string &name, const std::string &description, const float &gramming,
         const float &cost, const int &hour, const int &min, const int &sec,
         const std::vector<std::shared_ptr<Product>> &productList) {
        this->id = id;
        this->name = name;
        this->description = description;
        this->gramming = gramming;
        this->cost = cost;
        this->hour = hour;
        this->min = min;
        this->sec = sec;
        this->productList = productList;
    }

    friend std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Menu> &menu) {
        os << "ID: " << menu->id << std::endl;
        os << "Название: " << menu->name << std::endl;
        os << "Описание: " << menu->description << std::endl;
        os << "Стоимость: " << menu->cost << std::endl;
        os << "Грамовка: " << menu->gramming << std::endl;
        std::ostringstream oss;
        oss << menu->hour << ":" << menu->min << ":" << menu->sec;
        std::string timeString = oss.str();
        os << "Время готовки: " << timeString << std::endl;
        os << "Продукты: " << std::endl;
        for (const auto &item: menu->productList) {
            os << item->name << std::endl;
        }
        os << "--------------------------------------" << std::endl;

        return os;
    }

    static void saveMenuItemsToJson() {
        json jMenuItems;
        std::string filename = "menuItems.json";
        for (const auto &menuItem: menuProductList) {
            json j;
            menuItem->toJson(j);
            jMenuItems.push_back(j);
        }
        std::ofstream ofs(filename);
        if (ofs.is_open()) {
            ofs << jMenuItems.dump(4);
            ofs.close();
        } else {
            std::cerr << "Ошибка записи в файл." << std::endl;
        }
    }

    static void loadMenuItemsFromJson() {
        try {
            std::string filename = "menuItems.json";
            std::ifstream ifs(filename);
            if (ifs.is_open()) {
                json jLoadedProducts;
                ifs >> jLoadedProducts;
                for (const auto &j: jLoadedProducts) {
                    menuProductList.push_back(Menu::fromJson(j));
                }
            } else {
                std::cerr << "Ошибка чтения файла." << std::endl;
            }
        }
        catch (std::exception ex) {

        }
    }


};

#endif //FINAL_PROJECT_MENU_H
