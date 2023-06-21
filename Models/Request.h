//
// Created by jcpremizov on 20.06.23.
//

#ifndef FINAL_PROJECT_REQUEST_H
#define FINAL_PROJECT_REQUEST_H

#include <vector>
#include <memory>
#include <map>
#include "Product.h"

class Request{

public:
    static inline std::vector<std::shared_ptr<Request>> requestsList;
    static inline std::vector<std::shared_ptr<Request>> approvedRequestsList;

    float totalCost = 0;
    std::uint16_t id;
    std::vector<std::map<int, std::map<int, std::shared_ptr<Product>>>> rProductsList;





};
#endif //FINAL_PROJECT_REQUEST_H
