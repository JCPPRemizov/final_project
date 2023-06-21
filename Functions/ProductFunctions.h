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
static inline void addNewProduct(const std::string& name, const float& cost){
    std::uint16_t lastId = 1;
    if (!Product::productList.empty()) {
        lastId = Product::productList[Product::productList.size() - 1]->id + 1;
    }
    Product::productList.push_back(std::make_shared<Product>(lastId, name, cost));

    saveProduct();
}

static inline void editProduct(const std::shared_ptr<Product>& product, const std::string& name, const float& cost){
    product->name = name;
    product->cost = cost;

    saveProduct();
}

static inline void printProductList(const std::vector<std::shared_ptr<Product>>& products){
    if (!products.empty()){
        for (const auto& item:products){
            std::cout << "ID: " << item->id << "\n" << "Название: " << item->name << "\n" << "Стоимость: " << item->cost << "\n" << "--------------------------" << std::endl;
        }
    }
}

static inline void deleteProduct(const int& productId){
    Product::productList.erase(std::remove_if(Product::productList.begin(), Product::productList.end(),[productId](const std::shared_ptr<Product> &product) {return product->id == productId;}), Product::productList.end());
    saveProduct();
}

static inline void saveProduct(){
    std::thread saveProducts([](){Product::saveProductsToJson();});
    saveProducts.join();
}

static inline void loadProduct(){
    std::thread loadProducts([](){Product::loadProductsFromJson();});
    loadProducts.join();
}

};



#endif //FINAL_PROJECT_PRODUCTFUNCTIONS_H
