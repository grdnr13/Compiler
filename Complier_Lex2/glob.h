/*
* glob.h–global variable for the project
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/
//TODO: 필요없는거 삭제하기
#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "testdata.txt"

#define STsize 10  //size of string table
#define HTsize 100	//size of hash table

#define FALSE 0
#define TRUE 1

//#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z' || (x) == '_') )
//#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

#define MAX_LEN		12

typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;  //index of identifier in ST
	HTpointer next;  //pointer to next identifier
} HTentry;

extern enum errorTypes { illid_digit, illid_long, illid_illch, overst };
typedef enum errorTypes ERRORtypes;

//extern char seperators[] = " .,;:?!\t\n";

extern HTpointer HT[HTsize];
extern char ST[STsize];

extern int nextid = 0;  //the current identifier
extern int nextfree = 0;  //the next available index of ST
extern int hashcode;  //hash code of identifier
extern int sameid;  //first index of identifier

extern int found;  //for the previous occurrence of an identifie

extern ERRORtypes err;

//extern FILE* fp;   //to be a pointer to FILE 
//extern char input;

extern yylex();
extern char* yytext;

extern line_num = 0; //count line numbers in scanner.l
