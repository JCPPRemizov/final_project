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

    static inline void registration(EmployeeType employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
                      const std::string& login, const std::string& password){
        size_t hasedPassword = hashPassword(password);
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
};


#endif //FINAL_PROJECT_PAGESFUNCTIONS_H
