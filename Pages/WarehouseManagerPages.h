#ifndef FINAL_PROJECT_WAREHOUSEMANAGERPAGES_H
#define FINAL_PROJECT_WAREHOUSEMANAGERPAGES_H

#include <iostream>
#include "RequestFunctions.h"

class WarehouseManagerPages{
public:
    static inline void warehousePage() {
        while (true){
            system(consoleClear.c_str());
            int action;
            std::cout << "Страница складского менеджера" << std::endl;
            std::cout << "1.Добавить новую заявку\n2.Удалить заявку\n3.Просмотр заявок\n" << "Выберите действие(Введите 0 для выхода): " << std::endl;
            std::cin >> action;

            if (std::cin.fail()){
                std::cout << "Ошибка! Неверный ввод!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }
            if (action == 0){
                break;
            }

            if (action == 1){
                addNewRequestPage();
            } else if (action == 2){
                deleteRequestPage();
            } else if(action == 3){
                requestsPrintPage();
            } else {
                std::cout << "Ошибка! Введите число в диапазоне от 1 до 1!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }

        }
    }

    static inline void addNewRequestPage(){
        std::vector<std::map<int, std::map<int, std::shared_ptr<Product>>>> rProductsList;
        while (true) {
            system(consoleClear.c_str());

            std::map<int, std::map<int, std::shared_ptr<Product>>> productMap;
            std::map<int, std::shared_ptr<Product>> product;
            int productId = 0, count = 0;

            std::cout << "Выберите продукты из списка: " << std::endl;
            ProductFunctions::printProductList(Product::productList);
            std::cout << "Выбор(Введите 0 для выхода): " << std::endl;
            std::cin >> productId;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (productId == 0) {
                if (!rProductsList.empty()){
                    RequestFunctions::addNewRequest(rProductsList);
                    RequestFunctions::saveRequestsToJson();
                }
                break;
            }

            try {
                auto iterator = std::find_if(Product::productList.begin(), Product::productList.end(),
                                             [productId](const std::shared_ptr<Product> &product) {
                                                 return product->id == productId;
                                             });

                if (productId > Product::productList.size() or productId < 0){
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Такого продукта нету в списке!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    continue;
                }

                std::cout << "Введите количество продукта: " << std::endl;
                std::cin >> count;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Ошибка! Введите число!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    continue;
                }

                //std::shared_ptr<Product> pr = *iterator;


                product[count] = *iterator;

                productMap[productId] = product;

                rProductsList.push_back(productMap);


/*                Product::productList.erase(std::remove_if(Product::productList.begin(), Product::productList.end(),
                                              [productId](const std::shared_ptr<Product> &product) {
                                                  return product->id == productId;
                                              }), Product::productList.end());*/
            }
            catch (std::exception ex) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Такого продукта нету в списке!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
        }
    }

    static inline void deleteRequestPage(){
        while (true) {
            system(consoleClear.c_str());
            std::shared_ptr<Request> request;
            int requestId;
            RequestFunctions::printRequests();
            std::cout << "Введите ID заявки для удаления(Введите 0 для выхода): " << std::endl;
            std::cin >> requestId;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (requestId == 0) {
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

            RequestFunctions::deleteRequest(requestId);

        }
    }

    static inline void requestsPrintPage(){
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
};


#endif //FINAL_PROJECT_WAREHOUSEMANAGERPAGES_H
