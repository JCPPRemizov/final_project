//
// Created by jcpremizov on 19.06.23.
//

#ifndef FINAL_PROJECT_PRODUCT_H
#define FINAL_PROJECT_PRODUCT_H

#include <cstdint>
#include <string>
#include <vector>
#include <bits/shared_ptr.h>

class Product{
public:
    static inline std::vector<std::shared_ptr<Product>> productList;
    std::uint16_t id = 0;
    std::string name;
    float cost = 0;

    Product(const std::uint16_t id, std::string name, const float& cost) {
        this->id = id;
        this->name = name;
        this->cost = cost;
    }
};
#endif //FINAL_PROJECT_PRODUCT_H
