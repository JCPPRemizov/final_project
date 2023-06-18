//
// Created by jcpremizov on 16.06.23.
//

#ifndef FINAL_PROJECT_EMPLOYEETYPES_H
#define FINAL_PROJECT_EMPLOYEETYPES_H
    enum EmployeeType {
        ADMIN, //Системный администратор
        NOBODY
    };
    std::ostream& operator<<(std::ostream& os, EmployeeType employeeType) {
        switch (employeeType) {
            case EmployeeType::ADMIN:
                os << "Системный администратор";
                break;
            case EmployeeType::NOBODY:
                os << "Никто";
                break;
            default:
                os << "Неизвестный тип сотрудника";
        }
        return os;
    }


#endif //FINAL_PROJECT_EMPLOYEETYPES_H
