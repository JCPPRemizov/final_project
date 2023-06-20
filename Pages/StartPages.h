//
// Created by jcpremizov on 20.06.23.
//

#ifndef FINAL_PROJECT_STARTPAGES_H
#define FINAL_PROJECT_STARTPAGES_H

#include "AdminPages.h"
#include "WarehousePages.h"

class StartPage{
private:
    static inline bool isAdminExist;
public:

    static void adminRegPage() {
    while (true) {
        system(consoleClear.c_str());
        std::string login, password, name, surname, middle_name;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Введите логин: " << std::endl;
        std::cin >> login;
        std::cout << "Введите пароль: " << std::endl;
        std::cin >> password;
        std::cout << "Введите Имя: " << std::endl;
        std::cin >> name;
        std::cout << "Введите Фамилию: " << std::endl;
        std::cin >> surname;
        std::cout << "Введите Отчество: " << std::endl;
        std::cin >> middle_name;
        EmployeeFunctions::registration(EmployeeType(ADMIN), name, surname, middle_name, login, password);
        std::cout << "Успешная регистрация!" << std::endl;
        isAdminExist = true;
        break;
    }
}
    static void authorizationPage() {
    while (true) {
        system(consoleClear.c_str());
        std::string login, password;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Введите логин: " << std::endl;
        std::cin.clear();
        std::cin >> login;
        std::cout << "Введите пароль: " << std::endl;
        std::cin >> password;
        std::shared_ptr<Employee> employee = EmployeeFunctions::authorization(login, password);
        if (employee == nullptr) {
            std::cout << "Неверный логин или пароль!" << std::endl;
            std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            getchar();
            break;
        }
        switch (employee->employeeType) {
            case ADMIN:
                AdminPages::adminPage();
                break;
            case WAREHOUSE_MANAGER:
                WarehousePages::warehousePage();
                break;
        }
        break;

    }
}
    static void startPage() {
    int action;
    EmployeeFunctions::loadEmployee();
    ProductFunctions::loadProduct();
    MenuFunctions::loadMenuItems();
    if (!Employee::staff.empty()) {
        for (const auto &item: Employee::staff) {
            if (item->employeeType == EmployeeType(ADMIN)) {
                isAdminExist = true;
            }
        }
    }
    while (true) {
        system(consoleClear.c_str());
        if (!isAdminExist) {
            std::cout << "Добро пожаловать!\n" << "Доступные действия:\n"
                      << "1.Авторизация\n2.Регистрация админа\n3.Войти как гость\nВыберите действие(Для выхода введите 0): "
                      << std::endl;
        } else {
            std::cout << "Добро пожаловать!\n" << "Доступные действия:\n"
                      << "1.Авторизация\n2.Войти как гость\nВыберите действие(Для выхода введите 0): " << std::endl;
        }
        std::cin >> action;
        if (std::cin.fail()) {
            std::cout << "Введите число!" << std::endl;
            std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            getchar();
            continue;
        }
        if (action == 0) {
            break;
        }
        if (!isAdminExist) {
            if (action < 1 or action > 3) {
                std::cout << "Введите число в диапазоне от 1 до 3!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            } else {
                switch (action) {
                    case 1:
                        authorizationPage();
                        break;
                    case 2:
                        adminRegPage();
                        break;
                }
            }
        } else {
            if (action < 1 or action > 2) {
                std::cout << "Введите число в диапазоне от 1 до 2!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            } else {
                switch (action) {
                    case 1:
                        authorizationPage();
                        break;
                    case 2:
                        std::cout << "Два" << std::endl;
                        break;
                }
            }
        }

    }
}

};
#endif //FINAL_PROJECT_STARTPAGES_H
