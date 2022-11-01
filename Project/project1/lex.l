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

decimal [+-]?(0|{pos_digit}{digit}*)
hexadecimal [+-]?(0x)({hex_digit}+)

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

{TYPE} {yylval.node_ptr = new Node(Type, yytext);
return TYPE;}

{STRUCT} {yylval.node_ptr = new Node("STRUCT");
return STRUCT;}


{IF} {yylval.node_ptr = new Node("IF"); return IF;}
{ELSE} { yylval.node_ptr = new Node("ELSE"); return ELSE;}
{WHILE} {yylval.node_ptr = new Node("WHILE"); return WHILE;}
{RETURN} {yylval.node_ptr = new Node("RETURN"); return RETURN;}
{DOT} {yylval.node_ptr = new Node("DOT"); return DOT;}
{SEMI} {yylval.node_ptr = new Node("SEMI"); return SEMI;}
{COMMA} {yylval.node_ptr = new Node("COMMA"); return COMMA;}
{ASSIGN} {yylval.node_ptr = new Node("ASSIGN"); return ASSIGN;}
{LT} {yylval.node_ptr = new Node("LT"); return LT;}
{LE} {yylval.node_ptr = new Node("LE"); return LE;}
{GT} {yylval.node_ptr = new Node("GT"); return GT;}
{GE} {yylval.node_ptr = new Node("GE"); return GE;}
{NE} {yylval.node_ptr = new Node("NE"); return NE;}
{EQ} {yylval.node_ptr = new Node("EQ"); return EQ;}
{PLUS} {yylval.node_ptr = new Node("PLUS"); return PLUS;}
{MINUS} {yylval.node_ptr = new Node("MINUS"); return MINUS;}
{MUL} {yylval.node_ptr = new Node("MUL"); return MUL;}
{DIV} {yylval.node_ptr = new Node("DIV"); return DIV;}
{AND} {yylval.node_ptr = new Node("AND"); return AND;}
{OR} {yylval.node_ptr = new Node("OR"); return OR;}
{NOT} {yylval.node_ptr = new Node("NOT"); return NOT;}
{LP} {yylval.node_ptr = new Node("LP"); return LP;}
{RP} {yylval.node_ptr = new Node("RP"); return RP;}
{LB} {yylval.node_ptr = new Node("LB"); return LB;}
{RB} {yylval.node_ptr = new Node("RB"); return RB;}
{LC} {yylval.node_ptr = new Node("LC"); return LC;}
{RC} {yylval.node_ptr = new Node("RC"); return RC;}
{INT} {yylval.node_ptr = new Node(Int, yytext, atoi(yytext)); return INT;}
{FLOAT} {yylval.node_ptr = new Node(Float, yytext, (float)atof(yytext)); return FLOAT;}
{CHAR} {yylval.node_ptr = new Node(Char, yytext); return CHAR;}
{WRONG_ID} {has_error=1; fprintf(stdout,"Error type A at Line %d: unknown lexeme %s\n",
               yylineno, yytext); return ID;}
{ID} {yylval.node_ptr = new Node(Id, yytext); return ID;}
[ \t\r]+ {}
"\n" { yycolno = 1; }
{ILLEGAL_TOKEN} {has_error=1; fprintf(stdout,"Error type A at Line %d: unknown lexeme %s\n",
               yylineno, yytext); return ILLEGAL_TOKEN;}
{INVALID_NUMBER} {has_error=1; fprintf(stdout,"Error type A at Line %d: unknown lexeme %s\n",
               yylineno, yytext); return INVALID_NUMBER;}
%%
