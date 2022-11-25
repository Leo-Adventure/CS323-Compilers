#include "symbol.hpp"
#include <stdlib.h>
#include <stdio.h>


#define DEBUG_INFO printf("file:%s line:%d function:%s\n", __FILE__, __LINE__, __FUNCTION__)
#define END_FUNCTION printf("END file:%s line:%d function:%s\n", __FILE__, __LINE__, __FUNCTION__)

unordered_map<string, GlobalType *> symbol_table;

void parseProgram(Node* program) {
    // Program: ExtDefList
    //DEBUG_INFO;
    parseExtDefList(getNodePop(program));
}

void parseExtDefList(Node* ext_def_list) {
    //DEBUG_INFO;
    // ExtDefList:
    //     Epsilon
    if (ext_def_list->nodes_num == 0) return;
    //     ExtDef ExtDefList
    Node* ext_def = getNodePop(ext_def_list);
    Node* ext_def_list1 = getNodePop(ext_def_list);
    parseExtDef(ext_def);
    parseExtDefList(ext_def_list1);
}

void parseExtDef(Node* ext_def) {
    //DEBUG_INFO;
    // ExtDef:
    Node* specifier = getNodePop(ext_def);

    GlobalType* spec_type = parseSpecifier(specifier);
    // if(spec_type == nullptr){
    //     printf("spec_type is nullptr\n");
    // }
    // else{
    //     printf("spec_type is not nullptr\n");
    // }

    Node* child = getNodePop(ext_def);

    if (child->name == "ExtDecList") { //Specifier ExtDecList SEMI
        Node* ext_dec_list = child;
        Node* _SEMI = getNodePop(ext_dec_list);
        parseExtDecList(ext_dec_list, spec_type);
    } else if (child->name == "FunDec") { //Specifier FunDec CompSt  
        Node* fun_dec = child;
        Node* comp_st = getNodePop(ext_def);
        GlobalType* fun_dec_type = parseFunDec(fun_dec, spec_type);

        if(fun_dec_type != nullptr){
            string func_name = fun_dec_type->params_ptr->name;
            if(symbol_table.count(func_name)){
                GlobalType* global_type = symbol_table[func_name];
                my_error(MY_ERROR_TYPE::REDEFINED_FUNC, fun_dec->line_num, func_name.c_str());
            } else {
                symbol_table[func_name] = fun_dec_type; 
                parseCompSt(comp_st, spec_type);
            }
		}
    }
    // |   Specifier SEMI
}

GlobalType* parseSpecifier(Node* specifier) {
    // Specifier:
    // printf("start ");
    //DEBUG_INFO;
    GlobalType* global_type = nullptr;
    Node* type = getNodePop(specifier);
    if (type->nodetype == NodeType::Type) { // TYPE
        if (!strcmp(type->char_value, "int")) {
            global_type = getGlobalTypeInt();
        }
        else if (!strcmp(type->char_value, "float")) {
            global_type = getGlobalTypeFloat();
        }else{
            global_type = getGlobalTypeChar();
        }
    } else if (type->name == "StructSpecifier") { // StructSpecifier:
        Node* _struct = getNodePop(type);
        Node* struct_id = getNodePop(type);
        char* struct_name = struct_id->char_value;
        // printf("struct_name: %s\n", struct_name);

        if (type->nodes_num != 2) { //STRUCT ID LC DefList RC
            if(symbol_table.count(struct_name) != 0){
                my_error(MY_ERROR_TYPE::REDEFINED_STRUCT, struct_id->line_num, struct_name);
                return nullptr;
            }

            Node* _LC = getNodePop(type);
            Node* def_list = getNodePop(type);
            Node* _RC = getNodePop(type);

            ParamsList* params_ptr = parseDefList(def_list, nullptr);
            global_type = new GlobalType(Category::STRUCTURE, params_ptr);
            symbol_table[string(struct_name)] = global_type;
            // printf("struct_name: (%s)\n", struct_name);

        } else { // STRUCT ID
            // printf("struct_name in parse specifier struct ID: %s\n", struct_name);
            if (symbol_table.count(struct_name) == 0) { // | STRUCT ID (Not declaration)
                my_error(MY_ERROR_TYPE::UNDEFINED_VARIABLE, struct_id->line_num, struct_name);
                return nullptr;
            }
            if (symbol_table[struct_name]->category != Category::STRUCTURE) {
                my_error(MY_ERROR_TYPE::STRUCT_MISMATCH, struct_id->line_num, struct_name);
                return nullptr;
            }
            global_type = symbol_table[struct_name];
        }
    }
    if(global_type != nullptr){
        // printf("global_type category %d\n", global_type->category);
    }
    // printf("end ");
    //DEBUG_INFO;
    return global_type;
}

ParamsList* parseDefList(Node* def_list, ParamsList* para) {
    // DefList: 
    //     Def DefList
    // |
    if(def_list->nodes_num == 0){
        return para;
	}

    Node* def = getNodePop(def_list);
    if (para == nullptr) {
        para = parseDef(def, para);
    } else {
        para->next = parseDef(def, para);
    }
    parseDefList(getNodePop(def_list), para);
    return para;
}

ParamsList* parseDef(Node* def, ParamsList* para) {
    // Def:
    //     Specifier DecList SEMI
    //DEBUG_INFO;
    Node* specifier = getNodePop(def);
    Node* dec_list = getNodePop(def);

    GlobalType* global_type = parseSpecifier(specifier);
    // if(global_type == nullptr){
    //     printf("global_type is nullptr in parsedef\n");
    // }
    para = parseDecList(dec_list, para, global_type);

	return para;
}

ParamsList* parseDecList(Node* dec_list, ParamsList* para, GlobalType* global_type) {
    // DecList: 
    //     Dec
    // |   Dec COMMA DecList
    //DEBUG_INFO;
    Node* dec = getNodePop(dec_list);

    para = parseDec(dec, para, global_type);
    if (dec_list->nodes_num != 1) {
    // |   Dec COMMA DecList
        Node* _COMMA = getNodePop(dec_list);
        Node* dec_list1 = getNodePop(dec_list);
        para = parseDecList(dec_list1, para, global_type);
    }
    return para;
}

ParamsList* parseDec(Node* dec, ParamsList* para, GlobalType* global_type) {
    // Dec: 
    //     VarDec
    // |   VarDec ASSIGN Exp
    //DEBUG_INFO;
    Node* var_dec = getNodePop(dec);
    ParamsList* var_dec_fields = parseVarDec(var_dec, global_type);

    if(dec->nodes_num != 1) {
        // TODO: maybe initialization in struct
        Node* _ASSIGN = getNodePop(dec);
        Node* exp = getNodePop(dec);
        GlobalType* exp_type = parseExp(exp);
        if(!sameType(global_type, exp_type)) {
            my_error(MY_ERROR_TYPE::ASSIGN_UNMATCH, var_dec->line_num);
        }
    }
    return var_dec_fields;
}

ParamsList* parseVarDec(Node* var_dec, GlobalType* global_type) {
    // VarDec:
    //DEBUG_INFO;
    //     ID
    // |   VarDec LB INT RB
    GlobalType* lasttype = global_type;
    // printf("last type category: %d", lasttype->category);
    // if(global_type == nullptr){
    //     printf("global type is nullptr\n");
    // }
    Node* next_node = nullptr;

	while(var_dec->nodes_num == 4)
	{
        next_node = getNodePop(var_dec);
        Node* _LB = getNodePop(var_dec);
        Node* int_node = getNodePop(var_dec);
        Node* _RB = getNodePop(var_dec);

        // printf("array int value %d\n", int_node->int_value);
        Array* newarray = new Array(lasttype, int_node->int_value);
        GlobalType* newtype = new GlobalType(Category::ARRAY, newarray);
        
		lasttype = newtype;
		var_dec = next_node; // Goto ID
	}
    Node* id = getNodePop(var_dec);
    ParamsList* result = new ParamsList(id->char_value, lasttype, nullptr);
    if(symbol_table.count(result->name) != 0){
        my_error(MY_ERROR_TYPE::REDEFINED_VARIABLE, id->line_num, result->name.c_str());
    }
    symbol_table[result->name] = lasttype;
    // printf("END__");
    //DEBUG_INFO;
    return result;
}

void parseVarList(Node* var_list, ParamsList* param) {
    // VarList:
    //     ParamDec COMMA VarList
    // |   ParamDec
    //DEBUG_INFO;
    Node* param_dec = getNodePop(var_list);

    param = parseParamDec(param_dec, param);
    if (var_list->nodes_num != 1) {
        Node* _COMMA = getNodePop(var_list);
        Node* var_list1 = getNodePop(var_list);
        parseVarList(var_list1, param);
    }
}

ParamsList* parseParamDec(Node* param_dec, ParamsList* param) {
    // ParamDec:
    //     Specifier VarDec
    //DEBUG_INFO;
    Node* specifier = getNodePop(param_dec);
    GlobalType* spec = parseSpecifier(specifier);
    if(spec != nullptr) {
        Node* var_dec = getNodePop(param_dec);
        ParamsList* temp = parseVarDec(var_dec, spec);
        param->next = temp;
        param = temp;
    }
    return param;
}

GlobalType* checkAssign(Node* exp1, Node* _ASSIGN, Node* exp2){
    //DEBUG_INFO;
    GlobalType* global_type = nullptr;
    GlobalType* exp1_type = parseExp(exp1);
    GlobalType* exp2_type = parseExp(exp2);
    bool flag = false;
    switch(exp1->nodes_num){
        case 1:{
            Node* id = getNodePop(exp1);
            if(id->nodetype == NodeType::Id){
                flag = true;
            }
            break;
        }
        case 3:{ // EXP DOT ID
            Node* exp = getNodePop(exp1);
            Node* _DOT = getNodePop(exp1);
            Node* id = getNodePop(exp1);
            if(exp->name == "Exp" && _DOT->name == "DOT" && id->nodetype == NodeType::Id){
                flag = true;
            }
            break;
        }
        case 4:{ // Exp LB Exp RB
            Node* lhs_exp1 = getNodePop(exp1);
            Node* _LB = getNodePop(exp1);
            Node* lhs_exp2 = getNodePop(exp1);
            Node* _RB = getNodePop(exp1);
            if(lhs_exp1->name == "Exp" && _LB->name == "LB" && lhs_exp2->name == "Exp" && _RB->name == "RB"){
                flag = true;
            }
            break;
        }
    }
    if(!flag){
        my_error(MY_ERROR_TYPE::RVALUE_ERROR, exp1->line_num);
    }
    else if (!sameType(exp1_type, exp2_type)) {
        
        my_error(MY_ERROR_TYPE::ASSIGN_UNMATCH, _ASSIGN->line_num);
    } else {
        global_type = exp1_type;
    }
    //END_FUNCTION;
    return global_type;
}

GlobalType* parseExp(Node* exp){
    GlobalType* global_type = nullptr;
    if(exp->nodes_num == 1){ // ID | CHAR | FLOAT | INT
        Node* node1 = getNodePop(exp);
        if(node1->nodetype == NodeType::Id){ //ID
			if (symbol_table.count(node1->char_value) == 0) {
                my_error(MY_ERROR_TYPE::UNDEFINED_VARIABLE, node1->line_num, node1->char_value);
			} else {
				global_type = symbol_table[node1->char_value];
			}
        }else{ // CHAR | FLOAT | INT
            return getGlobalTypePrimitive(node1);
        }
    }else if(exp->nodes_num == 2){ // NOT EXP | MINUS EXP
        Node* node1 = getNodePop(exp);
        Node* node2 = getNodePop(exp);
        GlobalType* exp_type = parseExp(node2);
        if(node1->name == "NOT"){
            if(!(exp_type->category == Category::PRIMITIVE && exp_type->nodetype == NodeType::Int)) {
                my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node1->line_num);
            } else {
                global_type = getGlobalTypeInt();
            }
        }else if(node1->name == "MINUS"){
            if(exp_type->category != Category::PRIMITIVE || exp_type->nodetype == NodeType::Char) {
                my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node1->line_num);
            } else {
                global_type = exp_type;
            }
        }
    }else if(exp->nodes_num == 3){
        Node* node1 = getNodePop(exp);
        Node* node2 = getNodePop(exp);
        Node* node3 = getNodePop(exp);
        if (node2->name == "ASSIGN") { //  Exp ASSIGN Exp
            global_type = checkAssign(node1, node2, node3);
        }else if (node2->name == "AND" || node2->name == "OR") { // Exp AND Exp | Exp OR Exp
            Node* exp1 = node1;
            Node* exp2 = node3;
            GlobalType* exp1_type = parseExp(exp1);
            GlobalType* exp2_type = parseExp(exp2);
            if (!sameType(exp1_type, exp2_type) ||
                !(exp1_type->category == Category::PRIMITIVE && exp1_type->nodetype == NodeType::Int)) {
                my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node2->line_num);
            } else {
                global_type = exp1_type;
            }
        } else if (node2->name == "LT" || //  Exp LT Exp
                   node2->name == "LE" || // Exp LE Exp
                   node2->name == "GT" || // Exp GT Exp
                   node2->name == "GE" || // Exp GE Exp
                   node2->name == "NE" || // Exp NE Exp
                   node2->name == "EQ" || // Exp EQ Exp
                   node2->name == "PLUS" || // Exp PLUS Exp
                   node2->name == "MINUS" || // Exp MINUS Exp
                   node2->name == "MUL" || // Exp MUL Exp
                   node2->name == "DIV") { // Exp DIV Exp
            Node* exp1 = node1;
            Node* exp2 = node3;
            GlobalType* exp1_type = parseExp(exp1);
            GlobalType* exp2_type = parseExp(exp2);
            if (!sameType(exp1_type, exp2_type) || exp1_type->category != Category::PRIMITIVE) {
                my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node1->line_num);
            } else {
                global_type = exp1_type;
            }
        } else if (node2->name == "DOT") { //  Exp DOT ID
            Node* exp1 = node1;
            Node* member_id = node3;
            GlobalType* exp1_type = parseExp(exp1);
            // if(exp1_type == nullptr){
            //     printf("exp1_type is nullptr\n");
            // }
            // printf("here in DOT parse\n");
            if (exp1_type->category != Category::STRUCTURE) {
                my_error(MY_ERROR_TYPE::DOT_ERROR, exp1->line_num);
			} else {
                ParamsList* param = nullptr;
				for(param = exp1_type->params_ptr; param != nullptr; param = param->next) {
					if(param->name == string(member_id->char_value)) break;
                }
				if(param == nullptr) {
                    my_error(MY_ERROR_TYPE::UNDEFINED_STRUCT_MEMBER, member_id->line_num, member_id->char_value);
				} else {
					global_type = param->global_type;
				}
			}
        } else if (node1->name == "LP") { //  LP Exp RP
            global_type = parseExp(node2);
        } else if(node1->nodetype == NodeType::Id){
            if (symbol_table.count(node1->char_value) == 0) {
                my_error(MY_ERROR_TYPE::UNDEFINED_FUNC, node1->line_num, node1->char_value);
                return nullptr;
			} else if (symbol_table[node1->char_value]->category != Category::FUNCTION) {
                my_error(MY_ERROR_TYPE::FUNC_INVOKE_ERROR, node1->line_num, node1->char_value);
                return nullptr;
            }
            GlobalType* func_type = symbol_table[node1->char_value];
            if(func_type->params_ptr->next == nullptr) {
                global_type = func_type->params_ptr->global_type;
            } else {
                my_error(MY_ERROR_TYPE::ARGS_MISMATCH, node1->line_num, node1->char_value);
            }
        }
    }else if(exp->nodes_num == 4){
        Node* node1 = getNodePop(exp);
        Node* node2 = getNodePop(exp);
        Node* node3 = getNodePop(exp);
        Node* node4 = getNodePop(exp);
        if(node1->nodetype == NodeType::Id){ // ID LP Args RP
            if (symbol_table.count(node1->char_value) == 0) {
                my_error(MY_ERROR_TYPE::UNDEFINED_FUNC, node1->line_num, node1->char_value);
                return nullptr;
			} else if (symbol_table[node1->char_value]->category != Category::FUNCTION) {
                my_error(MY_ERROR_TYPE::FUNC_INVOKE_ERROR, node1->line_num, node1->char_value);
                return nullptr;
            }
            GlobalType* func_type = symbol_table[node1->char_value];
            global_type = checkArgs(node3, func_type, node1);
        }else if (node2->name == "LB") { //  Exp LB Exp RB
            Node* exp1 = node1;
            Node* exp2 = node3;
            GlobalType* exp1_type = parseExp(exp1);
            GlobalType* exp2_type = parseExp(exp2);
			if (exp1_type->category != Category::ARRAY) {
                my_error(MY_ERROR_TYPE::INDEX_OPERATOR_ERROR, node1->line_num);
			} else if (!(exp2_type->category == Category::PRIMITIVE && exp2_type->nodetype == NodeType::Int)) {
                my_error(MY_ERROR_TYPE::INDEX_TYPE_ERROR, exp2->line_num);
                global_type = exp1_type->array_ptr->base;
            } else {
                global_type = exp1_type->array_ptr->base;
            }
        }
    }
    return global_type;
}

// GlobalType* parseExp(Node* exp) {
//     // Exp:
//     //DEBUG_INFO;
//     Node* node1 = getNodePop(exp);
//     GlobalType* global_type = nullptr;
//     if (node1->name == "Exp") {
//         Node* node2 = getNodePop(exp);
//         if (node2->name == "ASSIGN") { //  Exp ASSIGN Exp
//             Node* node3 = getNodePop(exp);
//             global_type = checkAssign(node1, node2, node3);
//         } else if (node2->name == "AND" || node2->name == "OR") { // Exp AND Exp | Exp OR Exp
//             Node* node3 = getNodePop(exp);
//             Node* exp1 = node1;
//             Node* exp2 = node3;
//             GlobalType* exp1_type = parseExp(exp1);
//             GlobalType* exp2_type = parseExp(exp2);
//             if (!sameType(exp1_type, exp2_type) ||
//                 !(exp1_type->category == Category::PRIMITIVE && exp1_type->nodetype == NodeType::Int)) {
//                 my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node2->line_num);
//             } else {
//                 global_type = exp1_type;
//             }
//         } else if (node2->name == "LT" || //  Exp LT Exp
//                    node2->name == "LE" || // Exp LE Exp
//                    node2->name == "GT" || // Exp GT Exp
//                    node2->name == "GE" || // Exp GE Exp
//                    node2->name == "NE" || // Exp NE Exp
//                    node2->name == "EQ" || // Exp EQ Exp
//                    node2->name == "PLUS" || // Exp PLUS Exp
//                    node2->name == "MINUS" || // Exp MINUS Exp
//                    node2->name == "MUL" || // Exp MUL Exp
//                    node2->name == "DIV") { // Exp DIV Exp
//             Node* node3 = getNodePop(exp);
//             Node* exp1 = node1;
//             Node* exp2 = node3;
//             GlobalType* exp1_type = parseExp(exp1);
//             GlobalType* exp2_type = parseExp(exp2);
//             if (!sameType(exp1_type, exp2_type) || exp1_type->category != Category::PRIMITIVE) {
//                 my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node1->line_num);
//             } else {
//                 global_type = exp1_type;
//             }
//         } else if (node2->name == "LB") { //  Exp LB Exp RB
//             Node* node3 = getNodePop(exp);
//             Node* node4 = getNodePop(exp);
//             Node* exp1 = node1;
//             Node* exp2 = node3;
//             GlobalType* exp1_type = parseExp(exp1);
//             GlobalType* exp2_type = parseExp(exp2);
// 			if (exp1_type->category != Category::ARRAY) {
//                 my_error(MY_ERROR_TYPE::INDEX_OPERATOR_ERROR, node1->line_num);
// 			} else if (!(exp2_type->category == Category::PRIMITIVE && exp2_type->nodetype == NodeType::Int)) {
//                 my_error(MY_ERROR_TYPE::INDEX_TYPE_ERROR, exp2->line_num);
//                 global_type = exp1_type->array_ptr->base;
//             } else {
//                 global_type = exp1_type->array_ptr->base;
//             }
//         } else if (node2->name == "DOT") { //  Exp DOT ID
//             Node* node3 = getNodePop(exp);
//             Node* exp1 = node1;
//             Node* member_id = node3;
//             GlobalType* exp1_type = parseExp(exp1);
//             if(exp1_type == nullptr){
//                 printf("exp1_type is nullptr\n");
//             }
//             printf("here in DOT parse\n");
//             if (exp1_type->category != Category::STRUCTURE) {
//                 my_error(MY_ERROR_TYPE::DOT_ERROR, exp1->line_num);
// 			} else {
//                 ParamsList* param = nullptr;
// 				for(param = exp1_type->params_ptr; param != nullptr; param = param->next) {
// 					if(param->name == string(member_id->char_value)) break;
//                 }
// 				if(param == nullptr) {
//                     my_error(MY_ERROR_TYPE::UNDEFINED_STRUCT_MEMBER, member_id->line_num, member_id->char_value);
// 				} else {
// 					global_type = param->global_type;
// 				}
// 			}
//         }
//     } else if (node1->name == "LP") { //  LP Exp RP
//         Node* node2 = getNodePop(exp);
//         Node* _RP = getNodePop(exp);
//         global_type = parseExp(node2);
//     } else if (node1->name == "MINUS") { // MINUS Exp
//         Node* node2 = getNodePop(exp);
//         GlobalType* exp_type = parseExp(node2);
//         if(exp_type->category != Category::PRIMITIVE) {
//             my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node1->line_num);
//         } else {
//             global_type = exp_type;
//         }
//     } else if (node1->name == "NOT") { //  NOT 
//         Node* node2 = getNodePop(exp);
//         GlobalType* exp_type = parseExp(node2);
//         if(!(exp_type->category == Category::PRIMITIVE && exp_type->nodetype == NodeType::Int)) {
//             my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, node1->line_num);
//         } else {
//             global_type = getGlobalTypeInt();
//         }
//     } else if (node1->nodetype == NodeType::Id) {
//         if (exp->nodes_num != 1) {
//     // |   ID LP Args RP
//     // |   ID LP RP
//             if (symbol_table.count(node1->char_value) == 0) {
//                 my_error(MY_ERROR_TYPE::UNDEFINED_FUNC, node1->line_num, node1->char_value);
//                 return nullptr;
// 			} else if (symbol_table[node1->char_value]->category != Category::FUNCTION) {
//                 my_error(MY_ERROR_TYPE::FUNC_INVOKE_ERROR, node1->line_num, node1->char_value);
//                 return nullptr;
//             }
//             GlobalType* func_type = symbol_table[node1->char_value];
//             if (exp->nodes_num == 4) { //  ID LP Args RP
//                 Node* _LP = getNodePop(exp);
//                 Node* args = getNodePop(exp);
//                 Node* _RP = getNodePop(exp);
//                 global_type = checkArgs(args, func_type, node1);
//             } else {
//                 if(func_type->params_ptr->next == nullptr) {
//                     global_type = func_type->params_ptr->global_type;
//                 } else {
//                     my_error(MY_ERROR_TYPE::ARGS_MISMATCH, node1->line_num, node1->char_value);
//                 }
//             }
//         } else { // ID
// 			if (symbol_table.count(node1->char_value) == 0) {
//                 my_error(MY_ERROR_TYPE::UNDEFINED_VARIABLE, node1->line_num, node1->char_value);
// 			} else {
// 				global_type = symbol_table[node1->char_value];
// 			}
//         }
//     } else if (node1->nodetype == NodeType::Int) {
//         global_type = getGlobalTypeInt();
//     } else if(node1->nodetype == NodeType::Float) { // |   FLOAT
//         global_type = getGlobalTypeFloat();
//     } else if(node1->nodetype == NodeType::Char) { // |   CHAR
//         global_type = getGlobalTypeChar();
//     }
//     //END_FUNCTION;
//     return global_type;
// }

GlobalType* checkArgs(Node * args, GlobalType* func_type, Node* id){
    //DEBUG_INFO;
    ParamsList* args_type = func_type->params_ptr->next;
    GlobalType* global_type = nullptr;
    if (args_type == nullptr) {
        my_error(MY_ERROR_TYPE::ARGS_MISMATCH, id->line_num, id->char_value);
        return global_type;
    }
    // Args: Exp COMMA Args
    //   |   Exp
    Node* exp = getNodePop(args);
    while (true) {
        GlobalType* exp_type = parseExp(exp);
        if (exp_type != nullptr) {
            if(!sameType(exp_type, args_type->global_type)) {
                // printf("not the same type\n");
                my_error(MY_ERROR_TYPE::ARGS_MISMATCH, id->line_num, id->char_value);
                break;
            }
            args_type = args_type->next;
            if (args_type == nullptr && args->nodes_num == 1) {
                global_type = func_type->params_ptr->global_type;
                break;
            }
            if (args_type != nullptr && args->nodes_num == 1) {
                // printf("given less ");
                my_error(MY_ERROR_TYPE::ARGS_MISMATCH, id->line_num, id->char_value);
                break;
            } 
            if (args_type == nullptr && args->nodes_num != 1) {
                // printf("given more ");
                my_error(MY_ERROR_TYPE::ARGS_MISMATCH, id->line_num, id->char_value);
                break;
            }
            Node* _COMMA = getNodePop(args);
            args = getNodePop(args);
            exp = getNodePop(args);
        }
    }
    //END_FUNCTION;
    return global_type;
}


GlobalType* parseFunDec(Node* fun_dec, GlobalType* lasttype) {
    // FunDec:
    //     ID LP VarList RP
    // |   ID LP RP
    //DEBUG_INFO;
	Node* func_id = getNodePop(fun_dec);
	ParamsList* param = new ParamsList(func_id->char_value, lasttype, nullptr);
    GlobalType* global_type = new GlobalType(Category::FUNCTION, param);

	if(fun_dec->nodes_num == 3) { //    ID LP RP
		param->next = nullptr;
	} else { //    ID LP VarList RP
        Node* _LP = getNodePop(fun_dec);
        Node* var_list = getNodePop(fun_dec);
        Node* _RP = getNodePop(fun_dec);
		parseVarList(var_list, param);
	}
    return global_type;
}

void parseCompSt(Node* compst, GlobalType* returntype) {
    // CompSt: 
    //     LC DefList StmtList RC
    Node* _LC = getNodePop(compst);
    Node* def_list = getNodePop(compst);
    Node* stmt_list = getNodePop(compst);
    Node* _RC = getNodePop(compst);
    parseDefList(def_list, nullptr);
    parseStmtList(stmt_list, returntype);

}

void parseStmtList(Node* stmt_list, GlobalType* returntype) {
    // StmtList: 
    //     Stmt StmtList
    //DEBUG_INFO;
    if (stmt_list->nodes_num != 0) {
        Node* stmt = getNodePop(stmt_list);
        Node* stmt_list1 = getNodePop(stmt_list);
        parseStmt(stmt, returntype);
        parseStmtList(stmt_list1, returntype);
    }
    //END_FUNCTION;
}

void parseStmt(Node* stmt, GlobalType* returntype) {
    // Stmt:
    //DEBUG_INFO;
    Node* node1 = getNodePop(stmt);
	if(node1->name == "Exp") { // Exp SEMI
        parseExp(node1);
    } else if(node1->name == "CompSt") { //   CompSt
		parseCompSt(node1, returntype);
	} else if(node1->name == "RETURN") { //  RETURN Exp SEMI
        Node* exp = getNodePop(stmt);
		GlobalType* exp_type = parseExp(exp);
		if (exp_type != nullptr && !sameType(returntype, exp_type)) {
            my_error(MY_ERROR_TYPE::RETURN_VALUE_MISMATCH, node1->line_num);
		}
	} else if(node1->name == "IF") { //  IF LP Exp RP Stmt 
        //  IF LP Exp RP Stmt ELSE Stmt
        Node* _LP = getNodePop(stmt);
        Node* exp = getNodePop(stmt);
        Node* _RP = getNodePop(stmt);
        Node* stmt1 = getNodePop(stmt);
		GlobalType* exp_type = parseExp(exp);
		if(exp_type != nullptr) {
            if(!(exp_type->category == Category::PRIMITIVE && exp_type->nodetype == NodeType::Int)) {
                my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, exp->line_num);
            } else {
                parseStmt(stmt1, returntype); //  IF LP Exp RP Stmt 
                if(stmt->nodes_num == 7) { //  IF LP Exp RP Stmt1 ELSE Stmt2
                    Node* _ELSE = getNodePop(stmt);
                    Node* stmt2 = getNodePop(stmt);
                    parseStmt(stmt2, returntype);
                }
            }
		}
	} else if(node1->name == "WHILE") { // |   WHILE LP Exp RP Stmt 
        Node* _LP = getNodePop(stmt);
		Node* exp = getNodePop(stmt);
		GlobalType* exp_type = parseExp(exp);
		if(exp_type != nullptr) {
			if(!(exp_type->category == Category::PRIMITIVE && exp_type->nodetype == NodeType::Int)) {
                my_error(MY_ERROR_TYPE::UNMATCH_OPERAND, exp->line_num);
            } else {
                Node* _RP = getNodePop(stmt);
                Node* stmt1 = getNodePop(stmt);
                parseStmt(stmt1, returntype);
            }
		}
	}
    //END_FUNCTION;
}

void parseExtDecList(Node* ext_dec_list, GlobalType* global_type) {
    // ExtDecList:
    // |   VarDec COMMA ExtDecList
    //     VarDec
    //DEBUG_INFO;
    Node* var_dec = getNodePop(ext_dec_list);
    parseVarDec(var_dec, global_type);
    if (ext_dec_list->nodes_num != 1) {
        Node* _COMMA = getNodePop(ext_dec_list);
        Node* ext_dec_list1 = getNodePop(ext_dec_list);
        parseExtDecList(ext_dec_list1, global_type);
    }
}

bool sameType(GlobalType* global_type1, GlobalType* global_type2) {
    if (global_type1 == nullptr || global_type2 == nullptr) {
        return false;
    }
    if (global_type1->category == global_type2->category) {
        if (global_type1->category == Category::PRIMITIVE && global_type1->nodetype == global_type2->nodetype) {
            return true;
        } else if (global_type1->category == Category::ARRAY &&
            sameType(global_type1->array_ptr->base, global_type2->array_ptr->base) &&
            global_type1->array_ptr->size == global_type2->array_ptr->size) {
            return true;
        } else if(global_type1->category == Category::STRUCTURE || global_type1->category == Category::FUNCTION) {
			ParamsList* param1 = global_type1->params_ptr;
			ParamsList* param2 = global_type2->params_ptr;
			while(param1 != nullptr && param2 != nullptr)
			{
				if(!sameType(param1->global_type, param2->global_type)) {
					return false;
                }
				param1 = param1->next;
				param2 = param2->next;
			}
			if(param1 != nullptr || param2 != nullptr) {
				return false;
            }
			return true;
		}
    }
    return false;
}

void printNodeName(Node* node){
    switch (node->nodetype)
    {
    case Type:
    {
        printf("TYPE: %s\n", node->char_value);
        break;
    }
    case Int:
    {
        printf("INT: %s\n", node->name.c_str());
        break;
    }
    case Char:
    {
        printf("CHAR: %s\n", node->char_value);
        break;
    }
    case Float:
    {
        printf("FLOAT: %s\n", node->name.c_str());
        break;
    }
    case Id:
    {
        printf("ID: %s\n", node->char_value);
        break;
    }
    case TERMINAL:
    {
        printf("TERMINAL %s\n", node->name.c_str());
        break;
    }
    case NONTERMINAL:
    {
        printf("NONTERMINAL %s\n", node->name.c_str());
        break;
    }
    }
}

Node* getNodePop(Node* node){
    //DEBUG_INFO;
    Node* res = node->nodes_queue.front();
    // printNodeName(res);
    node->nodes_queue.pop();
    node->nodes_queue.push(res);
    return res;
}