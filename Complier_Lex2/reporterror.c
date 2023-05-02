/*
* reporterror.c–handle errors
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/
#include "glob.h"

ERRORtypes err;

/* PrintError    - 	Print out error messages
			overst :  overflow in ST. print the hashtable and abort
			illid_digit    : illegal identifier (start with digit)
			illid_long	: illegal identifier (too long identifier)
			illid_illch	: illegal identifier (containing illegal characters) */
void PrintError(ERRORtypes err)
{
	printf("%-20d, %-40s", line_num, "**Error**");
	switch (err) {
	case overst: //overflow error
		printf("Overflow\n");
		nextfree = nextid; //TODO: 다시 확인
		exit(0);
		break;
	case illid_long: //too long identifier error
		printf("Too long identifier\n");
		break;
	case illid_illch: //illegal identifier error
		printf(yytext);
		printf(" Illegal IDENT\n");
		break;
	case illid_digit: //illegal identifier error
		//TODO: error중에서 identifier 아닌 문자 쓴 경우: scanner.l에서 처리
		printf(yytext);
		printf(" Illegal IDENT\n");
		break;
	}
}