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

        Menu::menuProductList.push_back(std::make_shared<Menu>(name, description, gramming, cost, hour, min, sec, productList));
    }
};

#endif //FINAL_PROJECT_MENUFUNCTIONS_H
