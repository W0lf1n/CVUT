## Úkolem je realizovat program, který zobrazí na obrazovce šachovnici.

Vstupem programu jsou dvě celá čísla - velikost šachovnice (počet políček na šířku a výšku) a velikost políčka (počet znaků na výšku a šířku jednoho políčka).

Výstupem programu je zobrazená šachovnice. Šachovnice bude tvořena znaky mezera (bílá pole) a znakem X (černá pole). Celá šachovnice bude orámovaná. V levém horním rohu bude umístěno vždy pole bílé. Šachovnice je čtvercová (počet políček je stejný v obou směrech), políčka jsou rovněž čtvercová (počet znaků na políčko je shodný v obou směrech).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- na vstupu nejsou dvě platná celá čísla,
- čísla na vstupu jsou záporná nebo nulová.

**Ukázka práce programu:**
```
Zadejte pocet poli:
5
Zadejte velikost pole:
3
+---------------+
|   XXX   XXX   |
|   XXX   XXX   |
|   XXX   XXX   |
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|   XXX   XXX   |
|   XXX   XXX   |
|   XXX   XXX   |
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|XXX   XXX   XXX|
|   XXX   XXX   |
|   XXX   XXX   |
|   XXX   XXX   |
+---------------+

Zadejte pocet poli:
8
Zadejte velikost pole:
4
+--------------------------------+
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|    XXXX    XXXX    XXXX    XXXX|
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
|XXXX    XXXX    XXXX    XXXX    |
+--------------------------------+

Zadejte pocet poli:
2
Zadejte velikost pole:
0
Nespravny vstup.

Zadejte pocet poli:
asdf
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriál (Courses -> Video tutoriály), jak testovací data použít a jak testování zautomatizovat.
- Výstup programu může být velmi široký/dlouhý, vyplatí se výstup přesměrovat do souboru a ten si prohlížet v nějakém editoru.
