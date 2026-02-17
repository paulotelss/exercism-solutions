#include "leap.h"

namespace leap {

bool is_leap_year(int year) {
    // Uma abordagem comum seria usar múltiplos "ifs".
    // A abordagem "fora da curva" foca na clareza da expressão booleana pura:
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

}