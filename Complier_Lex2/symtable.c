/****************************************************************************************************************

Hashtable Implementation (STsize  = 1000)
=========================================


Programmer  :   Byoungju Choi, Jihyun Park

Date		:	2023/03/30

Description :

Input	:		A file consisting of identifiers seperated by spaces,tab characters,newlines and punctuation marks.
				An identifier is a string of letters and digits,starting with a letter.

Output	:	The identifier,its index in the stringtable and whether entered or present.
			Prints error message for illegal identifier(starting with a digit, too long identifier, containing illegal characters) and overflow.
			Prints the hashtable before terminating. Simply write out hashcode and the list of identifiers
			associated with each hashcode, but only for non-empty lists.
			Finally,print out the number of characters used up in ST.

Grobal variations :
				ST - Array of string table
				HT - Array of list head of hashtable
				letters - Set of letters A..Z, a..z
				digits - Set of digits 0..9
				seperators - null , . ; : ? ! \t \n

*****************************************************************************************************************/
#include <string.h>
#include "tn.h"
#include "glob.h"


//#define MAX_LEN		12
//
//#define FALSE 0
//#define TRUE 1
//
//typedef struct HTentry* HTpointer;
//typedef struct HTentry {
//	int index;  //index of identifier in ST
//	HTpointer next;  //pointer to next identifier
//} HTentry;
//
//HTpointer HT[HTsize];
//char ST[STsize];
//


//int hashcode;  //hash code of identifier
//int sameid;  //first index of identifier
//
//int found;  //for the previous occurrence of an identifie
//
//char* yytext;

/*ReadIO 	- 	Read identifier from the input file the string table ST directly into
			ST(append it to the previous identifier).
			An identifier is a string of letters and digits, starting with a letter.
			If first letter is digit, print out error message. */
void ReadID()
{
	int count = 0;
	nextid = nextfree;
	char* input = yytext;

	//TODO: EOF처리 해줘야하나 나중에 확인하기
	ST[nextfree++] = input;
	count++;

}

/* ComputeHS 	- 	Compute the hash code of identifier by summing the ordinal values of its
					characters and then taking the sum modulo the size of HT. */
void ComputeHS(int nid, int nfree)
{
	int code, i;
	code = 0;
	for (i = nid; i < nfree - 1; i++) {
		int current = (int)ST[i];
		//If current is lowercase, convert it to uppercase
		current = (current >= 'A' && current <= 'Z' ? current - 'A' + 'a' : current);
		code += current;
	}
	hashcode = (code % HTsize)+1;
	hashcode = (hashcode == HTsize ? 0 : hashcode);
}

/*LookupHS 	-	For each identifier,Look it up in the hashtable for previous occurrence
				of the identifier.If find a match, set the found flag as true.
				Otherwise flase.
				If find a match, save the starting index of ST in same id. */
void LookupHS(int nid, int hscode)
{
	HTpointer here;
	int i, j;

	found = FALSE;
	if (HT[hscode] != NULL) {
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;

			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				int left = ST[i] >= 'A' && ST[i] <= 'Z' ? ST[i] - 'A' + 'a' : ST[i];
				int right = ST[j] >= 'A' && ST[j] <= 'Z' ? ST[j] - 'A' + 'a' : ST[j];
				if (left != right)
					found = FALSE;
				else {
					i++;
					j++;
				}
			}
			here = here->next;
		}
	}
}


/* ADDHT	-	Add a new identifier to the hash table.
			If list head ht[hashcode] is null, simply add a list element with
			starting index of the identifier in ST.
			IF list head is not a null , it adds a new identifier to the head of the chain */
void ADDHT(int hscode)
{
	HTpointer ptr;

	ptr = (HTpointer)malloc(sizeof(ptr));
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}

/* MAIN		-	Read the identifier from the file directly into ST.
			Compute its hashcode.
			Look up the idetifier in hashtable HT[hashcode]
			If matched, delete the identifier from ST and print ST-index
			of the matching identifier.
			If not matched , add a new element to the list,pointing to new identifier.
			Print the identifier,its index in ST, and whether it was entered or present.
			Print out the hashtable,and number of characters used up in ST
*/
//TODO: 함수 주석
void SymbolTable() {
	ST[nextfree++] = '\0';
	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);
	if (!found) {
		for (int i = nextid; i < nextfree - 1; i++)	ADDHT(hashcode);
	}
	else {
		nextfree = nextid;
	}
}