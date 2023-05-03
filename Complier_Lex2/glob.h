/*
* glob.h–global variable for the project
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/
//TODO: 필요없는거 삭제하기
#include <stdio.h>
#include <stdlib.h>

#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z' || (x) == '_') )
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

#define STsize 10  //size of string table
#define HTsize 100	//size of hash table

#define MAX_LEN		12

#define FALSE 0
#define TRUE 1



#ifndef _LINENUM_
#define _LINENUM_
extern int line_num; //count line numbers in scanner.l
#endif // !_LINENUM_

#ifndef _ERRORTYPES_
#define _ERRORTYPES_
enum errorTypes { illid_digit, illid_long, illid_illch, overst };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;
#endif // !_ERRORTYPES_


#ifndef __SYMTABLE_TYPES__
#define __SYMTABLE_TYPES__
typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;  //index of identifier in ST
	HTpointer next;  //pointer to next identifier
} HTentry;

HTpointer HT[HTsize];
char ST[STsize];
#endif // !__SYMTABLE_TYPES__



#ifndef _SYMTABLE_
#define _SYMTABLE_

int nextid;  //the current identifier
int nextfree;  //the next available index of ST
int hashcode;  //hash code of identifier
int sameid;  //first index of identifier

int found;  //for the previous occurrence of an identifie

#endif // !_SYMTABLE_


#ifndef __YY__
#define __YY__
yylex();
char* yytext;
#endif // !__YY__


extern int cErrors; //count the number of errors
