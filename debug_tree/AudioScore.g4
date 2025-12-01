grammar AudioScore;

program
    : tempoDecl? statement* EOF
    ;

tempoDecl
    : 'tempo' INT ';'
    ;

statement
    : noteStmt ';'
    | restStmt ';'
    ;

noteStmt
    : NOTE OCTAVE DUR
    ;

restStmt
    : 'rest' DUR
    ;

// ----- Tokens -----

NOTE
    : [A-G] [#b]?        // C, D#, Eb, etc. (simplificado)
    ;

OCTAVE
    : [0-8]
    ;

DUR
    : [qhe]              // q = quarter, h = half, e = eighth
    ;

INT
    : [0-9]+
    ;

WS
    : [ \t\r\n]+ -> skip
    ;
