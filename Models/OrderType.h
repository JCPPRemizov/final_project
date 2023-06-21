//
// Created by jcpremizov on 21.06.23.
//

#ifndef FINAL_PROJECT_ORDERTYPE_H
#define FINAL_PROJECT_ORDERTYPE_H

#include <ostream>

enum OrderTypes {
    WAITING, IN_PROCESS, COMPLETED
};

inline std::ostream &operator<<(std::ostream &os, OrderTypes orderType) {
    switch (orderType) {
        case OrderTypes::WAITING:
            os << "Системный администратор";
            break;
        case OrderTypes::IN_PROCESS:
            os << "Складской менеджер";
            break;
        case OrderTypes::COMPLETED:
            os << "Поставщик";
            break;
        default:
            os << "Неизвестный тип сотрудника";
    }
    return os;
}

#endif //FINAL_PROJECT_ORDERTYPE_H
