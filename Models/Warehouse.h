//
// Created by jcpremizov on 20.06.23.
//

#ifndef FINAL_PROJECT_WAREHOUSE_H
#define FINAL_PROJECT_WAREHOUSE_H

#include <vector>
#include <memory>
#include <map>
#include "Product.h"
class Warehouse{
public:
    static inline std::vector<std::map<int, std::shared_ptr<Product>>> wProductsList;
};
#endif //FINAL_PROJECT_WAREHOUSE_H
