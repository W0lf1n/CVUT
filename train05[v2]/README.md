## Úkolem je vytvořit program, který bude zpracovávat jednoduché matematické vzorce.

Na vstupu dostanete dvě desetinná čísla oddělená znakem operace a zakončená znakem rovná se. Vaším úkolem je vypočítat hodnotu podle zadaného operátoru:

- pro + určit součet,
- pro - určit rozdíl,
- pro * určit součin,
- pro / určit celočíselný podíl (např. 3.5 / 1.5 = 2, kolikrát se do dělence vejde celý dělitel).

Jiné operace program nebude umět a vypíše pro ně chybové hlášení. Formát vstupu a výstupu je vidět níže na ukázce práce programu.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- zadané číslo není validní desetinné číslo,
- dělitel je 0 pro operaci /,
- čísla nejsou oddělena validním operátorem (+, -, * nebo /),
- za posledním číslem se nenachází znak =.

**Ukázka práce programu:**
```
Zadejte vzorec:
3.5 + 1.5 =
5

Zadejte vzorec:
3.5 / 1.5 =
2

Zadejte vzorec:
1000000 * 1.5e+8 =
1.5e+14

Zadejte vzorec:
7 / -1 =
-7

Zadejte vzorec:
abc / 1 =
Nespravny vstup.

Zadejte vzorec:
4 & 10 =
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Pro reprezentaci hodnot použijte desetinná čísla typu double. Nepoužívejte typ float, jeho přesnost nemusí být dostatečná.
- Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriál (Courses -> Video tutoriály), jak testovací data použít a jak testování zautomatizovat.
- Výsledná hodnota je porovnávána jako desetinné číslo s tolerancí 1 promile.
- Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít problém).
- Slovní popis struktury platných vstupních dat není zcela exaktní. Proto připojujeme i formální popis vstupního jazyka v EBNF:
```
    input      ::= { whiteSpace } decimal { whiteSpace } op { whiteSpace } decimal { whiteSpace } '='
    whiteSpace ::= ' ' | '\t' | '\n' | '\r'
    decimal    ::= [ '+' | '-' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ] |
                   [ '+' | '-'  ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
    integer    ::= digit { digit }
    digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
    op         ::= '+' | '-' | '*' | '/'
```
