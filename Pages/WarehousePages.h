//
// Created by jcpremizov on 20.06.23.
//

#ifndef FINAL_PROJECT_WAREHOUSEPAGES_H
#define FINAL_PROJECT_WAREHOUSEPAGES_H

#include <iostream>

class WarehousePages{
public:
    static void warehousePage() {
        std::cout << "Страница складского менеджера" << std::endl;
        std::cin.ignore();
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }
};


#endif //FINAL_PROJECT_WAREHOUSEPAGES_H
