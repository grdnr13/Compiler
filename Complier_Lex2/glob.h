/*
* glob.h–global variable for the project
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/
//TODO: 필요없는거 삭제하기
#include <stdio.h>
#include <stdlib.h>



//#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z' || (x) == '_') )
//#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

//#define MAX_LEN		12

#ifndef _LINENUM_
#define _LINENUM_
extern int line_num = 0; //count line numbers in scanner.l
#endif // !_LINENUM_

#ifndef _ERRORTYPES_
#define _ERRORTYPES_
extern enum errorTypes { illid_digit, illid_long, illid_illch, overst };
typedef enum errorTypes ERRORtypes;
extern ERRORtypes err;
#endif // !_ERRORTYPES_

//#ifndef __SYMTABLE_TYPES__
//#define __SYMTABLE_TYPES__
//typedef struct HTentry* HTpointer;
//typedef struct HTentry {
//	int index;  //index of identifier in ST
//	HTpointer next;  //pointer to next identifier
//} HTentry;
//
//HTpointer HT[HTsize];
//char ST[STsize];
//#endif // !__SYMTABLE_TYPES__



//#ifndef _SYMTABLE_
//#define _SYMTABLE_
//
//extern int nextid = 0;  //the current identifier
//extern int nextfree = 0;  //the next available index of ST
//extern int hashcode;  //hash code of identifier
//extern int sameid;  //first index of identifier
//
//extern int found;  //for the previous occurrence of an identifie
//
//#endif // !_SYMTABLE_

#ifndef __YY__
#define __YY__
extern yylex();
extern char* yytext;
#endif // !__YY__


