## Úkolem je vytvořit program, který bude řešit logickou hru - odebírání žetonů.

Hru hrají dva hráči A a B. Na stole je v řade umístěno 1 až 100 žetonů. Každý žeton má na sobě napsanou hodnotu, hodnota je celé číslo (kladná, nulová nebo záporná). Hráči se střídají, začíná hráč A. Hráč na tahu si může vzít dle své volby 1 až 2 žetony. Navíc hráč nesmí odebírat dva žetony ve dvou po sobě jdoucích tazích (pokud si hráč v jednom tahu vezme dva žetony, ve svém následujícím tahu si musí vzít pouze jeden žeton). Žetony lze odebírat pouze ze začátku nebo z konce řady. Pokud hráč odebírá dva žetony ze stejného konce řady, je nutné nejprve odebrat žeton krajní a teprve pak žeton takto zpřístupněný. Hra končí v okamžiku, kdy jeden z hráčů odebere poslední žeton. Vyhrává ten hráč, který získal větší součet hodnot svých žetonů.

Předpokládáme, že oba hráči hrají absolutně efektivně. Tedy každý z hráčů odebírá žetony tak, aby získal co nejvyšší součet svých žetonů. Úkolem je nalézt posloupnost těchto efektivních tahů a určit, kdo vyhraje.

Vstupem programu je posloupnost celých čísel. Tato čísla představují hodnoty žetonů tak, jak jsou vedle sebe na stole. Při odebírání se na žetony odkazujeme jejich indexem (0 až počet-1).

Výstupem programu je nalezená posloupnost tahů jednotlivých hráčů. Každý tah je na samostatné řádce. Tahy jsou vždy uvozené identifikací hráče (A nebo B, střídají se) následuje index odebraného žetonu (index může být jeden nebo dva podle počtu odebíraných žetonů) a končí hodnotou (hodnotami) odebíraných žetonů. Poslední řádkou výstupu je informace o součtech žetonů obou hráčů.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Po detekování chyby se program ukončí. Za chybu považujte:

byla zadaná prázdná posloupnost žetonů nebo žetonů bylo více než 100,
hodnota žetonu není celé číslo.

**Ukázka práce programu:**
```
Zetony:
100 100 100 100 100 100
A [0]: 100
B [1]: 100
A [2]: 100
B [5], [4]: 100 + 100
A [3]: 100
A: 300, B: 300

Zetony:
3 5 3 6 1
A [0]: 3
B [1], [2]: 5 + 3
A [4], [3]: 1 + 6
A: 10, B: 8

Zetony:
-11 5 3 6 -1
A [4]: -1
B [3], [2]: 6 + 3
A [1]: 5
B [0]: -11
A: 4, B: -2

Zetony:
1 5 3 6 2 1 8 2 3
A [0], [1]: 1 + 5
B [8]: 3
A [2]: 3
B [7], [6]: 2 + 8
A [3], [4]: 6 + 2
B [5]: 1
A: 17, B: 14

Zetony:
-57 87 -75 117 44 96
A [5]: 96
B [4], [3]: 44 + 117
A [0], [1]: -57 + 87
B [2]: -75
A: 126, B: 86

Zetony:
73 -7 118 86 11 -11 83
A [6]: 83
B [0]: 73
A [1], [2]: -7 + 118
B [3], [4]: 86 + 11
A [5]: -11
A: 183, B: 170

Zetony:
-34 -1 94 111 43 78 -79 13
A [0], [7]: -34 + 13
B [6], [5]: -79 + 78
A [1]: -1
B [2]: 94
A [4], [3]: 43 + 111
A: 132, B: 93

Zetony:
-72 36 -2 42 139 116 -59 -31 -34
A [8], [7]: -34 + -31
B [6]: -59
A [5]: 116
B [4]: 139
A [3]: 42
B [2], [1]: -2 + 36
A [0]: -72
A: 21, B: 114

Zetony:
131 8 97 -68 -79 135 -93 -61 -4 -61
A [0], [9]: 131 + -61
B [1], [2]: 8 + 97
A [8]: -4
B [3]: -68
A [4], [5]: -79 + 135
B [7]: -61
A [6]: -93
A: 29, B: -24

Zetony:
32 119 7 -34 -21 92 -73 92 76 -45 90
A [0], [1]: 32 + 119
B [10], [9]: 90 + -45
A [2]: 7
B [8]: 76
A [7]: 92
B [6], [5]: -73 + 92
A [4]: -21
B [3]: -34
A: 229, B: 106

Zetony:
2 62 132 25 71 9 52 44 58 15 58 -65
A [11], [10]: -65 + 58
B [0]: 2
A [1]: 62
B [2]: 132
A [3], [4]: 25 + 71
B [9], [8]: 15 + 58
A [5]: 9
B [6]: 52
A [7]: 44
A: 204, B: 259

Zetony:
140 -63 11 -18 138 -10 0 -74 138 146 43 116 -62
A [0]: 140
B [12], [11]: -62 + 116
A [10]: 43
B [9]: 146
A [8]: 138
B [1]: -63
A [7]: -74
B [2]: 11
A [3], [4]: -18 + 138
B [6]: 0
A [5]: -10
A: 357, B: 148

Zetony:
127 62 -84 138 141 96 101 42 -29 140 44 9 -6 130
A [0], [13]: 127 + 130
B [1]: 62
A [12]: -6
B [11], [10]: 9 + 44
A [9], [8]: 140 + -29
B [7]: 42
A [6]: 101
B [5], [4]: 96 + 141
A [3]: 138
B [2]: -84
A: 601, B: 310

Zetony:
-92 92 80 47 6 60 86 -82 -86 93 75 -69 -24 -81 71
A [14]: 71
B [13], [12]: -81 + -24
A [11]: -69
B [10]: 75
A [9]: 93
B [0], [1]: -92 + 92
A [2]: 80
B [3]: 47
A [8]: -86
B [7], [6]: -82 + 86
A [5], [4]: 60 + 6
A: 155, B: 21

Zetony:
hello
Nespravny vstup.
```

**Poznámky:**
- V ukázkovém běhu programu jsou vizuálně odlišené uživatelské vstupy (standardní font) a výpisy programu (tučné písmo). Toto rozlišení je použité pouze zde na WWW stránce zadání problému, aby se výpis snáze četl. Realizovaný program musí zobrazovat text bez dalších úprav (nepoužívá žádný markup), viz též přiložené soubory.
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Při řešení je potřeba projít všechny kombinace, kterými mohou hráči táhnout. Pro takový postup se nejlépe hodí rekurze.
- Pro některé vstupy lze ke správnému výsledku dojít více způsoby - součet žetonů hráčů je stejný, ale tahy byly zkombinované jinak. Testovací prostředí uzná každý platný postup, který dosáhne správného výsledku.
- Počet vyvolání rekurzivní funkce může být velmi vysoký. Funkci je proto potřeba implementovat rozumně efektivně.
- Procházení všech možností je velmi zdlouhavé. Pokud je implementovaná základní podoba algoritmu, lze program efektivně testovat pro vstupní sekvence do délky cca 20 žetonů.
- Bonusový test zkouší efektivitu použitého algoritmu, zadává delší vstupy (až 100 žetonů). Pro zvládnutí bonusového testu je potřeba efektivní algoritmus, který neopakuje dříve provedené rekurzivní výpočty. Tato technika se nazývá dynamické programování.
- Řešení této úlohy, které projde všemi závaznými a nepovinnými testy na 100%, může být použito pro code review (pro code review není požadované zvládnutí testu rychlosti).
