## Úkolem je vytvořit program, který pro čtveřici bodů v rovině rozhodne, zda tvoří obdélník.

Vstupem programu je čtveřice bodů v rovině. Každý bod je tedy zadán jako dvojice **celých** čísel - souřadnice **x** a **y**. Pořadí bodů na vstupu respektuje pořadí bodů na obvodu zadávaného obdélníku. Pokud jsou body zadané proházeně, program je vyhodnotí tak, že netvoří obdélník (viz předposlední ukázka).

Výstupem programu je rozhodnutí, zda zadané body tvoří obdélník nebo ne. Pokud body tvoří čtverec, považuje to program rovněž za obdélník (je to speciální případ obdélníku). Za výpisem (formát viz ukázka) je znak odřádkování (\n).

Program musí být schopen detekovat nesprávný vstup. Pokud je na vstupu nesmyslné zadání, program to zjistí, vypíše chybové hlášení a ukončí se. Formát chybového hlášení je uveden v ukázce níže. Pozor, za případným chybovým hlášením je odřádkování (\n). Chybová hlášení zasílejte na standardní výstup **(printf)**, nezasílejte jej na chybový výstup. Za chybu je považováno:

- nečíselná hodnota souřadnice,
- chybějící/nesprávný oddělovač (závorka, čárka) nebo
- chybějící souřadnice.

Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriály (courses -> videotutoriály -> Testování), jak testovací data použít a jak testování zautomatizovat.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít problém).

**Ukázka práce programu:**
```
Bod #1:
(0,0)
Bod #2:
(20,0)
Bod #3:
(20,50)
Bod #4:
(0,50)
Body tvori obdelnik.

Bod #1:
 (0,-4)
Bod #2:
(4, 0)
Bod #3:
(0, 4)
Bod #4:
(-4, 0)
Body tvori obdelnik.

Bod #1:
(0, -4)
Bod #2:
(4, 0)
Bod #3:
(0, 4)
Bod #4:
(-6, 0)
Body netvori obdelnik.

Bod #1:
(0, 0)
Bod #2:
(20, 0)
Bod #3:
(0, 50)
Bod #4:
(20, 50)
Body netvori obdelnik.

Bod #1:
(1416, 6069)
Bod #2:
(163, 2428)
Bod #3:
(1372, 8041)
Bod #4:
(1566, 4009)
Body netvori obdelnik.

Bod #1:
(50, 50)
Bod #2:
(35, test)
Nespravny vstup.

Bod #1:
10,20
Nespravny vstup.
```

**Poznámky:**
- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Tato úloha je zjednodušená, vstupní souřadnice jsou celá čísla. Doporučujeme začít řešit tuto úlohu a následně program upravit tak, aby dokázal zpracovávat i desetinná čísla v obtížnější variantě.
