/*
 * (A or B xor C and D) and E
 * Sets as hash-tables
 */
#include <iostream>
#include "Set.h"

int main(int argc, char **argv) {
    Set set1 {"123"};
    Set set2 {"1234"};
    Set set3{};
    set3 = set1 + set2;
    set1.show();
    set2.show();
    set3.show();
    return 0;
}
