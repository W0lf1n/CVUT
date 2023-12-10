## Úkolem je realizovat program, který vyhodnotí cíle, které je možné sledovat radarem.

Vstupem programu jsou informace o možných vojenských cílech nepřítele a informace o umístění vlastních radarů. Pro cíle znáte jejich souřadnice x a y. Pro radar znáte jeho umístění (opět souřadnici x a y) a jeho dosah. Všechna čísla jsou desetinná. Úkolem je vyhodnotit, kolik cílů vidí každý z radarů.

Vstupem programu je seznam cílů a radarů. Tyto informace jsou ve vstupu libovolně promíchané. Cíl je v seznamu zadán T x y, kde x a y jsou desetinná čísla (souřadnice cíle). Radar je na vstupu zadán R x y radius, kde x a y jsou desetinná čísla (souřadnice cíle) a radius je desetinné číslo udávající dosah radaru (radar vidí pouze cíle, které jsou od něj ve vzdálenosti radius nebo menší).

Výstupem je počet cílů, které vidí jednotlivé radary. Radary jsou na výstupu zobrazené v pořadí, ve kterém byly přečtené na vstupu. Formát výstupu je zřejmý z ukázek.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- na vstupu není zadán ani cíl ani radar,
- souřadnice jsou neplatné (nejsou desetinná čísla, chybí),
- dosah radaru není desetinné číslo, chybí, je nulový nebo záporný.

**Ukázka práce programu:**
```
Seznam cilu a radaru:
T 5.0 7.0
T 6 8
T -3 2
R 2 3 5
T 4 -1
R 0 0 10
T 1 2
Pokryti:
Radar #0: 3
Radar #1: 5

Seznam cilu a radaru:
T 1 1
R 2 3 4
T 6 abcd
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Počet cílů a radarů na vstupu není omezen. Program musí přizpůsobit alokace dat podle velikosti vstupu.
- Při běhu je omezena doba běhu (zde není kritická, postačuje naivní algoritmus) a velikost alokované paměti. Velikost dostupné paměti s rezervou postačuje na uložení vstupních dat.
- Pro jednoduchost považujte za správný i vstup, ve kterém není žádný radar / žádný cíl / žádný radar ani žádný cíl.
- Pro jednoduchost nekontrolujte unikátnost souřadnic. Tedy dva cíle/dva radary/radar a cíl mohou být na stejné souřadnici.
