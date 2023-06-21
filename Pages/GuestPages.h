//
// Created by jcpremizov on 21.06.23.
//

#ifndef FINAL_PROJECT_GUESTPAGES_H
#define FINAL_PROJECT_GUESTPAGES_H

#include "Order.h"

class GuestPages{
public:
    static void guestPage(){
        while (true) {
            int userChoise;
            std::cout << "1.Сделать заказ\n" << "2.Просмотреть заказ\n"
                      << "Просмотреть меню\nВыберите действие(Введите 0 для выхода): " << std::endl;
            std::cin >> userChoise;
            if (std::cin.fail()) {
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клвишу для выхода" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
            }

            if (userChoise == 0) {
                break;
            }

            if (userChoise == 1){
                addToOrderPage();
            } else if (userChoise == 2){
                printOrder();
            } else if (userChoise == 3){
                menuPrint();
            } else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Такого действия нету!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }

        }

    }

    static void menuPrint(){
        while (true) {
            system(consoleClear.c_str());
            for (const auto &item: Menu::menuProductList) {

                std::cout << item;
            }
            std::cout << "Нажмите любую клвишу для выхода" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            getchar();
            break;
        }
    }

    static void addToOrderPage(){
        while (true) {
            std::uint16_t menuId;
            system(consoleClear.c_str());
            for (const auto &item: Menu::menuProductList) {

                std::cout << item;
            }
            std::cout << "Введите номер меню для заказа: " << std::endl;
            std::cin >> menuId;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!";
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (menuId == 0){
                break;
            }

            Orders::placeOrder(menuId);

        }
    }

    static void printOrder(){
        while (true) {
            system(consoleClear.c_str());
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system(consoleClear.c_str());
            Orders::displayOrders();
            std::cout << "Нажмите любую клвишу для выхода" << std::endl;
            getchar();
            break;
        }
    }
};

#endif //FINAL_PROJECT_GUESTPAGES_H
