Nové nařízení císaře Nového evropského císařství je skoncovat s podivným rozměňováním drobných. Dobří občané již mají plné zuby mnoha drobných ve svých krypto-peněženkách. A tak císařství zavedlo, že na každou částku musí být vráceno co nejméně FITcoinů. Což je jediná krypto-měna, která si od roku 2020 udržela svoji hodnotu.

Vaším úkolem je vytvořit pokladnu, která uživateli zobrazí, z kolika mincí se vratná částka skládá.

Na vstupu dostanete zadaný seznam aktuálně používaných mincí oddělený bílými znaky a ukončený nulou. Následně na vstupu budou zadané částky, u kterých chceme zjistit z kolika mincí se nejméně dají složit. Zadávání vstupu je ukončeno koncem vstupu (EOF). Pokud se daná částka nedá složit, vypíšete o tomto informaci a zpracování pokračuje dále. Formát vstupu a výstupu je vidět níže na ukázce práce programu.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

zadaná mince není validní kladné celé číslo,
chybí nula na konci zadávání mincí,
nebyla zadána žádná mince,
zadaná částka není validní nezáporné celé číslo.

**Ukázka práce programu:**
```
Mince:
1 2 5 10 20 50 5000 2000 1000 500 200 100 0
Castky:
1 2 3 4 5 6 7 8 9 10
= 1
= 1
= 2
= 2
= 1
= 2
= 2
= 3
= 3
= 1

Mince:
2 3 0
Castky:
1
= nema reseni
2
= 1
3
= 1
4
= 2
5
= 2

Mince:
1 23 25 0
Castky:
47
= 3
48
= 2
92
= 4
94
= 4
95
= 5

Mince:
-1 2 3 0
Nespravny vstup.

Mince:
1 2 5 10 0
Castky:
5
= 1
abc
Nespravny vstup.
```

**Poznámky:** 
- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu). - Může se zdát, že problém je vlastně triviální. Například pro nominální hodnoty 1, 2, 5, 10, … z ukázky - pro takové hodnoty stačí naivní hladové řešení. To ale neplatí v obecném případě, například pro ukázkový vstup 1, 23, 25. V obecném případě se s výhodou uplatní rekurze.
