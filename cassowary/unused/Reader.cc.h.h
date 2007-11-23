typedef union {
  double num;
  const Variable *pclv;
  LinearExpression *pcle;
  Constraint *pcn;
} YYSTYPE;
#define	NUM	257
#define	VAR	258
#define	RO_VAR	259
#define	GEQ	260
#define	GT	261
#define	LEQ	262
#define	LT	263
#define	NEG	264

