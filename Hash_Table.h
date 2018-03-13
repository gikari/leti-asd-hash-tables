#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <list>
#include <vector>
#include <stdexcept>
#include <iostream>

class element_not_found : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Hash_Table {
public:
    Hash_Table();
    ~Hash_Table();
    int hash_function (int value);
    void add_value(int value);
    int get_value_from_hash(int hash);
    void remove_value(int value);
    int *& operator [] (int index);
    const int * operator [] (int index) const;
    int capacity() const {
        return cap;
    }

    static const int len = 100;
private:
    int try_get_value_from_hash(int hash);
    void try_add_value(int value);
    void try_remove_value(int value);

    std::vector <int*> hash_table_array;

    int cap;
};

#endif
