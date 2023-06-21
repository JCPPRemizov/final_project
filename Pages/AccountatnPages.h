//
// Created by jcpremizov on 21.06.23.
//

#ifndef FINAL_PROJECT_ACCOUNTATNPAGES_H
#define FINAL_PROJECT_ACCOUNTATNPAGES_H


#include <iostream>
#include "RequestFunctions.h"
#include "ProviderFunctions.h"
#include "Restaurant.h"
#include "AdminPages.h"

class AccountantPages{
public:
    static void accountantPages(){
        while (true) {
            system(consoleClear.c_str());
            int action;
            std::cout << "Страница бухгалтера" << std::endl;
            std::cout << "1.Просмотреть отправленные заявки на продукты\n2.Просмотреть принятые заявки на продукты\n3.Просмотр баланса ресторана\n" << "Введите действие(Введите 0 для выхода):" << std::endl;
            std::cin >> action;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!";
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (action == 0) {
                break;
            } else if (action == 1) {
                sendedRequestsPage();
            } else if (action == 2){
                approvedRequestsPage();
            } else if (action == 3){
                restaurantBalancePage();
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

    static void sendedRequestsPage(){
        while (true) {
            system(consoleClear.c_str());
            RequestFunctions::printRequests();
            std::cout << "Нажмите любую клвишу для выхода" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            getchar();
            break;
        }
    }

    static void approvedRequestsPage(){
        while (true) {
            system(consoleClear.c_str());
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            ProviderFunctions::printApprovedRequests();
            std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
            getchar();
            break;
        }
    }

    static void restaurantBalancePage(){
        while (true) {
            system(consoleClear.c_str());
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Текущий баланс: " << Restaurant::balance << std::endl;
            std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
            getchar();
            break;
        }
    }
};

#endif //FINAL_PROJECT_ACCOUNTATNPAGES_H
