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
    static inline std::vector<Request> requestsList;

    std::uint16_t id;
    std::vector<std::map<int, std::shared_ptr<Product>>> rProductsList;
};
#endif //FINAL_PROJECT_REQUEST_H
