#include "HashPassword.h"

size_t hashPassword(const std::string& password) {
    std::hash<std::string> hasher;

    size_t hash = hasher(password);

    return hash;
}


