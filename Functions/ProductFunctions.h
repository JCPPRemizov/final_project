//
// Created by jcpremizov on 19.06.23.
//

#ifndef FINAL_PROJECT_PRODUCTFUNCTIONS_H
#define FINAL_PROJECT_PRODUCTFUNCTIONS_H

#include <cstdint>
#include <string>
#include "Product.h"

class ProductFunctions{
public:
static void addNewProduct(const std::string& name, const float& cost){
    std::uint16_t lastId = 1;
    if (!Product::productList.empty()) {
        lastId = Product::productList[Product::productList.size() - 1]->id + 1;
    }
    Product::productList.push_back(std::make_shared<Product>(lastId, name, cost));

    std::thread productListThread([](){Product::saveStaffToJson();});
    productListThread.join();
}

static void editProduct(const std::shared_ptr<Product>& product, const std::string& name, const float& cost){
    product->name = name;
    product->cost = cost;

    std::thread productListThread([](){Product::saveStaffToJson();});
    productListThread.join();
}

static void printProductList(){
    if (!Product::productList.empty()){
        for (const auto& item:Product::productList){
            std::cout << "ID: " << item->id << "\n" << "Название: " << item->name << "\n" << "Стоимость: " << item->cost << "\n" << "--------------------------" << std::endl;
        }
    }
}
};


#endif //FINAL_PROJECT_PRODUCTFUNCTIONS_H
