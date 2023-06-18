//
// Created by jcpremizov on 18.06.23.
//

#ifndef FINAL_PROJECT_PAGESFUNCTIONS_H
#define FINAL_PROJECT_PAGESFUNCTIONS_H


#include <memory>
#include <iostream>
#include "Employee.h"
#include "HashPassword.h"

class PagesFunctions {
public:
    static inline std::shared_ptr<Employee> authorization(const std::string& login, const std::string& password){

        size_t hashedPassword = hashPassword(password);
        std::shared_ptr<Employee> employee;
        for (auto item:Employee::staff){
            if (item->login == login and item->password == hashedPassword){
                employee = item;
            }
        }
        return employee;
    }
    static inline void newUserRegistarion(){
        std::string login, password, name, surname, middle_name;
        EmployeeType type;
        while (true) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Выберите тип учетной записи :" << std::endl;
            std::cout << "1.Системный администратор\n2.Другие\nТип учетной записи: " << std::endl;
            int action = 0;
            std::cin >> action;
            if (std::cin.fail()){
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
                    type = EmployeeType(ADMIN);
            }
            registration(type, name, surname, middle_name, login, password);
            std::cout << "Новая учетная запись создана!" << std::endl;
            break;
        }

    }
    static inline void userRefactor(){
        while (true) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Выберите пользователя для редактирования (Введите 0 для выхода): " << std::endl;
            int i = 0;
            for (auto item: Employee::staff) {
                i++;
                std::cout << i << ". " << "Имя: " << item->name << "\n" << "Фамилия: " << item->surname << "\n" << "Логин: " << item->login << "\n"
                << "Должность: " << item->employeeType << "\nПользователь: " << std::endl;
            }
            int userNum = 0;
            std::cin >> userNum;
            if (std::cin.fail()){
                std::cout << "Неверный ввод!" << std::endl;
                continue;
            }
            if (userNum == 0){
                break;
            }
            if (userNum > Employee::staff.size() or userNum < 0){
                std::cout << "Такого пользователя нету" << std::endl;
                continue;
            }
            std::shared_ptr<Employee> &employee = Employee::staff[userNum - 1];
            std::cout << "Введите логин: " << std::endl;
            std::cin >> employee->login;
            std::cout << "Введите пароль: " << std::endl;
            std::string password;
            std::cin >> password;
            std::cout << "Введите Имя: " << std::endl;
            std::cin >> employee->name;
            std::cout << "Введите Фамилию: " << std::endl;
            std::cin >> employee->surname;
            std::cout << "Введите Отчество: " << std::endl;
            std::cin >> employee->middle_name;

            employee->password = hashPassword(password);

        }
    }
    static inline void registration(EmployeeType employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
                      const std::string& login, const std::string& password){
        size_t hasedPassword = hashPassword(password);
        auto* employee = new Employee(employeeType, name, surname, middle_name, login, hasedPassword);
        for (auto item:Employee::staff){
            if (item->login == employee->login){
                std::cout << "Такой логин уже есть!" << std::endl;
                return;
            }
        }
        Employee::addNewEmployee(employee);
        Employee::saveStaffToJson();
    }
};


#endif //FINAL_PROJECT_PAGESFUNCTIONS_H
