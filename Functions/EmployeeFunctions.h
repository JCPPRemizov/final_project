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
    // Функция авторизации
    static inline std::shared_ptr<Employee> authorization(const std::string& login, const std::string& password){

        size_t hashedPassword = hash(password); // Хэширование пароля
        std::shared_ptr<Employee> employee;
        // Нахождение нужного пользователя
        for (auto item:Employee::staff){
            if (item->login == login and item->password == hashedPassword){
                employee = item;
            }
        }
        // Возрващаем пользователя
        return employee;
    }

    // Функция регистрации
    static inline void registration(EmployeeType employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
                      const std::string& login, const std::string& password){
        size_t hasedPassword = hash(password); // Хэшируем пароль
        auto* employee = new Employee(employeeType, name, surname, middle_name, login, hasedPassword); // Создаем нового сотрудника
        // Проверяем, что логин не занят
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
        // Добавляем нового сотрудника в список сотрудников
        Employee::addNewEmployee(employee);
        // Сохраняем список сотрудников в JSON
        saveEmployee();
        std::cout << "Новая учетная запись создана!" << std::endl;
    }

    // Функция редактирования сотрудника
    static inline void editEmployee(const int& employeeId, const int& employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
                                    const std::string& login, const std::string& password){
        EmployeeType type;
        //Изменение типа сотрудника
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
        //Изменение сотрудника
        employee->employeeType = type;
        employee->name = name;
        employee->surname = surname;
        employee->middle_name = middle_name;
        employee->login = login;
        employee->password = hash(password);
        saveEmployee();

    }

    //Функция добавления нового пользователя
    static inline void addNewEmployee(const int& employeeType, const std::string& name, const std::string& surname, const std::string& middle_name,
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

    static inline void deleteEmployee(const std::string& login){
        Employee::staff.erase(std::remove_if( Employee::staff.begin(),  Employee::staff.end(),
                                              [login](const std::shared_ptr<Employee> &employee) {return employee->login == login;}),  Employee::staff.end());
        saveEmployee();

    }

    static inline void saveEmployee(){
        std::thread saveStaffThread([](){Employee::saveStaffToJson();});
        saveStaffThread.join();
    }

    static inline void loadEmployee(){
        std::thread loadStaffThread([](){Employee::loadStaffFromJson();});
        loadStaffThread.join();
    }

};


#endif //FINAL_PROJECT_EMPLOYEEFUNCTIONS_H
