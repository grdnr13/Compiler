/*
* main.c–각 토큰에 대한 출력
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/
#include "tn.h"
#include "glob.h"



/*
* printToken() -- token type별로 출력
*/
void printToken(enum tnumber tn) {
	if (tn == TIDENT) {
		//print Line number,Ttoken type, ST-index, Token
		printf("%-20d, %-20s, %-20d, %-20d", line_num, "Identifier", nextfree, yytext);
		//insert token to symbol table

	}
	else {
		//print Line number, Token type, Token
		//TODO: 출력형식 고치기
		printf("%-20d, %-40d, %-20s", line_num, tn, yytext);
	}

}

/*
* main -- 각 token별 처리, error 개수 출력
*/
void main()
{
	enum tnumber tn;  // token number
	//print Heading
	printf("\n\n");
	printf("Line number         Token type          ST-index            Token               \n");
	//printf("--------------------------------------------------------------------------------\n");
	//printf("\n");

	int cErrors = 0; //count the number of errors
	while  ((tn = yylex()) != TEOF) {
		printToken(tn);
		//switch (tn) {
		//	case TCONST	: printf("Const\n");  break;
		//	case TELSE	: printf("Else\n"); break;
		//	case TIF	: printf("If\n"); break;
		//	case TINT	: printf("Int\n"); break;
		//	case TRETURN : printf("Return\n"); break;
		//	case TVOID	: printf("Void\n"); break;
		//	case TWHILE	: printf("While\n"); break;
		//	case TEQUAL	: printf("Equal\n"); break;
		//	case TNOTEQU : printf("Not equal\n"); break;
		//	case TLESSE	: printf("Less equal\n"); break;
		//	case TGREATE : printf("greate equal\n"); break;
		//	case TAND	: printf("And\n"); break;
		//	case TOR    : printf("Or\n"); break;
		//	case TINC	: printf("Increase\n"); break;
		//	case TDEC	: printf("Decrease\n"); break;
		//	case TADDASSIGN	: printf("Add op\n"); break;
		//	case TSUBASSIGN	: printf("Sub op\n"); break;
		//	case TMULASSIGN	: printf("Mul op\n"); break;
		//	case TDIVASSIGN	: printf("Div op\n"); break;
		//	case TMODASSIGN: printf("Mod op\n"); break;
		//	case TIDENT	: printf("Identifier : %s\n",yytext); break;
		//	case TNUMBER	: printf("Number : %d\n",atoi(yytext)); break;
		//	case TDOT	: printf("%s\n",yytext[0]); break;
		//	case TASSIGN:	printf("Assign op = \n"); break;
		//	case TMINUS: printf("Minus op - \n"); break;
		//	case TPLUS:	printf("Plus op + \n"); break;
		//	case TLPAREN: printf("(\n"); break;
		//	case TRPAREN:	printf(")\n"); break;
		//	case TCOMMA:	printf(",\n"); break;
		//	case (TLBRACE):	printf("{\n"); break;
		//	case (TRBRACE):	printf("}\n"); break;
		//	case (TLBRACKET):	printf("[\n"); break;
		//	case (TRBRACKET):
		//	case (TSEMI):
		//	case (TSTAR):
		//	case (TSLASH):
		//	case (TMOD):
		//	case (TNOT):
		//	default: printf("test default %s \n", yytext); break;
		//}
	}

	//Print the number of errors
	if (cErrors == 0) {
		printf("No errors detected\n");
	}
	else {
		printf("%d errors detected\n", cErrors);
	}

}