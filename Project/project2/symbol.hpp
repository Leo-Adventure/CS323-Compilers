#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include "tree.hpp"
#include "type.hpp"
#include "my_error.hpp"
#include <unordered_map>

void parseProgram(Node* program);
void parseExtDefList(Node* ext_def_list);
void parseExtDef(Node* ext_def);
GlobalType* parseSpecifier(Node* specifier);
ParamsList* parseDefList(Node* def_list, ParamsList* paramslist); // need return value
ParamsList* parseDef(Node* def, ParamsList* paramslist); // need return value
ParamsList* parseDecList(Node* dec_list, ParamsList* paramslist, GlobalType* globaltype); // need return value
ParamsList* parseDec(Node* dec, ParamsList* paramslist, GlobalType* globaltype); // need return value
ParamsList* parseVarDec(Node* var_dec, GlobalType* globaltype); // need
void parseVarList(Node* var_list, ParamsList* paramslist); // don't
ParamsList* parseParamDec(Node* param_dec, ParamsList* paramslist); // need
GlobalType* checkAssign(Node* exp1, Node* _ASSIGN, Node* exp2);
GlobalType* parseExp(Node* exp);
GlobalType* parseFunDec(Node* fun_dec, GlobalType* lasttype);
void parseCompSt(Node* compst, GlobalType* returntype);
void parseStmt(Node* stmt, GlobalType* returntype);
void parseStmtList(Node* stmt_list, GlobalType* returntype);
void parseExtDecList(Node* ext_dec_list, GlobalType* globaltype);
bool sameType(GlobalType* globaltype1, GlobalType* globaltype2);
Node* getNodePop(Node *);
GlobalType* checkArgs(Node * args, GlobalType* func_type, Node* id);
void printNodeName(Node* node);

#endif