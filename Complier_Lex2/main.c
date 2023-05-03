/*
* main.c–각 토큰에 대한 출력
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/
#include "tn.h"
#include "glob.h"

//initialize global variables
line_num = 1;
nextid = 0;  //the current identifier
nextfree = 0;  //the next available index of ST


/*
* getTokenName -- token number에 따른 token name 반환
*/
char* getTokenName(enum tnumber tn){
	switch (tn) {
		case TCONST:	return "const";
		case TELSE:		return "else";
		case TIF:		return "if";
		case TINT:		return "integer";
		case TRETURN:	return "return";
		case TVOID:		return "void";
		case TWHILE:	return "while";

		case TPLUS:		return "Plus op";
		case TMINUS:	return "Minus op";
		case TSTAR:		return "star";
		case TSLASH:	return "slash";
		case TMOD:		return "mod";

		case TASSIGN:	return"assign op";
		case TADDASSIGN: return"add assign op";
		case TSUBASSIGN: return"sub assign op";
		case TMULASSIGN: return"mul assign op";
		case TDIVASSIGN: return"div assign op";
		case TMODASSIGN: return"mod assign op";

		case TNOT:		return "not";
		case TAND:		return "and";
		case TOR:		return "or";

		case TEQUAL:		return "equal";
		case TNOTEQU:		return "not equal";
		case TLESS:			return "less";
		case TGREAT:		return "great";
		case TLESSE:		return "less or equal";
		case TGREATE:		return "great or equal";

		case TINC:			return "increase";
		case TDEC:			return "decrease";

		case TLPAREN:		return "left paren";
		case TRPAREN:		return "right paren";
		case TCOMMA:		return "comma";
		case (TLBRACE):		return "left brace";
		case (TRBRACE):		return "right brace";
		case (TLBRACKET):	return "left bracket";
		case (TRBRACKET):	return"right bracket";
		case (TSEMI):		return"semicolon";

		case TNUMBER:		return "Number";
		case TDOT:			return "Dot";
		case TCOMMENT:		return "comment";
		}
}
/*
* printToken() -- token type별로 출력
*/
void printToken(enum tnumber tn) {
	//TODO: STindex, yytext 잘 출력되나 확인
	if (tn == TIDENT) {
		//print Line number,Ttoken type, ST-index, Token
		printf("%-20d%-20s%-20d%-20s", line_num, "ident",  nextfree, yytext);
	}
	else if(tn != TERROR) {
		//print Line number, Token type, Token
		//TODO: 출력형식 고치기
		printf("%-20d%-40s%-20s", line_num, getTokenName(tn), yytext);
	}
	printf("\n");
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

	while  ((tn = yylex()) != TEOF) {
		printToken(tn);
	}

	//Print the number of errors
	if (cErrors == 0) {
		printf("No errors detected\n");
	}
	else {
		printf("%d errors detected\n", cErrors);
	}

}