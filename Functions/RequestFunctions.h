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

    static inline void deleteRequest(const int& requestId){
        Request::requestsList.erase(std::remove_if(Request::requestsList.begin(), Request::requestsList.end(),[requestId](const std::shared_ptr<Request> &request) {return request->id == requestId;}), Request::requestsList.end());
    }

    static inline void saveRequestsToJson() {
        json jsonData;

        for (const auto& request : Request::requestsList) {
            json requestJson;
            requestJson["id"] = request->id;

            for (const auto& outerMap : request->rProductsList) {
                json outerMapJson;

                for (const auto& innerMap : outerMap) {
                    json innerMapJson;

                    for (const auto& productPair : innerMap.second) {
                        std::shared_ptr<Product> product = productPair.second;
                        json productJson;
                        productJson["id"] = product->id;
                        productJson["name"] = product->name;
                        productJson["cost"] = product->cost;

                        innerMapJson[std::to_string(productPair.first)] = productJson;
                    }

                    outerMapJson[std::to_string(innerMap.first)] = innerMapJson;
                }

                requestJson["rProductsList"].push_back(outerMapJson);
            }

            jsonData.push_back(requestJson);
        }

        std::ofstream file("requests.json");
        if (file.is_open()) {
            file << jsonData.dump(4);  // Записываем отформатированный JSON с отступами (4 пробела)
            file.close();
        } else {
            std::cerr << "Невозможно открыть файл: " << "requests.json" << std::endl;
        }
    }

    static inline void loadRequestsFromJson() {
        std::ifstream file("requests.json");
        if (file.is_open()) {
            json jsonData;
            file >> jsonData;
            file.close();

            if (jsonData.is_array()) {
                Request::requestsList.clear();

                for (const auto& requestJson : jsonData) {
                    std::shared_ptr<Request> request = std::make_shared<Request>();
                    request->id = requestJson["id"];

                    for (const auto& outerMapJson : requestJson["rProductsList"]) {
                        std::map<int, std::map<int, std::shared_ptr<Product>>> outerMap;

                        for (const auto& innerMapJson : outerMapJson.items()) {
                            std::map<int, std::shared_ptr<Product>> innerMap;

                            for (const auto& productJson : innerMapJson.value().items()) {
                                std::shared_ptr<Product> product;
                                std::uint16_t id = productJson.value()["id"];
                                std::string name = productJson.value()["name"];
                                float cost = productJson.value()["cost"];

                                product = std::make_shared<Product>(id,name,cost);

                                innerMap[std::stoi(productJson.key())] = product;
                            }

                            outerMap[std::stoi(innerMapJson.key())] = innerMap;
                        }

                        request->rProductsList.push_back(outerMap);
                    }

                    Request::requestsList.push_back(request);
                }

            } else {
                std::cerr << "Неверный формат JSON: " << "requests.json" << std::endl;
            }
        } else {
            std::cerr << "Невозможно открыть файл: " << "requests.json" << std::endl;
        }
    }

};

#endif //FINAL_PROJECT_REQUESTFUNCTIONS_H
