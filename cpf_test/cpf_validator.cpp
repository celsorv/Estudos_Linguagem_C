#include <iostream>
#include <cstring>
#include "cpf_validator.h"

using namespace std;

bool CpfValidator::isValid(const char* number) {

    if (strlen(number) != 11) return false;

    for (char cycle = 0; cycle < 2; cycle++) {

        char limit_index = cycle == 0 ? 9 : 10;
        char base_weight = limit_index + 1;

        int temp = 0;

        for (char index = 0; index < limit_index; index++) {
            temp += valueOf(number[index]) * (base_weight - index);
        }

        temp %= 11;
        char digit = temp < 2 ? 0 : 11 - temp;

        if (digit != valueOf(number[limit_index]))
            return false;

    }

    return true;
}

char CpfValidator::valueOf(const char c) {
    
    // if c less than '0' or c greater than '9'
    if (c < 48 || c > 57) throw "it's not a number!";

    return c - '0';
}
