//
// Created by jcpremizov on 19.06.23.
//

#ifndef FINAL_PROJECT_MENU_H
#define FINAL_PROJECT_MENU_H

#include <string>
#include <vector>
#include <memory>
#include "Product.h"

class Menu{
private:
    int hour, min, sec;
    std::string name, description;
    float gramming, cost;
    std::vector<std::shared_ptr<Product>> productList;
public:
    static inline std::vector<std::shared_ptr<Menu>> menuProductList;

    Menu(const std::string& name, const std::string& description, const float& gramming, const float& cost, const int& hour, const int& min, const int& sec, const std::vector<std::shared_ptr<Product>>& productList){
        this->name = name;
        this->description = description;
        this->gramming = gramming;
        this->cost = cost;
        this->hour = hour;
        this->min = min;
        this->sec = sec;
        this->productList = productList;
    }

    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Menu>& menu) {
        os << "Название: " << menu->name << std::endl;
        os << "Описание: " << menu->description << std::endl;
        os << "Стоимость: " << menu->cost << std::endl;
        os << "Грамовка: " << menu->gramming << std::endl;
        std::ostringstream oss;
        oss << menu->hour << ":" << menu->min << ":" << menu->sec;
        std::string timeString = oss.str();
        os << "Время готовки: " << timeString << std::endl;
        os << "Продукты: " << std::endl;
        for (const auto& item:menu->productList){
            os << item->name << std::endl;
        }
        os << "--------------------------------------" << std::endl;

        return os;
    }
};

#endif //FINAL_PROJECT_MENU_H
