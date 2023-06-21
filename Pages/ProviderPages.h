//
// Created by jcpremizov on 21.06.23.
//

#ifndef FINAL_PROJECT_PROVIDERPAGES_H
#define FINAL_PROJECT_PROVIDERPAGES_H

#include <cstdlib>
#include "Request.h"
#include "RequestFunctions.h"
#include "ProviderFunctions.h"

class ProviderPages{
public:
    static inline void providerPage(){
        while (true) {
            system(consoleClear.c_str());
            int action;
            std::cout << "Страница поставщика" << std::endl;
            std::cout << "1.Принять заявку\n2.Просмотр принятых заявок\n" << "Введите действие(Введите 0 для выхода):" << std::endl;
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
                approveRequestPage();
            } else if (action == 2){
                printApprovedRequestsPage();
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

    static inline void approveRequestPage(){
        while (true){
            system(consoleClear.c_str());
            int requestId = 0;
            std::shared_ptr<Request> request;
            RequestFunctions::printRequests();
            std::cout << "Введите номер заявки для одобрения(Введите 0 для выхода): " << std::endl;
            std::cin >> requestId;
            if (std::cin.fail()) {
                std::cout << "Ошибка ввода!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }
            if (requestId == 0){
                break;
            }

            for (const auto &item: Request::requestsList) {
                if (requestId == item->id) {
                    request = item;
                }
            }

            if (request == nullptr) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Такой заявки нету!" << std::endl;
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            ProviderFunctions::approveRequest(request);
            ProviderFunctions::addProductToWarehouse(request);

            Restaurant::balance -= request->totalCost;
            Restaurant::saveToJson();
            RequestFunctions::deleteRequest(requestId);
            RequestFunctions::saveRequestsToJson();
            RequestFunctions::saveApprovedRequestsToJson();



        }
    }

    static inline void printApprovedRequestsPage(){
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

};

#endif //FINAL_PROJECT_PROVIDERPAGES_H
