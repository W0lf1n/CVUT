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

**Ukázka práce programu:**
```
Zadejte rovnici:
3.5 + 1.5 = 5
Rovnice je spravne.

Zadejte rovnici:
3.5 / 1.5 = 2
Rovnice je spravne.

Zadejte rovnici:
8 / -1 = -8
Rovnice je spravne.

Zadejte rovnici:
1.44 + 12.25 = 13.69
Rovnice je spravne.

Zadejte rovnici:
1.44 + 2.55 = 4
3.99 != 4

Zadejte rovnici:
abc / 1 = 2
Nespravny vstup.

Zadejte rovnici:
4 & 10 = 1
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Pro reprezentaci hodnot použijte desetinná čísla typu double. Nepoužívejte typ float, jeho přesnost nemusí být dostatečná.
- Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriál (Courses -> Video tutoriály), jak testovací data použít a jak testování zautomatizovat.
- Porovnání musí respektovat dosažitelnou přesnost datového typu double. Vzhledem k jednoduchým výpočtům lze uvažovat cca 12-14 platných cifer výsledku.
- Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít problém).
- Slovní popis struktury platných vstupních dat není zcela exaktní. Proto připojujeme i formální popis vstupního jazyka v EBNF:

    input      ::= { whiteSpace } formula { whiteSpace } '=' { whiteSpace } decimal { whiteSpace }
    formula    ::= decimal { whiteSpace } op { whiteSpace } decimal
    whiteSpace ::= ' ' | '\t' | '\n' | '\r'
    decimal    ::= [ '+' | '-' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ] |
                   [ '+' | '-'  ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
    integer    ::= digit { digit }
    digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
    op         ::= '+' | '-' | '*' | '/' 
