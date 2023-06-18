
#ifndef FINAL_PROJECT_EMPLOYEE_H
#define FINAL_PROJECT_EMPLOYEE_H


#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <fstream>
#include "EmployeeTypes.h"
#include "../libs/json.hpp"
using json = nlohmann::json;
class Employee {
private:
    void toJson(json& j) const {
        j["employeeType"] = employeeType;
        j["login"] = login;
        j["password"] = password;
        j["name"] = name;
        j["surname"] = surname;
        j["middle_name"] = middle_name;
    }
    static std::shared_ptr<Employee> fromJson(const json& j) {
        EmployeeType employeeType = j["employeeType"].get<EmployeeType>();
        std::string login = j["login"].get<std::string>();
        size_t password = j["password"].get<size_t>();
        std::string name = j["login"].get<std::string>();
        std::string surname = j["login"].get<std::string>();
        std::string middle_name = j["login"].get<std::string>();
        return std::make_shared<Employee>(employeeType ,name, surname, middle_name, login, password);
    }
public:
    static inline std::vector<std::shared_ptr<Employee>> staff;
    EmployeeType employeeType;
    std::string name, surname, middle_name, login;
    size_t password;
    Employee(EmployeeType employeeType ,std::string name, std::string surname, std::string middle_name, std::string login, size_t password){
        this->employeeType = employeeType;
        this->name = std::move(name);
        this->surname = std::move(surname);
        this->middle_name = std::move(middle_name);
        this->login = std::move(login);
        this->password = password;
    };
    static inline void addNewEmployee(Employee* employee){
        staff.push_back(std::shared_ptr<Employee>(employee));
    }


    static void saveStaffToJson() {
        json jStaff;
        std::string filename = "staff.json";
        for (const auto& employee : staff) {
            json j;
            employee->toJson(j);
            jStaff.push_back(j);
        }

        std::ofstream ofs(filename);
        if (ofs.is_open()) {
            ofs << jStaff.dump(4);
            ofs.close();
        } else {
            std::cerr << "Ошибка записи в файл." << std::endl;
        }
    }
    static void loadStaffFromJson() {
        std::string filename = "staff.json";
        std::ifstream ifs(filename);
        if (ifs.is_open()) {
            json jLoadedStaff;
            ifs >> jLoadedStaff;

            for (const auto& j : jLoadedStaff) {
                staff.push_back(Employee::fromJson(j));
            }

            ifs.close();
        } else {
            std::cerr << "Ошибка чтения файла." << std::endl;
        }
    }
};



#endif //FINAL_PROJECT_EMPLOYEE_H
