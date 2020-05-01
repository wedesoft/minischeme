enum yytokentype {
  NUMBER = 258,
  SYMBOL = 259
};

union YYSTYPE {
  int number;
  char *symbol;
};

typedef union YYSTYPE YYSTYPE;

extern YYSTYPE yylval;

int yylex(void);
