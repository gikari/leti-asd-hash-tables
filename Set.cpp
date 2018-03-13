//
// Created by zomial on 04.03.18.
//

#include "Set.h"
#include <stdexcept>


Set::Set(const char * str) {
    container = {};
    for (int i = 0; str[i]; ++i) {
        container.add_value(char_to_int(str[i]));
    }
}

int Set::char_to_int(char ch) const {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F') {
        switch (ch) {
            case 'a':
            case 'A':
                return 0xA;
            case 'b':
            case 'B':
                return 0xB;
            case 'c':
            case 'C':
                return 0xC;
            case 'd':
            case 'D':
                return 0xD;
            case 'e':
            case 'E':
                return 0xE;
            case 'f':
            case 'F':
                return 0xF;
            default:
                throw std::runtime_error("Unknown error!");
        }
    } else {
        throw not_represents_hex_error("Char don't represents hex digit!");
    }
}

void Set::add(char elem) {
    if (container.capacity() < 16) {
        container.add_value(char_to_int(elem));
    } else {
        throw std::overflow_error("Too many elements in set!");
    }
}

void Set::remove(char elem) {
    container.remove_value(char_to_int(elem));
}

void Set::remove(int elem) {
    remove(int_to_char(elem));
}

std::string Set::to_str() const {
    std::string str_rep{};
    for (int i = 0; i < container.len; ++i) {
        if (container[i] != nullptr) {
            str_rep += int_to_char(*container[i]);
        }
    }
    return str_rep;
}

char Set::int_to_char(int integer) const {
    if (integer >= 0 && integer <= 9) {
        return static_cast<char>('0' + integer);
    } else if (integer >= 0xA && integer <= 0xF) {
        return static_cast<char>('A' + integer - 0xA);
    } else {
        throw not_represents_hex_error("Integer don't represents hex!");
    }
}

void Set::show() {
    std::cout << this->to_str() << std::endl;
}

Set::Set(const std::string & str) {
    container = {};
    for (auto ch : str) {
        container.add_value(char_to_int(ch));
    }
}

Set& Set::operator=(const Set & another) {
    for (int i = 0; i < another.container.len; ++i) {
        if (another.container[i] != nullptr) {
            this->add(*(another.container[i]));
        }
    }
    return *this;
}

Set Set::operator&(const Set & another) const {
    Set new_set{};
    for (int i = 0; i < container.len; ++i) {
        if (container[i]) {
            auto element_for_search = *(container[i]);
            for (int j = 0; j < another.container.len; ++j) {
                if (another.container[j] && *(another.container[j]) == element_for_search) {
                    new_set.add(element_for_search);
                    break;
                }
            }
        }
    }
    return new_set;
}

void Set::add(int elem) {
    add(int_to_char(elem));
}

Set Set::operator | (const Set & another) const {
    Set new_set{};
    for (int i = 0; i < container.len; ++i) {
        if (container[i]) {
            auto element_for_search = *(container[i]);
            bool is_found = false;
            for (int j = 0; j < another.container.len; ++j) {
                if (another.container[j] && *(another.container[j]) == element_for_search) {
                    is_found = true;
                    break;
                }
            }
            if (!is_found) {
                new_set.add(element_for_search);
            }
        }
    }
    for (int i = 0; i < another.container.len; ++i) {
        if (another.container[i]) {
            new_set.add(*(another.container[i]));
        }
    }
    return new_set;
}

Set Set::operator+(const Set & another) const {
    Set new_set = (*this) | another;

    for (int i = 0; i < container.len; ++i) {
        if (container[i]) {
            auto element_for_search = *(container[i]);
            for (int j = 0; j < another.container.len; ++j) {
                if (another.container[j] && *(another.container[j]) == element_for_search) {
                    new_set.remove(element_for_search);
                    break;
                }
            }
        }
    }

    return new_set;
}


