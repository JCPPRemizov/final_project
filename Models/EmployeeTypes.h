//
// Created by jcpremizov on 16.06.23.
//

#ifndef FINAL_PROJECT_EMPLOYEETYPES_H
#define FINAL_PROJECT_EMPLOYEETYPES_H
    enum EmployeeType {
        ADMIN, //Системный администратор
        WAREHOUSE_MANAGER, //Складской менеджер
        PROVIDER, //Поставщик
        ACCOUNTANT, //Бухгалтер
        COOK, //Повар
        WAITER //Официант
    };
    std::ostream& operator<<(std::ostream& os, EmployeeType employeeType) {
        switch (employeeType) {
            case EmployeeType::ADMIN:
                os << "Системный администратор";
                break;
            case EmployeeType::WAREHOUSE_MANAGER:
                os << "Складской менеджер";
                break;
            case EmployeeType::PROVIDER:
                os << "Поставщик";
                break;
            case EmployeeType::ACCOUNTANT:
                os << "Бухгалтер";
                break;
            case EmployeeType::COOK:
                os << "Повар";
                break;
            case EmployeeType::WAITER:
                os << "Официант";
                break;
            default:
                os << "Неизвестный тип сотрудника";
        }
        return os;
    }


#endif //FINAL_PROJECT_EMPLOYEETYPES_H
