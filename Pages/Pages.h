#ifndef FINAL_PROJECT_PAGES_H
#define FINAL_PROJECT_PAGES_H

#include <vector>
#include "PagesFunctions.h"
    class Pages{
    public:
        static inline bool adminEx;
        static inline void adminPage(){
            while (true) {
                int action;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Страница админа" << std::endl;
                std::cout << "1.Редактировать учетные записи\n2.Регистрация новой учетной записи\nВыберите действие:" << std::endl;
                std::cin >> action;
                if (std::cin.fail()){
                    std::cout << "Неверный ввод!";
                    continue;
                }
                if (action == 1){
                    PagesFunctions::userRefactor();
                }
                else if (action == 2){
                    PagesFunctions::newUserRegistarion();
                }
                else if (action == 3){
                    break;
                }
            }
        }
        static inline void authorizationPage() {
            while (true) {
                std::string login, password;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Введите логин: " << std::endl;
                std::cin.clear();
                std::cin >> login;
                std::cout << "Введите пароль: " << std::endl;
                std::cin >> password;
                std::shared_ptr<Employee> employee = PagesFunctions::authorization(login, password);
                if (employee == nullptr){
                    std::cout << "Неверный логин или пароль!" << std::endl;
                    continue;
                }
                switch (employee->employeeType) {
                    case ADMIN:
                        adminPage();
                }

            }
        }
        static inline void adminRegPage(){
            while (true) {
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
                PagesFunctions::registration(EmployeeType(ADMIN), name, surname, middle_name, login, password);
                std::cout << "Успешная регистрация!" << std::endl;
                adminEx = true;
                break;
            }
        }
        static inline void startPage() {
            int action;
            Employee::loadStaffFromJson();
            if (Employee::staff.size() != 0){
                for (auto item:Employee::staff){
                    if (item->employeeType == EmployeeType(ADMIN)){
                        adminEx = true;
                    }
                }
            }
            while (true) {
                if (!adminEx){
                    std::cout << "Добро пожаловать!\n" << "Доступные действия:\n"
                              << "1.Авторизация\n2.Регистрация админа\n3.Войти как гость\nВыберите действие: " << std::endl;
                }
                else {
                    std::cout << "Добро пожаловать!\n" << "Доступные действия:\n"
                              << "1.Авторизация\n2.Войти как гость\nВыберите действие: " << std::endl;
                }
                std::string actionNum;
                std::cin >> action;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Неверный ввод!" << std::endl;
                    continue;
                } else {
                    if (!adminEx){
                        if (action < 1 or action > 3){
                            std::cout << "Введите число в диапазоне от 1 до 3!" << std::endl;
                            continue;
                        }
                        else{
                            switch (action) {
                                case 1:
                                    authorizationPage();
                                case 2:
                                    adminRegPage();
                            }
                        }
                    }
                    else{
                        if (action < 1 or action > 2){
                            std::cout << "Введите число в диапазоне от 1 до 2!" << std::endl;
                            continue;
                        }
                        else{
                            switch (action) {
                                case 1:
                                    authorizationPage();
                                case 2:
                                    std::cout << "Два" << std::endl;
                            }
                        }
                    }
                }
            }
        }
    };




#endif //FINAL_PROJECT_PAGES_H
