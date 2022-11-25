#include "type.hpp"

GlobalType::GlobalType(Category category, NodeType nodetype){
    this->category = category;
    this->nodetype = nodetype;
}

GlobalType::GlobalType(Category category, Array* array_ptr){
    this->array_ptr = array_ptr;
    this->category = category;
}

GlobalType::GlobalType(Category category, ParamsList* params_ptr){
    this->category = category;
    this->params_ptr = params_ptr;
}

ParamsList::ParamsList(string name, GlobalType* global_type, ParamsList* next){
    this->name = string(name);
    this->global_type = global_type;
    this->next = next;
}

GlobalType* getGlobalTypePrimitive(Node* node){
    switch (node->nodetype)
    {
    case NodeType::Int:
        return getGlobalTypeInt();
    case NodeType::Char:
        return getGlobalTypeChar();
    case NodeType::Float:
        return getGlobalTypeFloat();
    default:
        printf("not a primitive type\n");
        return nullptr;
    }
}

GlobalType* getGlobalTypeInt(){
    return new GlobalType(Category::PRIMITIVE, NodeType::Int);
}

GlobalType* getGlobalTypeChar(){
    return new GlobalType(Category::PRIMITIVE, NodeType::Char);
}

GlobalType* getGlobalTypeFloat(){
    return new GlobalType(Category::PRIMITIVE, NodeType::Float);
}

Array::Array(GlobalType *base, int size) : base(base), size(size) {}