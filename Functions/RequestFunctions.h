//
// Created by jcpremizov on 20.06.23.
//

#ifndef FINAL_PROJECT_REQUESTFUNCTIONS_H
#define FINAL_PROJECT_REQUESTFUNCTIONS_H

#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include "Product.h"
#include "Request.h"

class RequestFunctions{
public:
    static inline void addNewRequest(std::vector<std::map<int, std::map<int, std::shared_ptr<Product>>>> productsList){
        std::uint16_t lastId = 1;
        if (!Request::requestsList.empty()) {
            lastId = Request::requestsList[Request::requestsList.size() - 1]->id + 1;
        }
        Request::requestsList.push_back(std::make_shared<Request>(lastId, productsList));
    }
    static inline void printRequests(){
        for (const auto& request : Request::requestsList) {
            std::cout << "ID Заявки: " << request->id << std::endl;
            for (const auto& outerMap : request->rProductsList) {
                for (const auto& innerMap : outerMap) {
                    std::cout << "ID Продукта: " << innerMap.first << std::endl;
                    for (const auto& productPair : innerMap.second) {
                        std::shared_ptr<Product> product = productPair.second;
                        std::cout << "Название продукта : " << product->name << std::endl;
                        std::cout << "Стоимость продукта: " << product->cost << std::endl;
                        std::cout << "Количество продукта: " << productPair.first << std::endl;
                        std::cout << std::endl;
                    }
                }
            }
            std::cout << "-----------------------------------------------" << std::endl;
        }

    }
};

#endif //FINAL_PROJECT_REQUESTFUNCTIONS_H
