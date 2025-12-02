grammar AudioScore;

// Programa completo:
//  - Cero o más patterns
//  - Cero o más statements sueltos (notas, silencios, loops, play, tempo)
program
    : (patternDecl | statement)* EOF
    ;

// tempo 100;
tempoStmt
    : 'tempo' INT ';'
    ;

// pattern intro { ... }
patternDecl
    : 'pattern' ID '{' statement* '}'
    ;

// Statements que se pueden anidar dentro de patterns, loops o a nivel superior
statement
    : noteStmt ';'
    | restStmt ';'
    | tempoStmt            // tempo también se permite en medio de la canción
    | loopStmt
    | playStmt ';'
    ;

// loop 2 { ... }
loopStmt
    : 'loop' INT '{' statement* '}'
    ;

// play intro;
playStmt
    : 'play' ID
    ;

// ====== Sentencias base ======

noteStmt
    : NOTE INT DUR          // Ahora la octava es un INT, no un token OCTAVE
    ;

restStmt
    : 'rest' DUR
    ;

// ====== Tokens ======

NOTE
    : [A-G] [#b]?        // C, D#, Eb, etc. (simplificado)
    ;

DUR
    : [qhe]              // q = quarter, h = half, e = eighth
    ;

INT
    : [0-9]+
    ;

// Identificador para nombres de patrones: intro, coro, etc.
// *** Importante: empieza en minúscula para no capturar notas como C o G ***
ID
    : [a-z_][a-zA-Z_0-9]*
    ;

WS
    : [ \t\r\n]+ -> skip
    ;
