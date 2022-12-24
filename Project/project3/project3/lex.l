%{
    #include "string.h"
    #include "stdlib.h"
    extern "C" int yylex();
    extern int has_error;
%}
%{
    /* library inclusions */
    #include"syntax.tab.h"
    int yycolno = 1;
    #define YY_USER_ACTION \
    yylloc.first_line = yylineno; \
    yylloc.first_column = yycolno; \
    yylloc.last_line = yylineno; \
    yylloc.last_column = yycolno + yyleng; \
    yycolno += yyleng;
%}

%option yylineno

TYPE "int"|"float"|"char"
STRUCT "struct"
IF "if"
ELSE "else"
WHILE "while"
RETURN "return"
DOT "."
SEMI ";"
COMMA ","
ASSIGN "="
LT "<"
LE "<="
GT ">"
GE ">="
NE "!="
EQ "=="
PLUS "+"
MINUS "-"
MUL "*"
DIV "/"
AND "&&"
OR "||"
NOT "!"
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"


letter[a-zA-Z]
letter_[a-zA-Z_]
digit[0-9]
pos_digit[1-9]
hex_digit [0-9a-fA-F]

decimal (0|{pos_digit}{digit}*)
hexadecimal (0x)({hex_digit}+)

ID {letter_}+({letter_}|{digit})*
INT {decimal}|{hexadecimal}
FLOAT ({digit}+.{digit}+)
CHAR \'(\\x{hex_digit}{2}|.)\'
INVALID_CHAR \'.*\'
WRONG_ID ({INT}{ID})|{INVALID_CHAR}
COMMENT "//".*$
MULTIPLE_COMMENT "/*"((("*"[^/])?)|[^*])*"*/" 
ILLEGAL_TOKEN [^\x20^\n^\x09]
INVALID_NUMBER ([+-]?0x[0-9a-zA-Z]*)|(00+)


%%



{COMMENT} {}
{MULTIPLE_COMMENT} {
}

{TYPE} {yylval.node_ptr = new Node(Type, yytext, "",yylineno);
return TYPE;}

{STRUCT} {yylval.node_ptr = new Node("STRUCT", yylineno);
return STRUCT;}


{IF} {yylval.node_ptr = new Node("IF", yylineno); return IF;}
{ELSE} { yylval.node_ptr = new Node("ELSE", yylineno); return ELSE;}
{WHILE} {yylval.node_ptr = new Node("WHILE", yylineno); return WHILE;}
{RETURN} {yylval.node_ptr = new Node("RETURN", yylineno); return RETURN;}
{DOT} {yylval.node_ptr = new Node("DOT", yylineno); return DOT;}
{SEMI} {yylval.node_ptr = new Node("SEMI", yylineno); return SEMI;}
{COMMA} {yylval.node_ptr = new Node("COMMA", yylineno); return COMMA;}
{ASSIGN} {yylval.node_ptr = new Node("ASSIGN", yylineno); return ASSIGN;}
{LT} {yylval.node_ptr = new Node("LT", yylineno); return LT;}
{LE} {yylval.node_ptr = new Node("LE", yylineno); return LE;}
{GT} {yylval.node_ptr = new Node("GT", yylineno); return GT;}
{GE} {yylval.node_ptr = new Node("GE", yylineno); return GE;}
{NE} {yylval.node_ptr = new Node("NE", yylineno); return NE;}
{EQ} {yylval.node_ptr = new Node("EQ", yylineno); return EQ;}
{PLUS} {yylval.node_ptr = new Node("PLUS", yylineno); return PLUS;}
{MINUS} {yylval.node_ptr = new Node("MINUS", yylineno); return MINUS;}
{MUL} {yylval.node_ptr = new Node("MUL", yylineno); return MUL;}
{DIV} {yylval.node_ptr = new Node("DIV", yylineno); return DIV;}
{AND} {yylval.node_ptr = new Node("AND", yylineno); return AND;}
{OR} {yylval.node_ptr = new Node("OR", yylineno); return OR;}
{NOT} {yylval.node_ptr = new Node("NOT", yylineno); return NOT;}
{LP} {yylval.node_ptr = new Node("LP", yylineno); return LP;}
{RP} {yylval.node_ptr = new Node("RP", yylineno); return RP;}
{LB} {yylval.node_ptr = new Node("LB", yylineno); return LB;}
{RB} {yylval.node_ptr = new Node("RB", yylineno); return RB;}
{LC} {yylval.node_ptr = new Node("LC", yylineno); return LC;}
{RC} {yylval.node_ptr = new Node("RC", yylineno); return RC;}
{INT} {
    int int_value = 0;
    if (strlen(yytext) >= 3 && yytext[0] == '0') /* in hexidecimal form */
        sscanf(yytext, "%x", &int_value);
    else /* in decimal form */
        int_value = atoi(yytext);
    char *str_value = (char *)malloc(10*sizeof(char));
    yylval.node_ptr = new Node(Int, yytext, str_value, int_value, yylineno); 
    return INT;
    }
{FLOAT} {
    stringstream ss; 
    ss.str(yytext); 
    string value = ss.str();
    yylval.node_ptr = new Node(Float, yytext, value, (float)atof(yytext), yylineno); 
    return FLOAT;
}
{CHAR} {
    stringstream ss; 
    ss.str(yytext); 
    string value = ss.str();
    yylval.node_ptr = new Node(Char,yytext, value, yylineno); 
    return CHAR;
}
"read" {
    yylval.node_ptr=new Node("READ", yylineno);
    return READ;
}
"write" {
    yylval.node_ptr=new Node("WRITE", yylineno);
    return WRITE;
}
{WRONG_ID} {has_error=1; fprintf(stdout,"Error type A at Line %d: unknown lexeme %s\n",
               yylineno, yytext); return ID;}
{ID} {
    stringstream ss;
    ss.str(yytext);
    string value = ss.str();
    yylval.node_ptr = new Node(Id, yytext, value, yylineno); 
    return ID;}
[ \t\r]+ {}
"\n" { yycolno = 1; }
{ILLEGAL_TOKEN} {has_error=1; fprintf(stdout,"Error type A at Line %d: unknown lexeme %s\n",
               yylineno, yytext); return ILLEGAL_TOKEN;}
{INVALID_NUMBER} {has_error=1; fprintf(stdout,"Error type A at Line %d: unknown lexeme %s\n",
               yylineno, yytext); return INVALID_NUMBER;}
%%
