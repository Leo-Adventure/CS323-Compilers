%{
    #include "tree.hpp"
    #include "lex.yy.c"
    #include <stdio.h>
    #include "stdlib.h"
    #include <string.h>
    #include "my_error.hpp"
    #include "symbol.hpp"
    #include "type.hpp"
    #include "inter_rep.hpp"
    void yyerror(const char* s);
    int has_error=0;
%}
%locations

%union{
    Node* node_ptr;
}

%nonassoc <node_ptr> ILLEGAL_TOKEN
%nonassoc LOWER_ELSE
%nonassoc <node_ptr> ELSE

%token <node_ptr> TYPE INT CHAR FLOAT STRUCT ID /* basic type word*/
%token <node_ptr> IF WHILE RETURN /* conditional keyword */

%token<node_ptr> COMMA

%right <node_ptr> ASSIGN

%token<node_ptr> WRITE READ

%left <node_ptr> OR
%left <node_ptr> AND
%left <node_ptr> LT LE GT GE NE EQ 
%left <node_ptr> PLUS MINUS 
%left <node_ptr> MUL DIV 
%right <node_ptr> NOT
%left <node_ptr> DOT LP RP LB RB 


%token <node_ptr> SEMI LC RC /* punctuation word */
%token <node_ptr> INVALID_CHAR WRONG_ID UNKNOWN_CHAR INVALID_NUMBER /* mistake word */


/* Non terminal */
%type <node_ptr> Program ExtDefList ExtDef ExtDecList
%type <node_ptr> Specifier StructSpecifier 
%type <node_ptr> VarDec FunDec VarList ParamDec CompSt StmtList
%type <node_ptr> Stmt DefList Def DecList Dec Exp Args

%%

Program : ExtDefList {$$ = new Node("Program", 1, "", @$.first_line, $1); if(has_error == 0) {inter_program($$);}}
;

ExtDefList : {$$ = new Node("ExtDefList", 0, "", @$.first_line);};
| ExtDef ExtDefList {$$ = new Node("ExtDefList", 2, "", @$.first_line, $1, $2);}
;

ExtDef : Specifier ExtDecList SEMI {$$=new Node("ExtDef", 3, "", @$.first_line, $1, $2, $3);}
| Specifier SEMI {$$=new Node("ExtDef", 2, "", @$.first_line, $1, $2);}
| Specifier FunDec CompSt {$$=new Node("ExtDef", 3, "", @$.first_line, $1, $2, $3);}
| Specifier ExtDecList error {my_error(MISS_SEMI, @$.first_line); has_error=1;}
| Specifier error {my_error(MISS_SEMI, @$.first_line); has_error=1;}
;

ExtDecList: VarDec {$$=new Node("ExtDecList", 1, "", @$.first_line, $1);};
| VarDec COMMA ExtDecList {$$=new Node("ExtDecList", 3, "", @$.first_line, $1, $2, $3);}
;

/* specifier */
Specifier: TYPE  {$$=new Node("Specifier", 1, "", @$.first_line, $1);}
| StructSpecifier  {$$=new Node("Specifier", 1, "", @$.first_line, $1);}
;

StructSpecifier: STRUCT ID LC DefList RC {$$=new Node("StructSpecifier", 5, "", @$.first_line, $1, $2, $3, $4, $5);}
| STRUCT ID {$$=new Node("StructSpecifier", 2, "", @$.first_line, $1, $2);}
| STRUCT ID LC DefList error {my_error(MISS_RC, @$.first_line); has_error=1;}
;

/* declarator */
VarDec: ID {$$=new Node("VarDec", 1, "", @$.first_line, $1);}
| VarDec LB INT RB {$$=new Node("VarDec", 4, "", @$.first_line, $1, $2, $3, $4);}
| VarDec LB INT error {my_error(MISS_RB, @$.first_line); has_error=1;}
;

FunDec: ID LP VarList RP {$$=new Node("FunDec", 4, "", @$.first_line, $1, $2, $3, $4);}
| ID LP RP {$$=new Node("FunDec", 3, "", @$.first_line, $1, $2, $3);}
| ID LP VarList error {my_error(MISS_RP, @$.first_line); has_error=1;}
| ID LP error {my_error(MISS_RP, @$.first_line); has_error=1;}
;

VarList: ParamDec COMMA VarList {$$=new Node("VarList", 3, "", @$.first_line, $1, $2, $3);}
| ParamDec {$$=new Node("VarList", 1, "", @$.first_line, $1);}
;

ParamDec: Specifier VarDec {$$=new Node("ParamDec", 2, "", @$.first_line, $1, $2);}
;

/* statement */
CompSt: LC DefList StmtList RC {$$=new Node("CompSt", 4, "", @$.first_line, $1, $2, $3, $4);}
;

StmtList: {$$ = new Node("StmtList", 0, "", @$.first_line);}
|Stmt StmtList {$$=new Node("StmtList", 2, "", @$.first_line, $1, $2);}
;
// here
Stmt: Exp SEMI {$$=new Node("Stmt", 2, "", @$.first_line, $1, $2);}
| CompSt {$$=new Node("Stmt", 1, "", @$.first_line, $1);}
| RETURN Exp SEMI {$$=new Node("Stmt", 3, "", @$.first_line, $1, $2, $3);}
| IF LP Exp RP Stmt %prec LOWER_ELSE {$$=new Node("Stmt", 5, "", @$.first_line, $1, $2, $3, $4, $5);}
| IF LP Exp RP Stmt ELSE Stmt {$$=new Node("Stmt", 7, "", @$.first_line, $1, $2, $3, $4, $5, $6, $7);}
| WHILE LP Exp RP Stmt {$$=new Node("Stmt", 5, "", @$.first_line, $1, $2, $3, $4, $5);}
| WRITE LP Exp RP SEMI { 
    $$ = new Node("Stmt", 5, "" ,@1.first_line, $1, $2, $3, $4, $5); 
};
| Exp error {my_error(MISS_SEMI, @$.first_line); has_error=1;}
| RETURN Exp error {my_error(MISS_SEMI, @$.first_line); has_error=1;}
| IF LP Exp error Stmt {my_error(MISS_RP, @$.first_line); has_error=1;}
| WHILE LP Exp error Stmt {my_error(MISS_RP, @$.first_line); has_error=1;}
;

/* local definition */ 
DefList: {$$ = new Node("DefList", 0, "", @$.first_line);};
| Def DefList {$$=new Node("DefList", 2, "", @$.first_line, $1, $2);}
; 

Def: Specifier DecList SEMI {$$=new Node("Def", 3, "", @$.first_line, $1, $2, $3);}
| Specifier DecList error{my_error(MISS_SEMI, @$.first_line); has_error=1;}
| error DecList SEMI {my_error(MISS_SPEC, @$.first_line +1); has_error=1;}
;

DecList: Dec {$$=new Node("DecList", 1, "", @$.first_line, $1);}
| Dec COMMA DecList {$$=new Node("DecList", 3, "", @$.first_line, $1, $2, $3);}
;

Dec: VarDec {$$=new Node("Dec", 1, "", @$.first_line, $1);}
| VarDec ASSIGN Exp  {$$=new Node("Dec", 3, "", @$.first_line, $1, $2, $3);}
;

/* Expression */
Exp: Exp ASSIGN Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp AND Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp OR Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp LT Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp LE Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp GT Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp GE Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp NE Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp EQ Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp PLUS Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp MINUS Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp MUL Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp DIV Exp {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| LP Exp RP {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}

| MINUS Exp {$$=new Node("Exp", 2, "", @$.first_line, $1, $2);}
| NOT Exp {$$=new Node("Exp", 2, "", @$.first_line, $1, $2);}
| ID LP Args RP {$$=new Node("Exp", 4, "", @$.first_line, $1, $2, $3, $4);}
| ID LP RP  {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| Exp LB Exp RB {$$=new Node("Exp", 4, "", @$.first_line, $1, $2, $3, $4);}
| Exp DOT ID {$$=new Node("Exp", 3, "", @$.first_line, $1, $2, $3);}
| ID {$$=new Node("Exp", 1, "", @$.first_line, $1);}
| INT {$$=new Node("Exp", 1, "", @$.first_line, $1);}
| FLOAT {$$=new Node("Exp", 1, "", @$.first_line, $1);}
| CHAR {$$=new Node("Exp", 1, "", @$.first_line, $1);}
| READ LP RP { 
    $$ = new Node("Exp", 3, "", @$.first_line, $1, $2, $3); 
}
| ILLEGAL_TOKEN {has_error = 1;}
| INVALID_NUMBER {has_error=1;}
| Exp ILLEGAL_TOKEN Exp {has_error = 1;}
| LP Exp error {my_error(MISS_RP, @$.first_line); has_error=1;} // yes
| ID LP Args error {my_error(MISS_RP, @$.first_line); has_error=1;} // yes
| ID LP error {my_error(MISS_RP, @$.first_line); has_error=1;} // yes
| Exp LB Exp error {my_error(MISS_RB, @$.first_line); has_error=1;}
;

Args : Exp COMMA Args {$$=new Node("Args", 3, "", @$.first_line, $1, $2, $3);}
| Exp  {$$=new Node("Args", 1, "", @$.first_line, $1);}
;
%%

void yyerror(const char* s) {
}
int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}