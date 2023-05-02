﻿/*
* tn.h–token type
* progrmmer– 김정원, 이소현, 정지현, 하민지
* date - 05/03/2023
*/

enum tnumber {
	TEOF, TERROR,
	TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE,
	TPLUS, TMINUS, TSTAR, TSLASH, TMOD,
	TASSIGN, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN,
	TNOT, TAND, TOR,
	TEQUAL, TNOTEQU, TLESS, TGREAT, TLESSE, TGREATE,
	TINC, TDEC,
	TLPAREN, TRPAREN, TCOMMA, TLBRACE, TRBRACE, TLBRACKET, TRBRACKET, TSEMI,
	TIDENT, TNUMBER,
	TDOT, TCOMMENT
};
