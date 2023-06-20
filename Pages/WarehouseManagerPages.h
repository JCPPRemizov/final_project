#ifndef FINAL_PROJECT_WAREHOUSEMANAGERPAGES_H
#define FINAL_PROJECT_WAREHOUSEMANAGERPAGES_H

#include <iostream>

class WarehouseManagerPages{
public:
    static inline void warehousePage() {
        while (true){
            system(consoleClear.c_str());
            int action;
            std::cout << "Страница складского менеджера" << std::endl;
            std::cout << "1.Добавить новый запрос" << "Выберите действие(Введите 0 для выхода): " << std::endl;
            std::cin >> action;

            if (std::cin.fail()){
                std::cout << "Ошибка! Неверный ввод!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }
            if (action > 1 or action < 0){
                std::cout << "Ошибка! Введите число в диапазоне от 1 до 1!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }
            if (action == 0){
                break;
            }

            std::
        }
    }

    static inline void addNewRequestPage(){

    }
};


#endif //FINAL_PROJECT_WAREHOUSEMANAGERPAGES_H
