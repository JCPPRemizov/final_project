//
// Created by jcpremizov on 21.06.23.
//

#ifndef FINAL_PROJECT_WAREHOUSEFUNCTIONS_H
#define FINAL_PROJECT_WAREHOUSEFUNCTIONS_H
#include "Warehouse.h"
class WarehouseFunctions {
public:

    static void printWarehouse() {
        for (const auto &wProductMap: Warehouse::wProductsList) {
            for (const auto &wProductInnerMap: wProductMap) {
                std::cout << "ID продукта: " << wProductInnerMap.first << std::endl;
                for (const auto &wProductEntry: wProductInnerMap.second) {
                    const auto &product = *wProductEntry.second;
                    std::cout << "Название продукта: " << product.name << std::endl;
                    std::cout << "Количество на складе: " << wProductEntry.first << std::endl;
                    std::cout << "Стоимость 1 ед: " << product.cost << std::endl;
                    std::cout << "-----------------------" << std::endl;
                }
            }
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Нажмите любую клавишу для продолжения";
        getchar();
    }
};

#endif //FINAL_PROJECT_WAREHOUSEFUNCTIONS_H
