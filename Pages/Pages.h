#ifndef FINAL_PROJECT_PAGES_H
#define FINAL_PROJECT_PAGES_H

#include <vector>
#include "PagesFunctions.h"
    class Pages{
    public:
        static inline bool adminEx;
        static inline void adminPage(){
            while (true) {
                system("clear");
                int action;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Страница админа" << std::endl;
                std::cout << "1.Редактировать учетные записи\n2.Регистрация новой учетной записи\n3.Выход\nВыберите действие:" << std::endl;
                std::cin >> action;
                if (std::cin.fail()){
                    std::cout << "Неверный ввод!";
                    continue;
                }
                if (action == 1){
                    userRefactorPage();
                }
                else if (action == 2){
                    newUserRegistrationPage();
                }
                else if (action == 3){
                    break;
                }
            }
        }
        static inline void authorizationPage() {
            while (true) {
                system("clear");
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
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    getchar();
                    break;
                }
                switch (employee->employeeType) {
                    case ADMIN:
                        adminPage();
                }
                break;

            }
        }
        static inline void adminRegPage(){
            while (true) {
                system("clear");
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
                system("clear");
                if (!adminEx){
                    std::cout << "Добро пожаловать!\n" << "Доступные действия:\n"
                              << "1.Авторизация\n2.Регистрация админа\n3.Войти как гость\nВыберите действие: " << std::endl;
                }
                else {
                    std::cout << "Добро пожаловать!\n" << "Доступные действия:\n"
                              << "1.Авторизация\n2.Войти как гость\nВыберите действие: " << std::endl;
                }
                std::cin >> action;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Неверный ввод!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    getchar();
                    continue;
                } else {
                    if (!adminEx){
                        if (action < 1 or action > 3){
                            std::cout << "Введите число в диапазоне от 1 до 3!" << std::endl;
                            std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            getchar();
                            continue;
                        }
                        else{
                            switch (action) {
                                case 1:
                                    authorizationPage();
                                    break;
                                case 2:
                                    adminRegPage();
                                    break;
                            }
                        }
                    }
                    else{
                        if (action < 1 or action > 2){
                            std::cout << "Введите число в диапазоне от 1 до 2!" << std::endl;
                            std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            getchar();
                            continue;
                        }
                        else{
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
        }
        static inline void newUserRegistrationPage(){
            std::string login, password, name, surname, middle_name;
            EmployeeType type;
            while (true) {
                system("clear");
                std::cout << "Выберите тип учетной записи :" << std::endl;
                std::cout << "1.Системный администратор\n2.Складской менеджер\n3.Поставщик\n4.Бухгалтер\n5.Повар\n6.Официант\nТип учетной записи(Введите 0 для выхода): " << std::endl;
                int action = 0;
                std::cin >> action;
                if (std::cin.fail()){
                    std::cout << "Ошибка ввода!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    getchar();
                    continue;
                }
                if (action == 0){
                    break;
                }
                if (action < 1 or action > 6){
                    std::cout << "Число вне диапазона выбора" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    getchar();
                    continue;
                }
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
                switch (action) {
                    case 1:
                        type = EmployeeType::ADMIN;
                        break;
                    case 2:
                        type = EmployeeType::WAREHOUSE_MANAGER;
                        break;
                    case 3:
                        type = EmployeeType::PROVIDER;
                        break;
                    case 4:
                        type = EmployeeType::ACCOUNTANT;
                        break;
                    case 5:
                        type = EmployeeType::COOK;
                        break;
                    case 6:
                        type = EmployeeType::WAITER;
                }
                PagesFunctions::registration(type, name, surname, middle_name, login, password);
            }

        }
        static inline void userRefactorPage(){
            while (true) {
                std::string name, surname, middle_name, login, password;
                int userNum = 0;
                int action = 0;
                int i = 0;

                system("clear");

                std::cout << "Выберите пользователя для редактирования (Введите 0 для выхода): " << std::endl;

                for (auto item: Employee::staff) {
                    i++;
                    std::cout << i << ". " << "Имя: " << item->name << "\n" << "Фамилия: " << item->surname << "\n" << "Логин: " << item->login << "\n"
                              << "Должность: " << item->employeeType << "\nПользователь: " << std::endl;
                }

                std::cin >> userNum;

                if (std::cin.fail()){
                    std::cout << "Неверный ввод!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    getchar();
                    continue;
                }

                if (userNum == 0){
                    break;
                }

                if (userNum > Employee::staff.size() or userNum < 0){
                    std::cout << "Такого пользователя нету" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    getchar();
                    continue;
                }

                std::cout << "Выберите тип учетной записи :" << std::endl;
                std::cout << "1.Системный администратор\n2.Складской менеджер\n3.Поставщик\n4.Бухгалтер\n5.Повар\n6.Официант\nТип учетной записи(Введите 0 для выхода): " << std::endl;
                std::cin >> action;

                if (std::cin.fail()){
                    std::cout << "Неверный ввод!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    getchar();
                    continue;
                }

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

                PagesFunctions::editEmployee(userNum, action, name, surname, middle_name, login, password);
            }
        }
    };




#endif //FINAL_PROJECT_PAGES_H
