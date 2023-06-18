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

        size_t hashedPassword = hash(password);
        std::shared_ptr<Employee> employee;
        for (auto item:Employee::staff){
            if (item->login == login and item->password == hashedPassword){
                employee = item;
            }
        }
        return employee;
    }

    static inline void registration(EmployeeType employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
                      const std::string& login, const std::string& password){
        size_t hasedPassword = hash(password);
        auto* employee = new Employee(employeeType, name, surname, middle_name, login, hasedPassword);
        for (auto item:Employee::staff){
            if (item->login == employee->login){
                std::cout << "Такой логин уже есть!" << std::endl;
                std::cout << "Нажмите любую клавишу для продолежения" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                getchar();
                return;
            }
        }
        Employee::addNewEmployee(employee);
        Employee::saveStaffToJson();
        std::cout << "Новая учетная запись создана!" << std::endl;
    }

    static inline void editEmployee(const int& employeeId, const int& employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
                                    const std::string& login, const std::string& password){
        EmployeeType type;
        std::shared_ptr<Employee> &employee = Employee::staff[employeeId - 1];
        switch (employeeType) {
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
        employee->employeeType = type;
        employee->name = name;
        employee->surname = surname;
        employee->middle_name = middle_name;
        employee->login = login;
        employee->password = hash(password);

    }
};


#endif //FINAL_PROJECT_PAGESFUNCTIONS_H
