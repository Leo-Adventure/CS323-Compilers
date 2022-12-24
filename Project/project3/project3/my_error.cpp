#include "my_error.hpp"

using namespace std;

void my_error(MY_ERROR_TYPE type, int line_num){
    my_error(type, line_num, nullptr);
}

void my_error(MY_ERROR_TYPE type, int line_num, const char* name) {
    switch (type) {
        case MISS_SEMI: {
            printf("Error type B at Line %d: Missing semicolon \';\'\n", line_num);
            break;
        }
        case MISS_RC: {
            printf("Error type B at Line %d: Missing closing curly braces  \'}\'\n", line_num);
            break;
        }
        case MISS_RP: {
            printf("Error type B at Line %d: Missing closing parenthesis \')\'\n", line_num);
            break;
        }
        case MISS_SPEC: {
            printf("Error type B at Line %d: Missing specifier\n", line_num);
            break;
        }
        case MISS_RB: {
            printf("Error type B at Line %d: Missing closing bracket \']\'\n", line_num);
            break;
        }
        case UNDEFINED_VARIABLE:{
            printf("Error type 1 at Line %d: undefined variable: %s\n", line_num, name);
            break;
        }
        case UNDEFINED_FUNC:{
            printf("Error type 2 at line %d: undefined function: %s\n", line_num, name);
            break;
        }
        case REDEFINED_VARIABLE:{
            printf("Error type 3 at line %d: redefine variable: %s\n", line_num, name);
            break;
        }
        case REDEFINED_FUNC:{
            printf("Error type 4 at line %d: redefine function: %s\n", line_num, name);
            break;
        }
        case ASSIGN_UNMATCH:{
            printf("Error type 5 at line %d: unmatching type on both sides of assignment\n", line_num);
            break;
        }
        case RVALUE_ERROR:{
            printf("Error type 6 at line %d: left side in assignment is rvalue\n", line_num);
            break;
        }
        case UNMATCH_OPERAND:{
            printf("Error type 7 at line %d: binary operation on non-number variables\n", line_num);
            break;
        }
        case RETURN_VALUE_MISMATCH:{
            printf("Error type 8 at line %d: incompatiable return type\n", line_num);
            break;
        }
        case ARGS_MISMATCH:{
            printf("Error type 9 at line %d: invalid argument number for compare, %s\n", line_num, name);
            break;
        }
        case INDEX_OPERATOR_ERROR:{
            printf("Error type 10 at line %d: indexing on non-array variable\n", line_num);
            break;
        }
        case FUNC_INVOKE_ERROR:{
            printf("Error type 11 at line %d: invoking non-function variable: %s\n", line_num, name);
            break;
        }
        case INDEX_TYPE_ERROR:{
            printf("Error type 12 at line %d: indexing by non-integer\n", line_num);
            break;
        }
        case DOT_ERROR:{
            printf("Error type 13 at line %d: accessing with non-struct variable\n", line_num);
            break;
        }
        case UNDEFINED_STRUCT_MEMBER:{
            printf("Error type 14 at line %d: no such member: %s\n", line_num, name);
            break;
        }
        case REDEFINED_STRUCT:{
            printf("Error type 15 at line %d: redefine struct: %s\n", line_num, name);
            break;
        }
        case STRUCT_MISMATCH:{
            printf("Error type 16 at line %d: it's not a struct: %s\n", line_num, name);
            break;            
        }
    }
    
}
   