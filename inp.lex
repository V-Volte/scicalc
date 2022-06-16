%{
    #include "y.tab.h"
    #include <iostream>
    #include "constants.h"
    void yyerror(char *s);
    int yylex();

%}

%%
":q"                        {return tok_exit;}
[\t ]                       {;}   

[(\{\[]                     {yylval.T_operator = yytext[0]; return LEFT_PAREN;}
[)\}\]]                     {yylval.T_operator = yytext[0]; return RIGHT_PAREN;}
[a-zA-Z][_a-zA-Z0-9]*          {yylval.T_identifier = yytext; return identifier;}
[+\-*\/%^]                  {yylval.T_operator = yytext[0]; return *yytext;}
[=\n;]                      {return yytext[0];}
[0-9]+(\.[0-9]+)?(e[+-][0-9]+)?           {yylval.T_number = atof(yytext) ; return number;}
@[a-zA-Z]+                  {yylval.T_identifier = yytext; return function;}
\$[a-zA-Z]+                 {if(isConstant(yytext)){yylval.T_number = getConstantValue(yytext); return number;}else{yyerror("Undefined constant");}}
""                          {;} 
.                           {std::cerr << "Illegal character: '" << yytext[0] << "'" << std::endl;}
%%

int yywrap(void) {
    return 1;
}