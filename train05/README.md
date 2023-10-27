## Úkolem je vytvořit program, který bude kontrolovat jednoduché matematické rovnice.

Na vstupu dostanete jednoduchou rovnici ve tvaru a @ b = c, kde a, b a c jsou desetinná čísla a znak zavináč @ definuje aritmetickou operaci. Vaším úkolem je zjistit zda rovnice platí. Podporované operace jsou:

- + pro součet,
- - pro rozdíl,
- * pro součin,
- / pro celočíselné dělení (př. 3.5 / 1.5 = 2, kolikrát se vejde celý dělitel).

V případě rovnosti vypíšete pouze “Rovnice je spravne.”, v případě nerovnosti vypíšete levou a pravou hodnotu oddělenou posloupností znaků “!=”. Formát vstupu a výstupu je vidět níže na ukázce práce programu.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- zadané číslo není validní desetinné číslo,
- dělitel rovný 0 pro operaci /,
- čísla nejsou oddělena validním operátorem (+, -, * nebo /),
- rovnice neobsahuje znak =




Slovní popis struktury platných vstupních dat není zcela exaktní. Proto připojujeme i formální popis vstupního jazyka v EBNF:

    input      ::= { whiteSpace } formula { whiteSpace } '=' { whiteSpace } decimal { whiteSpace }
    formula    ::= decimal { whiteSpace } op { whiteSpace } decimal
    whiteSpace ::= ' ' | '\t' | '\n' | '\r'
    decimal    ::= [ '+' | '-' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ] |
                   [ '+' | '-'  ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
    integer    ::= digit { digit }
    digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
    op         ::= '+' | '-' | '*' | '/' 
