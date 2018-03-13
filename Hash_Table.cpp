#include "Hash_Table.h"

Hash_Table::Hash_Table() {
    hash_table_array = std::vector<int*>(len);
    cap = 0;
}

int Hash_Table::hash_function(int value) {
    return (97 * value + 11) % len;
}

void Hash_Table::add_value(int value) {
    try {
        try_add_value(value);
    } catch (std::out_of_range&) {
        std::cerr << "Hash table error: Requested hash out of range!\n";
        throw;
    }
}

void Hash_Table::try_add_value(int value) {
    int hash = hash_function(value);
    hash_table_array[hash] = new int(value);
    cap++;
}

int Hash_Table::get_value_from_hash(int hash) {
    try {
        return try_get_value_from_hash(hash);
    }
    catch (std::out_of_range&){
        std::cerr << "Hash table error: Requested hash out of range!\n";
        throw;
    }
    catch (element_not_found&) {
        std::cerr << "Hash table error: element not found!\n";
        throw;
    }
}

int Hash_Table::try_get_value_from_hash(int hash) {
    int* value_ptr = hash_table_array[hash];
    if (value_ptr == nullptr) {
        throw element_not_found("No element with such hash!");
    } else {
        return *value_ptr;
    }
}

Hash_Table::~Hash_Table() {
    for (auto element : hash_table_array) {
        delete element;
    }
}

void Hash_Table::remove_value(int value) {
    try {
        try_remove_value(value);
    } catch (element_not_found&) {
        std::cerr << "Hash table error: element not found!\n";
        throw;
    }
}

void Hash_Table::try_remove_value(int value) {
    auto element_for_del = hash_table_array[hash_function(value)];
    if (element_for_del == nullptr) {
        throw element_not_found("No such element in hash-table!");
    } else {
        delete element_for_del;
        hash_table_array[hash_function(value)] = nullptr;
        cap--;
    }
}

int *& Hash_Table::operator [] (int index) {
    return hash_table_array[index];
}

const int *Hash_Table::operator[](int index) const {
    return hash_table_array[index];
}

