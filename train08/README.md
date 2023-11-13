## Úkolem je vytvořit program, který bude počítat vzhled plochy hry hledání min (minesweeper).

Vstupem programu je hrací plocha této hry. Hrací plocha je zadaná jako obdélníkové pole vyplněné znaky hvězdička (mina) a tečka (volné pole). Pole je zadáno po řádcích, každá řádka vstupu obsahuje jednu řádku hracího pole. Zadávání hracího pole je ukončeno ve chvíli kdy skončí vstup (EOF je aktivní).

Výstupem programu je hrací pole vyplněné vypočteným počtem min, které se nacházejí v okolí políčka.

Program musí ošetřovat správnost zadávaného vstupu. Pokud vstup není platný, program tuto situaci detekuje a vypíše chybové hlášení. Formát chybového hlášení je opět uveden v ukázkách níže. Za chybu je považováno, pokud je na vstupu:

- hrací pole obsahuje jiné znaky než tečka hvězdička,
- hrací pole není obdélníkového tvaru a
- hrací pole nemá velikost alespoň 1x1.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu a dále je omezena i velikost dostupné paměti. Úloha není výpočetně náročná, je ale potřeba rozumně pracovat s pamětí. Na vstupu jsou zadávané malé i obrovské hrací plochy. Pokud hrací plochu alokujete staticky, pak buď nebudete schopni zpracovat velké vstupy, nebo neprojdete paměťovým limitem základního testu (který zadává malé vstupy, tedy citelně omezuje velikost dostupné paměti). Testovací prostředí používá paměťový debugger, aby zkontrolovalo správnou práci s pamětí. Věnujte proto péči alokaci a uvolňování paměti.
