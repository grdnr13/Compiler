%{
/* scanner.l-lexical analyzer for the MiniC
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
%}

letter [a-zA-Z_]
digit [0-9]

%%


"const"		return(TCONST);
"else"		return(TELSE);
"if"		return(TIF);
"int"		return(TINT);
"return"	return(TRETURN);
"void"		return(TVOID);
"while"		return(TWHILE);

"+"		return(TPLUS);
"-"		return(TMINUS);
"*"		return(TSTAR);
"/"		return(TSLASH);
"%"		return(TMOD);

"="		return(TASSIGN);
"+="		return(TADDASSIGN);
"-="		return(TSUBASSIGN);
"*="		return(TMULASSIGN);
"/="		return(TDIVASSIGN);
"%="		return(TMODASSIGN);

"!"		return(TNOT);
"&&"		return(TAND);
"||"		return(TOR);

"=="		return(TEQUAL);
"!="		return(TNOTEQU);
"<"		return(TLESS);
">"		return(TGREAT);
"<="		return(TLESSE);
">="		return(TGREATE);

"++"		return(TINC);
"--"		return(TDEC);

"("		return(TLPAREN);
")"		return(TRPAREN);
","		return(TCOMMA);
"{"		return(TLBRACE);
"}"		return(TRBRACE);
"["		return(TLBRACKET);
"]"		return(TRBRACKET);
";"		return(TSEMI);


{letter}({letter}|{digit})* 		{
						if(yyleng > 12)
						{ err = illid_long; PrintError(err); return(TERROR);}
						else
						{ SymbolTable(); return(TIDENT);}
					}

[1-9]{digit}*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);

{digit}+({letter}|{digit}|"_")+		{ err = illid_digit; PrintError(err); return(TERROR);}


"/*"([^*]|\*+[^*/])*\**"*/"	{
					int i;
					for(i = 0; i < yyleng; i++)
                                        	if(yytext[i] == '\n')line_num++;
					return (TCOMMENT);
				}

"//".*			return(TCOMMENT);
[ \t]			;
[\n]		{line_num++;}
.		return(TDOT);


%%
int yywrap()
{
	printf("   End of Lex Team5 \n");
	return 1;
}

