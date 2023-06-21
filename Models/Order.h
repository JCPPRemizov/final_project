//
// Created by jcpremizov on 21.06.23.
//

#ifndef FINAL_PROJECT_ORDER_H
#define FINAL_PROJECT_ORDER_H

#include <vector>
#include <memory>
#include <iostream>
#include "Menu.h"
#include "OrderType.h"

class Orders {
private:
    static inline std::vector<std::shared_ptr<Orders>> orderedMenuList;
public:

    Orders(OrderTypes orderType, std::shared_ptr<Menu> menuItem){
        this->orderType = orderType;
        this->menuItem = menuItem;
    }

    OrderTypes orderType;

    std::shared_ptr<Menu> menuItem;




   static void placeOrder(std::uint16_t menuId) {
        auto menuIt = std::find_if(Menu::menuProductList.begin(), Menu::menuProductList.end(),
                                   [menuId](const std::shared_ptr<Menu>& menu) {
            return menu->id == menuId;
        });

        if (menuIt != Menu::menuProductList.end()) {
            orderedMenuList.push_back(std::make_shared<Orders>(OrderTypes::WAITING, *menuIt));
            std::cout << "Заказ успешно добавлен." << std::endl;
        } else {
            std::cout << "Пункт не найден." << std::endl;
        }
    }

    static void cancelOrder(std::uint16_t menuId) {
        auto orderIt = std::find_if(orderedMenuList.begin(), orderedMenuList.end(),
                                    [menuId](const std::shared_ptr<Orders>& order) {
            return order->menuItem->id == menuId;
        });

        if (orderIt != orderedMenuList.end()) {
            orderedMenuList.erase(orderIt);
            std::cout << "Order canceled successfully." << std::endl;
        } else {
            std::cout << "Order not found." << std::endl;
        }
    }

    static void displayOrders() {
        std::cout << "Ordered Menus:" << std::endl;
        for (const auto& menu : orderedMenuList) {
            std::cout << menu->menuItem;
        }
    }
};

#endif //FINAL_PROJECT_ORDER_H
