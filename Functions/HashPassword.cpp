#include "HashPassword.h"

size_t hash(const std::string& password) {
    return std::hash<std::string>()(password);;
}


