//
// Created by jcpremizov on 19.06.23.
//

#ifndef FINAL_PROJECT_PRODUCT_H
#define FINAL_PROJECT_PRODUCT_H

#include <cstdint>
#include <string>
#include <vector>
#include <bits/shared_ptr.h>

class Product {
private:
    void toJson(json &j) const {
        j["id"] = id;
        j["name"] = name;
        j["cost"] = cost;
    }

    static std::shared_ptr<Product> fromJson(const json &j) {
        std::uint16_t id = j["id"].get<std::uint16_t>();
        std::string name = j["name"].get<std::string>();
        float cost = j["cost"].get<size_t>();
        return std::make_shared<Product>(id, name, cost);
    }

public:
    static inline std::vector<std::shared_ptr<Product>> productList;
    std::uint16_t id = 0;
    std::string name;
    float cost = 0;

    Product(const std::uint16_t id, std::string name, const float &cost) {
        this->id = id;
        this->name = name;
        this->cost = cost;
    }

    static void saveProductsToJson() {
        if (!productList.empty()) {
            json jProduct;
            std::string filename = "products.json";
            for (const auto &product: productList) {
                json j;
                product->toJson(j);
                jProduct.push_back(j);
            }

            std::ofstream ofs(filename);
            if (ofs.is_open()) {
                ofs << jProduct.dump(4);
                ofs.close();
            } else {
                std::cerr << "Ошибка записи в файл." << std::endl;
            }
        } else {
            std::string filename = "products.json";
            std::ofstream ofs(filename);
        }
    }

    static void loadProductsFromJson() {
        std::string filename = "products.json";
        std::ifstream ifs(filename);
        if (ifs.is_open()) {
            json jLoadedProducts;
            ifs >> jLoadedProducts;
            for (const auto &j: jLoadedProducts) {
                productList.push_back(Product::fromJson(j));
            }
        } else {
            std::cerr << "Ошибка чтения файла." << std::endl;
        }
    }
};

#endif //FINAL_PROJECT_PRODUCT_H
