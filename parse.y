%{
    #include "things.h"
    #include <cstdlib>
    #include <vector>
    #include <string>
    void yyerror(char *);
    int yylex();   

%}

%union {float T_number; char* T_identifier; char T_operator;}
%start line
/* %token <T_operator> newOperator; */
%token <T_identifier> tok_exit function;
%token <T_operator> LEFT_PAREN RIGHT_PAREN;
%left '+' '-'
%left '*' '/'
%token <T_identifier> identifier;
%token <T_number> number;
%type <T_number> line expression term;
%type <T_identifier> assignment;


%%

line        : assignment  '\n'       {;}
            | expression   '\n'      {coutf($1);}
            | tok_exit     '\n'         {exit(0);}
            | line assignment '\n'  {;}
            | line expression '\n'   {coutf($2);}
            | line tok_exit    '\n'     {exit(0);}
            | '\n'  {;}
            | line '\n' {;}
            | error {;}
            ;

assignment  : identifier '=' expression     {vput(strip($1), $3); }
            ;

expression  : term                         {$$ = $1;}
            /* | expression newOperator expression    {$$ = operate($1, $3, $2);} */
            | function expression          {if(isFunction(functionStrip($1))) {$$ = functionValue(functionStrip($1), $2);} else {std::cout << "Function not found: " << functionStrip($1) << std::endl; $$ = 0;}}
            | expression '+' expression    {$$ = $1 + $3;}
            | expression '-' expression    {$$ = $1 - $3;}
            | expression '*' expression    {$$ = $1 * $3;}
            | expression '/' expression    {$$ = $1 / $3;}
            | expression '%' expression    {$$ = (int)$1 % (int)$3;}
            | expression '^' expression    {$$ = pow($1, $3);}
            | LEFT_PAREN expression RIGHT_PAREN    {$$ = $2;}
                        /* | newOperator function expression      {if($1 == '-'){if(isFunction(functionStrip($2))) {$$ = -functionValue(functionStrip($2), $3);} else {std::cout << "Function not found: " << functionStrip($2) << std::endl; $$ = 0;}}else{yyerror("Invalid operator.\n");} }             */
            | '-' expression               {$$ = -$2; }
            ;

            ;
term        : number                {$$ = $1;}
            | identifier            {$$ = vget(strip($1));}
            ;

%%

int main() {
    return yyparse();
}

void yyerror(char *s) {
    cerrs(s);
}
