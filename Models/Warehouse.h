//
// Created by jcpremizov on 20.06.23.
//

#ifndef FINAL_PROJECT_WAREHOUSE_H
#define FINAL_PROJECT_WAREHOUSE_H

#include <vector>
#include <memory>
#include <map>
#include <iostream>
#include <fstream>
#include "Product.h"
#include "json.hpp"
#include "Employee.h"

class Warehouse{
public:
    static inline std::vector<std::map<int, std::map<int, std::shared_ptr<Product>>>> wProductsList;

    static inline void saveWarehouseToJson() {
        json jsonData;

        for (const auto& request : Warehouse::wProductsList) {
            json requestJson;
            for (const auto& outerMap : request) {
                json outerMapJson;

                for (const auto& innerMap : outerMap.second) {
                    json innerMapJson;
                        std::shared_ptr<Product> product = innerMap.second;
                        json productJson;
                        productJson["id"] = product->id;
                        productJson["name"] = product->name;
                        productJson["cost"] = product->cost;
                        innerMapJson[std::to_string(innerMap.first)] = productJson;

                    outerMapJson[std::to_string(innerMap.first)] = innerMapJson;
                }

                requestJson["wProductsList"].push_back(outerMapJson);
            }

            jsonData.push_back(requestJson);
        }

        std::ofstream file("warehouse.json");
        if (file.is_open()) {
            file << jsonData.dump(4);  // Записываем отформатированный JSON с отступами (4 пробела)
            file.close();
        } else {
            std::cerr << "Невозможно открыть файл: " << "requests.json" << std::endl;
        }
    }

    static inline void loadRequestsFromJson() {
        std::ifstream file("warehouse.json");
        if (file.is_open()) {
            json jsonData;
            file >> jsonData;
            file.close();

            if (jsonData.is_array()) {
                Warehouse::wProductsList.clear();

                for (const auto& requestJson : jsonData) {

                    for (const auto& outerMapJson : requestJson["wProductsList"]) {
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

                        Warehouse::wProductsList.push_back(outerMap);
                    }

                }

            } else {
                std::cerr << "Неверный формат JSON: " << "requests.json" << std::endl;
            }
        } else {
            std::cerr << "Невозможно открыть файл: " << "requests.json" << std::endl;
        }
    }

};
#endif //FINAL_PROJECT_WAREHOUSE_H
