## Úkolem je vytvořit program, který bude počítat vzhled plochy hry hledání min (minesweeper).

Vstupem programu je hrací plocha této hry. Hrací plocha je zadaná jako obdélníkové pole vyplněné znaky hvězdička (mina) a tečka (volné pole). Pole je zadáno po řádcích, každá řádka vstupu obsahuje jednu řádku hracího pole. Zadávání hracího pole je ukončeno ve chvíli kdy skončí vstup (EOF je aktivní).

Výstupem programu je hrací pole vyplněné vypočteným počtem min, které se nacházejí v okolí políčka.

Program musí ošetřovat správnost zadávaného vstupu. Pokud vstup není platný, program tuto situaci detekuje a vypíše chybové hlášení. Formát chybového hlášení je opět uveden v ukázkách níže. Za chybu je považováno, pokud je na vstupu:

- hrací pole obsahuje jiné znaky než tečka hvězdička,
- hrací pole není obdélníkového tvaru a
- hrací pole nemá velikost alespoň 1x1.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu a dále je omezena i velikost dostupné paměti. Úloha není výpočetně náročná, je ale potřeba rozumně pracovat s pamětí. Na vstupu jsou zadávané malé i obrovské hrací plochy. Pokud hrací plochu alokujete staticky, pak buď nebudete schopni zpracovat velké vstupy, nebo neprojdete paměťovým limitem základního testu (který zadává malé vstupy, tedy citelně omezuje velikost dostupné paměti). Testovací prostředí používá paměťový debugger, aby zkontrolovalo správnou práci s pamětí. Věnujte proto péči alokaci a uvolňování paměti.

**Ukázka práce programu:**
```
Zadejte hraci plochu:
.....*....
..*..*....
.....*..*.
..*.......
Vyplnena hraci plocha:
.1112*2...
.1*13*3111
.2222*21*1
.1*1111111

Zadejte hraci plochu:
.....*....
..****....
..*..*..*.
..***..*.*
..*.***...
..***.*...
Vyplnena hraci plocha:
.1234*2...
.2****3111
.3*76*32*2
.3***54*3*
.3*8***321
.2***5*2..

Zadejte hraci plochu:
.....*....
..**A.*...
Nespravny vstup.

Zadejte hraci plochu:
.....*....
..**.*...
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Úloha neomezuje velikost vstupního pole. Statická alokace paměti proto není dobrý nápad.
- Vstup je vhodné uložit do 2D pole. Velikost pole není dopředu známá, pole budete muset "natahovat". Začněte s nějakou malou velikostí pole (např. 100), pokud by mělo dojít k vyčerpání kapacity, pole zvětšete (vhodná na to může být funkce realloc).
- Je vhodné pole zvětšovat geometrickou řadou, tedy např. 100 - 200 - 400 - 800 ...
- Nepoužívejte C++ knihovnu STL (vector, list, string, ...). Účelem je procvičit dynamickou alokaci paměti v C. STL budete používat v předmětu PA2, v PA1 je použití STL zakázané. Pokud přesto STL použijete, Váš program nepůjde přeložit.
