// Copyright 2012 the V8 project authors. All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//     * Neither the name of Google Inc. nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/*
* This file is used for holding the reserved keywords and tokens 
* for Cobra.
*/

#ifndef TOKENS_H_
#define TOKENS_H_

enum TOK{
	// Reserved Words
	IMPORT = 256,
	INCLUDE,
	MACRO,
	VAR,
	RETURN,
	IF,
	ELSE,
	NULL_LITERAL, 
	TRUE_LITERAL,
	FALSE_LITERAL,
	FOR,
	DO,
	WHILE,
	EACH,
	NEW,
	THIS,
	STRICT,
	TRY,
	CATCH,
	FINALLY,
	THROW,

	// Logic
	LESS = 300,
	GREATER,
	LESS_EQUALS,
	GREATER_EQUALS,
	NOT_EQUALS,
	EQUALS,
	DOUBLE_EQUALS,
	OR,
	NOT,
	AND,
	MOD,

	// Operators
	PLUS = 400,
	DOUBLE_PLUS,
	MINUS,
	DOUBLE_MINUS,
	TIMES,
	DIVIDE,

	// Punctuators and objects
	LPAREN = 500,
	RPAREN,
	LBRACE,
	RBRACE,
	LBRACKET,
	RBRACKET,
	STATIC,
	CONSTRUCTOR,
	PROTOTYPE,
	GLOBAL,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	ESCAPE,
	CLOSE_DOUBLE_COMMENT,
	OPEN_DOUBLE_COMMENT,
	SINGLE_COMMENT,

	// Punctuators
	COMMA = 600,
	PERIOD,
	SEMI,
	COLON,

	// Internal
	EOF_LITERAL = 2000,
	ID, // Identifier
	RETURN_NUM,
	RETURN_STR	
};

#endif // TOKENS_H_