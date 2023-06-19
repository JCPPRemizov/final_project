//
// Created by jcpremizov on 18.06.23.
//

#ifndef FINAL_PROJECT_EMPLOYEEFUNCTIONS_H
#define FINAL_PROJECT_EMPLOYEEFUNCTIONS_H


#include <memory>
#include <iostream>
#include <thread>
#include "Employee.h"
#include "HashPassword.h"

class EmployeeFunctions {
public:
    static std::shared_ptr<Employee> authorization(const std::string& login, const std::string& password){

        size_t hashedPassword = hash(password);
        std::shared_ptr<Employee> employee;
        for (auto item:Employee::staff){
            if (item->login == login and item->password == hashedPassword){
                employee = item;
            }
        }
        return employee;
    }

    static void registration(EmployeeType employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
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
        saveEmployee();
        std::cout << "Новая учетная запись создана!" << std::endl;
    }

    static void editEmployee(const int& employeeId, const int& employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
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
        saveEmployee();

    }

    static void addNewEmployee(const int& employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
                               const std::string& login, const std::string& password){

        EmployeeType type;

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
        EmployeeFunctions::registration(type, name, surname, middle_name, login, password);
    }

    static void deleteEmployee(const std::string& login){
        Employee::staff.erase(std::remove_if( Employee::staff.begin(),  Employee::staff.end(),[login](const std::shared_ptr<Employee> &employee) {return employee->login == login;}),  Employee::staff.end());
        saveEmployee();

    }

    static void saveEmployee(){
        std::thread saveStaffThread([](){Employee::saveStaffToJson();});
        saveStaffThread.join();
    }

    static void loadEmployee(){
        std::thread loadStaffThread([](){Employee::loadStaffFromJson();});
        loadStaffThread.join();
    }

};


#endif //FINAL_PROJECT_EMPLOYEEFUNCTIONS_H
