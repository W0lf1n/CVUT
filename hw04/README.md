## Úkolem je realizovat funkci (ne celý program, pouze funkci), která bude počítat velikost území, které může ovládat vhodně umístěný hrad.

Předpokládáme mapu čtvercového tvaru. Mapa je rozdělena na n x n čtverců, pro každý čtverec známe jeho nadmořskou výšku. Předpokládáme, že čtverce jsou vodorovné, ke změně nadmořské výšky dochází skokově na jejich hranici. Na libovolný čtverec lze umístit hrad, hrad zabírá vždy jeden celý čtverec. Hrad ovládá území obdélníkového tvaru, pro ovládané území musí platit:

- hrad je uvnitř obdélníku ovládaného území,
- hrad je umístěn v nejvyšším bodě ovládaného území, tj. všechny ostatní čtverce v ovládaném území mají nižší nadmořskou výšku,
- hrad se snaží ovládnout co největší území.

Úkolem je realizovat funkci castleArea. Tato funkce dostane parametrem mapu s nadmořskými výškami (2D pole) a rozměr mapy. Funkce pro každý čtverec mapy vypočte, jak velké území by ovládal hrad umístěný na daném místě.

    void castleArea ( int altitude[][MAP_MAX], int size, int area[][MAP_MAX] )

Funkce pro výpočet velikosti ovládaného území. Parametry jsou:
- altitude vstupní parametr - 2D pole s vyplněnými nadmořskými výškami. Pole má vyplněné prvky [0][0] až [size-1][size-1]. Nadmořské výšky jsou určené pouze ke čtení, funkce obsah pole nesmí měnit.
- size - velikost zpracovávané mapy. Mapa je čtvercového tvaru size x size.
- area výstupní parametr, do prvku area[y][x] umístí funkce maximální velikost území, které by ovládal hrad na pozici [y][x]. Funkce bude vyplňovat pouze prvky [0][0] až [size-1][size-1].

    bool identicalMap ( int a[][MAP_MAX], int b[][MAP_MAX], int size )

Funkce pro porovnání obsahu dvou map. Tato funkce není volána z testovacího prostředí, ale je potřeba ji implementovat pro správnou funkci dodaných testů. Funkce porovná 2D pole a a b. Porovnává se pouze výřez těchto polí [0][0] až [size-1][size-1]. Funkce vrátí true pokud pole mají v tomto výřezu stejný obsah nebo false, pokud se obsahy výřezů liší.

    constexpr int MAP_MAX = 200;

je symbolická konstanta deklarovaná v testovacím prostředí. Udává maximální velikost zpracovávané mapy.

**Příklad:**
Ukázková data alt1 obsahují mapu velikosti 4x4 s nadmořskými výškami:

    alt1:
     2, 7, 1, 9 
     3, 5, 0, 2 
     1, 6, 3, 5 
     1, 2, 2, 8 

Pro tuto mapu funkce vypočte výsledek:

    area1:
     1, 12, 2, 16
     4, 4, 1, 2
     1, 9, 4, 4
     1, 2, 1, 12

Pokud umístíme hrad na pozici [0][0], pak bude ovládat pouze sám sebe (area[0][0] = 1). Hrad na pozici [0][1] s nadmořskou výškou 7 může ovládat obdélník [0][0] - [3][2] o velikosti 4x3=12 čtverců, tedy area[0][1] = 12. Hrad na pozici [0][2] ovládá obdélník [0][2] - [1][2], tedy area[0][2] = 2.

Odevzdávejte zdrojový soubor, který obsahuje implementaci požadované funkce castleArea. Do zdrojového souboru přidejte i další Vaše podpůrné funkce, které jsou z nich volané. Funkce bude volaná z testovacího prostředí, je proto důležité přesně dodržet zadané rozhraní funkce. Za základ pro implementaci použijte kód z přiloženého souboru. V kódu chybí vyplnit těla funkcí (a případné další podpůrné funkce). Ukázka obsahuje testovací funkci main, uvedené hodnoty jsou použité při základním testu. Všimněte si, že vkládání hlavičkových souborů a funkce main jsou zabalené v bloku podmíněného překladu (#ifdef/#endif). Prosím, ponechte bloky podmíněného překladu i v odevzdávaném zdrojovém souboru. Podmíněný překlad Vám zjednoduší práci. Při kompilaci na Vašem počítači můžete program normálně spouštět a testovat. Při kompilaci na Progtestu funkce main a vkládání hlavičkových souborů "zmizí", tedy nebude kolidovat s hlavičkovými soubory a funkcí main testovacího prostředí.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Hodnocení úlohy záleží na efektivitě implementovaného algoritmu:

- Naivní řešení se složitostí n8 projde základní testy, ale nezvládne ani první test rychlosti (n udává rozměry mapy). Takové řešení bude hodnoceno méně než 100% bodů.
- Prvním testem rychlosti projde řešení založené na algoritmu se složitostí n6 (nebo lepší) a má rozumně efektivní implementaci.
- Druhým testem rychlosti projde řešení založené na algoritmu se složitostí n5 (nebo lepší) a má rozumně efektivní implementaci.
- Třetím testem rychlosti projde řešení založené na algoritmu se složitostí n4 (nebo lepší) a má rozumně efektivní implementaci.
