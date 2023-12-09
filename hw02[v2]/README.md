## Úkolem je vytvořit program, který bude počítat velikost krabice potřebné pro zabalení výrobků.

Předpokládáme, že vyrábíme výrobky různých druhů. Výrobky jsou ve tvaru kvádru, každý druh výrobku může mít různou velikost. Výrobky expedujeme zabalené v krabicích. V krabici jsou vždy výrobky stejného druhu. Chceme, aby výrobky uložené v krabici zabraly celý vnitřní prostor bez mezer. Dále chceme, aby krabice byla tvaru krychle a chceme mít krabice pouze jedné velikosti pro zabalení libovolného druhu výrobku. Tedy pokud vyrábíme výrobky typu A a B, musí mít krabice takovou velikost, aby ji šlo bez mezer vyplnit výrobky typu A a zároveň ji musí jít bez mezer vyplnit výrobky typu B. Úkolem je určit nejmenší možnou velikost takové krabice pro zadané velikosti výrobků.

Vstupem programu jsou velikosti vyráběných výrobků. Zadávána jsou vždy tři desetinná čísla udávající rozměry jednoho výrobku. Desetinné číslo je zadáno na dvě desetinná místa a je v rozsahu 0.01 až 10000000.00 včetně. Na vstupu jsou postupně zadány rozměry všech vyráběných výrobků. Zadávání končí v okamžiku, kdy je signalizován EOF.

Výstupem programu je vypočtená velikost krabice. Výstup je zobrazen na dvě desetinná místa ve formátu podle ukázky. Pokud vypočtený rozměr krabice přesáhne hodnotu 10000000.00, program zobrazí informaci o příliš velké krabici (přesný formát je opět v ukázce). Pozor, za výpisem je odřádkování (\n).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- nebyly zadané žádné výrobky,
- pro výrobek nebyla zadaná tři čísla,
- rozměr byl zadaný jako nečíselný,
- rozměr nebyl z rozsahu 0.01 až 10000000.00.

Program by dále měl kontrolovat, že rozměry jsou zadané jako desetinná čísla na dvě desetinná místa. Tento test je náročnější, proto není v základní verzi požadovaný (v základní verzi se zadávají desetinná čísla vždy na dvě desetinná místa). Úloha nabízí bonusový (nepovinný test). V tomto bonusovém testu jsou zadávána i desetinná čísla s menším/větším počtem desetinných míst, která by program měl vyhodnotit jako nesprávné vstupy. Pokud program upravíte, aby zvládl i tento test, dostanete body navíc.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít problém).

**Ukázka práce programu:**
```
Velikost vyrobku:
1.00 2.00 3.00
4.00 5.00 6.00
Velikost krabice: 60.00

Velikost vyrobku:
6.40 2.56 7.20
8.10 3.48 2.16
Velikost krabice: 30067.20

Velikost vyrobku:
6.00 6.00 6.00
12.00 3.00 9.00
1.00 1.00 1.00
Velikost krabice: 36.00

Velikost vyrobku:
0.03 0.07 0.05
0.10 0.63 0.25
0.28 0.34 0.15
0.16 0.09 0.15
0.24 0.11 0.81
Velikost krabice: 424116.00

Velikost vyrobku:
331.00 337.00 281.00
Krabice je prilis velka.

Velikost vyrobku:
8342345.00 2422411.00 9234421.00
Krabice je prilis velka.

Velikost vyrobku:
1.00 2.00 -28.00
Nespravny vstup.

Velikost vyrobku:
22.00 64.00 15732438.00
Nespravny vstup.

Velikost vyrobku:
331.00 337.00 281.00
2.00 3.15 abcd
Nespravny vstup.
```

**Poznámky:**
- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Při programování si dejte pozor na rozsah použitých datových typů.
- Informaci o rozměru/překročení velikosti zobrazujte až po přečtení celého vstupu. I pokud je aktuální rozměr větší než mez, dokončete načítání a kontrolu vstupu a teprve pak zobrazte výsledek (mohl by přijít nesprávný vstup, viz poslední ukázkový běh).
