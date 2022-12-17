#ifndef TYPE_HPP
#define TYPE_HPP

#include "tree.hpp"

enum Category{
    PRIMITIVE, ARRAY, STRUCTURE, FUNCTION
};

class Array;

class ParamsList;

class GlobalType{
public:
    NodeType nodetype;
    Array* array_ptr = nullptr;
    ParamsList* params_ptr = nullptr;   
    Category category;

    GlobalType(Category category, NodeType nodetype);
    GlobalType(Category category, Array* array_ptr);
    GlobalType(Category category, ParamsList* params_ptr);

};

GlobalType* getGlobalTypePrimitive(Node* node);
GlobalType* getGlobalTypeInt();
GlobalType* getGlobalTypeChar();
GlobalType* getGlobalTypeFloat();

class Array {
public:
    GlobalType *base;
    int size;
    Array(GlobalType *base, int size);
};

class ParamsList{
public:
    string name;
    GlobalType *global_type = nullptr;
    ParamsList* next = nullptr;
    ParamsList(string name, GlobalType* global_type, ParamsList* next);
};
#endif