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
    static inline void addNewMenuItem(const std::string& name, const std::string& description, const float& gramming, const float& cost, const int& hour, const int& min, const int& sec, const std::vector<std::shared_ptr<Product>>& productList){
        std::uint16_t lastId = 1;
        if (!Menu::menuProductList.empty()) {
            lastId = Menu::menuProductList[Menu::menuProductList.size() - 1]->id + 1;
        }
        Menu::menuProductList.push_back(std::make_shared<Menu>(lastId ,name, description, gramming, cost, hour, min, sec, productList));
        saveMenuItems();
    }

    static inline void editMenuItem(const int& menuId , const std::string& name, const std::string& description, const float& gramming, const float& cost, const int& hour, const int& min, const int& sec, const std::vector<std::shared_ptr<Product>>& productList){

        try {
            auto iterator = std::find_if(Menu::menuProductList.begin(), Menu::menuProductList.end(),
                                         [menuId](const std::shared_ptr<Menu> &menu) {
                                             return menu->id == menuId;
                                         });
            std::shared_ptr<Menu>& menuItem = *iterator;

            menuItem->name = name;
            menuItem->description = description;
            menuItem->gramming = gramming;
            menuItem->cost = cost;
            menuItem->hour = hour;
            menuItem->min = min;
            menuItem->sec = sec;
            menuItem->productList = productList;
            saveMenuItems();
        }
        catch (std::exception ex){

        }


    }

    static inline void deleteMenuItem(const int& menuId){

        Menu::menuProductList.erase(std::remove_if(Menu::menuProductList.begin(), Menu::menuProductList.end(),[menuId](const std::shared_ptr<Menu> &menu) {return menu->id == menuId;}), Menu::menuProductList.end());
        saveMenuItems();

    }

    static inline void saveMenuItems(){

        std::thread saveMenuItemsThread([](){Menu::saveMenuItemsToJson();});
        saveMenuItemsThread.join();
    }

    static inline void loadMenuItems(){
        std::thread loadMenuItemsThread([](){Menu::loadMenuItemsFromJson();});
        loadMenuItemsThread.join();
    }
};

#endif //FINAL_PROJECT_MENUFUNCTIONS_H
