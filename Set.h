//
// Created by zomial on 04.03.18.
//

#ifndef LAB_3_SET_H
#define LAB_3_SET_H

#include "Hash_Table.h"
#include <string>
#include <stdexcept>

class not_represents_hex_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Set {
public:
    Set() = default;
    explicit Set ( const char* );
    explicit Set ( const std::string& );
    // Set ( const Set& );
    // Set ( Set&& );
    ~Set() = default;
    Set& operator = ( const Set& );
    // Set& operator = ( Set&& );
    // bool operator == ( const char* ) const;
    // bool operator == ( const Set& ) const;
    // Set operator / ( const Set& ) const;
    Set operator + ( const Set& ) const;
    Set operator | ( const Set& ) const;
    Set operator & ( const Set& ) const;

    void add ( char elem );
    void add ( int elem );
    void remove ( char elem );
    void remove(int elem);
    int char_to_int(char) const;
    char int_to_char(int) const;

    void show();
    std::string to_str() const;
private:
    static const int power = 16;

    Hash_Table container;
};


#endif //LAB_3_SET_H
