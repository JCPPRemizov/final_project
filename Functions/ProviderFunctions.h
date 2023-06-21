//
// Created by jcpremizov on 21.06.23.
//

#ifndef FINAL_PROJECT_PROVIDERFUNCTIONS_H
#define FINAL_PROJECT_PROVIDERFUNCTIONS_H

#include "Request.h"
#include "Warehouse.h"
#include "RequestFunctions.h"

class ProviderFunctions {
public:
    static inline void approveRequest(const std::shared_ptr<Request> &request) {

        Request::approvedRequestsList.push_back(request);
        RequestFunctions::saveApprovedRequestsToJson();
    }

    static inline void printApprovedRequests() {
        for (const auto &request: Request::approvedRequestsList) {
            std::cout << "ID Заявки: " << request->id << std::endl;
            for (const auto &outerMap: request->rProductsList) {
                for (const auto &innerMap: outerMap) {
                    std::cout << "ID Продукта: " << innerMap.first << std::endl;
                    for (const auto &productPair: innerMap.second) {
                        std::shared_ptr<Product> product = productPair.second;
                        std::cout << "Название продукта : " << product->name << std::endl;
                        std::cout << "Стоимость продукта: " << product->cost << std::endl;
                        std::cout << "Количество продукта: " << productPair.first << std::endl;
                    }
                }
            }
            std::cout << "Суммарная стоимость: " << request->totalCost << std::endl;
            std::cout << std::endl;

            std::cout << "-----------------------------------------------" << std::endl;
        }
    }

    static inline void addProductToWarehouse(const std::shared_ptr<Request> &request) {
        std::map<int, std::map<int, std::shared_ptr<Product>>> wProduct;
        for (const auto &outerMap: request->rProductsList) {
            for (const auto &innerMap: outerMap) {
                wProduct[innerMap.first] = innerMap.second;
            }
        }
        Warehouse::wProductsList.push_back(wProduct);
        Warehouse::saveWarehouseToJson();
    }
};

#endif //FINAL_PROJECT_PROVIDERFUNCTIONS_H
