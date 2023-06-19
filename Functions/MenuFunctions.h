//
// Created by jcpremizov on 19.06.23.
//

#ifndef FINAL_PROJECT_MENUFUNCTIONS_H
#define FINAL_PROJECT_MENUFUNCTIONS_H

#include <string>
#include <memory>
#include <vector>
#include "Product.h"
#include "Menu.h"

class MenuFunctions{
public:
    static void addNewMenu(const std::string& name, const std::string& description, const float& gramming, const float& cost, const int& hour, const int& min, const int& sec, const std::vector<std::shared_ptr<Product>>& productList){
        std::uint16_t lastId = 1;
        if (!Menu::menuProductList.empty()) {
            lastId = Menu::menuProductList[Menu::menuProductList.size() - 1]->id + 1;
        }
        Menu::menuProductList.push_back(std::make_shared<Menu>(lastId ,name, description, gramming, cost, hour, min, sec, productList));
    }

    static void editMenu(const int& menuId ,const std::string& name, const std::string& description, const float& gramming, const float& cost, const int& hour, const int& min, const int& sec, const std::vector<std::shared_ptr<Product>>& productList){
        std::shared_ptr<Menu>& menuItem = Menu::menuProductList[menuId - 1];
        menuItem->name = name;
        menuItem->description = description;
        menuItem->gramming = gramming;
        menuItem->cost = cost;
        menuItem->hour = hour;
        menuItem->min = min;
        menuItem->sec = sec;
        menuItem->productList = productList;
    }
};

#endif //FINAL_PROJECT_MENUFUNCTIONS_H
