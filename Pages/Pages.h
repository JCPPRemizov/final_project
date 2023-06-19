#ifndef FINAL_PROJECT_PAGES_H
#define FINAL_PROJECT_PAGES_H
#define LINUX

#include <vector>
#include "EmployeeFunctions.h"
#include "ProductFunctions.h"
#include "MenuFunctions.h"

#ifdef LINUX
static std::string consoleClear = "clear";
#endif

#ifdef WINDOWS
static std::string consoleClear = "cls";
#endif

class Pages {
private:
    static inline bool isAdminExist;
public:
    static void adminPage() {
        while (true) {
            system(consoleClear.c_str());
            int action;
            std::cout << "Страница админа" << std::endl;
            std::cout
                    << "1.Редактировать учетные записи\n2.Регистрация новой учетной записи\n3.Удаление пользователя\n4.Список продуктов\n5.Добавление продукта"
                       "\n6.Редактирование продуктов\n7.Удаление продуктов\n8.Добавление товара в меню\n9.Редактирование товара в меню\n10.Просмотр пунктов меню\nВыберите действие(Введите 0 для выхода):"
                    << std::endl;
            std::cin >> action;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!";
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (action == 0) {
                break;
            } else if (action == 1) {
                userRefactorPage();
            } else if (action == 2) {
                newUserRegistrationPage();
            } else if (action == 3) {
                userDeletePage();
            } else if (action == 4) {
                productListPage();
            } else if (action == 5) {
                productAddPage();
            } else if (action == 6) {
                productEditPage();
            } else if (action == 7) {
                productDeletePage();
            } else if (action == 8) {
                menuAddPage();
            } else if (action == 9){
                menuEditPage();
            } else if (action == 10) {
                menuPrintPage();
            } else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Такого действия нету!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
        }
    }

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

    static void newUserRegistrationPage() {
        std::string login, password, name, surname, middle_name;
        while (true) {
            system(consoleClear.c_str());
            int action = 0;
            std::cout << "Выберите тип учетной записи :" << std::endl;
            std::cout
                    << "1.Системный администратор\n2.Складской менеджер\n3.Поставщик\n4.Бухгалтер\n5.Повар\n6.Официант\nТип учетной записи(Введите 0 для выхода): "
                    << std::endl;
            std::cin >> action;

            if (std::cin.fail()) {
                std::cout << "Ошибка ввода!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }

            if (action < 0 or action > 6) {
                std::cout << "Число вне диапазона выбора" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }

            if (action == 0) {
                break;
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

            EmployeeFunctions::addNewEmployee(action, name, surname, middle_name, login, password);
        }

    }

    static void userRefactorPage() {
        while (true) {

            system(consoleClear.c_str());

            std::string name, surname, middle_name, login, password;
            int userNum = 0;
            int action = 0;
            int i = 0;

            std::cout << "Выберите пользователя для редактирования (Введите 0 для выхода): " << std::endl;

            for (const auto &item: Employee::staff) {
                i++;
                std::cout << i << ". " << "Имя: " << item->name << "\n" << "Фамилия: " << item->surname << "\n"
                          << "Логин: " << item->login << "\n"
                          << "Должность: " << item->employeeType << "\nПользователь: " << std::endl;
            }

            std::cin >> userNum;

            if (std::cin.fail()) {
                std::cout << "Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }

            if (userNum > Employee::staff.size() or userNum < 0) {
                std::cout << "Такого пользователя нету" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }

            if (userNum == 0) {
                break;
            }

            std::cout << "Выберите тип учетной записи :" << std::endl;
            std::cout
                    << "1.Системный администратор\n2.Складской менеджер\n3.Поставщик\n4.Бухгалтер\n5.Повар\n6.Официант\nТип учетной записи(Введите 0 для выхода): "
                    << std::endl;

            std::cin >> action;

            if (std::cin.fail()) {
                std::cout << "Введите число!" << std::endl;
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

            EmployeeFunctions::editEmployee(userNum, action, name, surname, middle_name, login, password);
        }
    }

    static void userDeletePage() {
        while (true) {

            system(consoleClear.c_str());

            std::string name, surname, middle_name, login, password;
            int userNum = 0;
            int i = 0;

            std::cout << "Выберите пользователя для редактирования (Введите 0 для выхода): " << std::endl;

            for (const auto &item: Employee::staff) {
                i++;
                std::cout << i << ". " << "Имя: " << item->name << "\n" << "Фамилия: " << item->surname << "\n"
                          << "Логин: " << item->login << "\n"
                          << "Должность: " << item->employeeType << "\nПользователь: " << std::endl;
            }

            std::cin >> userNum;

            if (std::cin.fail()) {
                std::cout << "Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }

            if (userNum > Employee::staff.size() or userNum < 0) {
                std::cout << "Такого пользователя нету" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                continue;
            }

            if (userNum == 0) {
                break;
            }
            EmployeeFunctions::deleteEmployee(Employee::staff[userNum - 1]->login);
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
                    adminPage();
                    break;
                case WAREHOUSE_MANAGER:
                    warehousePage();
                    break;
            }
            break;

        }
    }

    static void startPage() {
        int action;
        EmployeeFunctions::loadEmployee();
        ProductFunctions::loadProduct();
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

    static void warehousePage() {
        std::cout << "Страница складского менеджера" << std::endl;
        std::cin.ignore();
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }

    static void productAddPage() {
        while (true) {
            system(consoleClear.c_str());
            std::string name;
            float cost;
            std::cout << "Введите имя продукта: " << std::endl;
            std::cin >> name;
            std::cout << "Введите стоимость продукта: " << std::endl;
            std::cin >> cost;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            ProductFunctions::addNewProduct(name, cost);
            break;
        }
    }

    static void productDeletePage() {
        while (true) {
            system(consoleClear.c_str());
            std::shared_ptr<Product> product;
            int productId;
            ProductFunctions::printProductList(Product::productList);
            std::cout << "Введите ID товара для удаления(Введите 0 для выхода): " << std::endl;
            std::cin >> productId;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (productId == 0) {
                break;
            }
            for (const auto &item: Product::productList) {
                if (productId == item->id) {
                    product = item;
                }
            }
            if (product == nullptr) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Такого товара нету!" << std::endl;
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            ProductFunctions::deleteProduct(productId);

        }
    }

    static void productEditPage() {
        while (true) {
            system(consoleClear.c_str());
            std::shared_ptr<Product> product;
            int productId;
            std::string name;
            float cost;
            ProductFunctions::printProductList(Product::productList);
            std::cout << "Введите ID товара для редактирования(Введите 0 для выхода): " << std::endl;
            std::cin >> productId;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (productId == 0) {
                break;
            }
            for (const auto &item: Product::productList) {
                if (productId == item->id) {
                    product = item;
                }
            }
            if (product == nullptr) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Такого товара нету!" << std::endl;
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }

            std::cout << "Введите новое имя товара:" << std::endl;
            std::cin >> name;
            std::cout << "Введите новую стоимость товара" << std::endl;
            std::cin >> cost;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            ProductFunctions::editProduct(product, name, cost);

        }
    }

    static void productListPage() {
        while (true) {
            system(consoleClear.c_str());
            ProductFunctions::printProductList(Product::productList);
            std::cout << "Нажмите любую клвишу для выхода" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            getchar();
            break;
        }
    }

    static void menuAddPage() {
        while (true) {
            system(consoleClear.c_str());
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::vector<std::shared_ptr<Product>> productToMenu;
            system(consoleClear.c_str());
            int hour, min, sec;
            std::string name, description, str_input;
            float gramming, cost;
            std::cout << "Введите название пункта меню: " << std::endl;
            std::cin >> name;
            std::cout << "Введите описание пункта меню: " << std::endl;
            std::cin >> description;
            std::cout << "Введите стоимость пукнта меню: " << std::endl;
            std::cin >> cost;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите граммовку пункта меню: " << std::endl;
            std::cin >> gramming;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите часы приготовления: " << std::endl;
            std::cin >> hour;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (hour > 23) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Выход за пределы значения!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите минуты приготовления: " << std::endl;
            std::cin >> min;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (min > 59) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Выход за пределы значения!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите секунды приготовления: " << std::endl;
            std::cin >> sec;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (sec > 59) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Выход за пределы значения!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::vector<std::shared_ptr<Product>> products;
            products = Product::productList;
            while (true) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                int productId;
                if (products.empty()) {
                    std::cout << "Больше продуктов нет!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    break;
                }
                std::cout << "Выберите продукты из списка: " << std::endl;
                ProductFunctions::printProductList(products);
                std::cout << "Выбор(Введите 0 для выхода): ";
                std::cin >> productId;
                if (std::cin.fail()) {
                    std::cout << "Ошибка! Введите число!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    continue;
                }
                if (productId == 0) {
                    break;
                }
                try {
                    auto iterator = std::find_if(products.begin(), products.end(),
                                                 [productId](const std::shared_ptr<Product> &product) {
                                                     return product->id == productId;
                                                 });
                    productToMenu.push_back(*iterator);

                    products.erase(std::remove_if(products.begin(), products.end(),
                                                  [productId](const std::shared_ptr<Product> &product) {
                                                      return product->id == productId;
                                                  }), products.end());
                }
                catch (std::exception ex) {
                    std::cout << "Такого продукта нету в списке!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    continue;
                }

            }
            if (!productToMenu.empty()) {

                MenuFunctions::addNewMenu(name, description, gramming, cost, hour, min, sec, productToMenu);
            }
            break;
        }
    }

    static void menuEditPage() {
        while (true) {
            system(consoleClear.c_str());
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::vector<std::shared_ptr<Product>> productToMenu;
            system(consoleClear.c_str());
            int hour, min, sec, userCh;
            std::string name, description, str_input;
            float gramming, cost;
            system(consoleClear.c_str());
            for (const auto &item: Menu::menuProductList) {
                std::cout << item;
            }
            std::cout << "Введите id пункта заказа для изменения(Введите 0 для выхода): " << std::endl;
            std::cin >> userCh;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (userCh == 0){
                break;
            }
            if (userCh > Menu::menuProductList.size() or userCh < 0){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Число вне диапазона выбора!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                break;
            }
            std::cout << "Введите название пункта меню: " << std::endl;
            std::cin >> name;
            std::cout << "Введите описание пункта меню: " << std::endl;
            std::cin >> description;
            std::cout << "Введите стоимость пукнта меню: " << std::endl;
            std::cin >> cost;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите граммовку пункта меню: " << std::endl;
            std::cin >> gramming;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите часы приготовления: " << std::endl;
            std::cin >> hour;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (hour > 23) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Выход за пределы значения!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите минуты приготовления: " << std::endl;
            std::cin >> min;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (min > 59) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Выход за пределы значения!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::cout << "Введите секунды приготовления: " << std::endl;
            std::cin >> sec;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Введите число!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            if (sec > 59) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка! Выход за пределы значения!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                getchar();
                continue;
            }
            std::vector<std::shared_ptr<Product>> products;
            products = Product::productList;
            while (true) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                int productId;
                if (products.empty()) {
                    std::cout << "Больше продуктов нет!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    break;
                }
                std::cout << "Выберите продукты из списка: " << std::endl;
                ProductFunctions::printProductList(products);
                std::cout << "Выбор(Введите 0 для выхода): ";
                std::cin >> productId;
                if (std::cin.fail()) {
                    std::cout << "Ошибка! Введите число!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    continue;
                }
                if (productId == 0) {
                    break;
                }
                try {
                    auto iterator = std::find_if(products.begin(), products.end(),
                                                 [productId](const std::shared_ptr<Product> &product) {
                                                     return product->id == productId;
                                                 });
                    productToMenu.push_back(*iterator);

                    products.erase(std::remove_if(products.begin(), products.end(),
                                                  [productId](const std::shared_ptr<Product> &product) {
                                                      return product->id == productId;
                                                  }), products.end());
                }
                catch (std::exception ex) {
                    std::cout << "Такого продукта нету в списке!" << std::endl;
                    std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                    getchar();
                    continue;
                }

            }
            if (!productToMenu.empty()) {
                MenuFunctions::editMenu(userCh ,name, description, gramming, cost, hour, min, sec, productToMenu);
            }
            break;
        }
    }

    static void menuPrintPage() {
        while (true) {
            system(consoleClear.c_str());
            for (const auto &item: Menu::menuProductList) {

                std::cout << item;
            }
            std::cout << "Нажмите любую клвишу для выхода" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            getchar();
            break;
        }
    }

};


#endif //FINAL_PROJECT_PAGES_H
