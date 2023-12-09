## Úkolem je realizovat sadu funkcí pro práci s řídkými maticemi. Řídká matice je taková matice, která má nastaveno pouze málo hodnot (např. pouze 1 %) a ostatní hodnoty nejsou nastavené (nenastavené hodnoty jsou typicky považované za 0). Proto se ji vyplatí ukládat jinak než 2D polem. Naše řídká matice bude realizovaná pomocí spojových seznamů.

Vlastní matice je realizovaná strukturou TSPARSEMATRIX. V této struktuře jsou odkazy na dva jednosměrně zřetězené spojové seznamy existujících (neprázdných) řádek a sloupců. Spojový seznam řádek (sloupců) je realizován pomocí struktur TROWCOL. Prvkem spojového seznamu je popis řádky matice (sloupce matice), ve kterém je alespoň jeden obsazený prvek. Řádky (sloupce) v seznamu jsou uspořádané podle rostoucího indexu. Ve struktuře TROWCOL je pak ukazatel m_Cells na jednotlivé prvky obsažené v dané řádce (sloupci).

Struktura TCELL popisuje jeden prvek matice. Obsahuje pozici (řádek, sloupec), hodnotu a dva ukazatele na další prvky: další prvek na řádce a další prvek ve sloupci. Prvky v řádcích (sloupcích) jsou uspořádané vzestupně podle svých sloupcových (řádkových) indexů. Následující obrázek zachycuje řídkou matici, ve které byly zadané prvky:
```
m[0, 1] = 10
m[1, 0] = 20
m[1, 5] = 30
m[2, 1] = 40
```

**TSPARSEMATRIX**
tato datová struktura je deklarovaná v testovacím prostředí. Vaše implementace bude s touto strukturou pracovat, ale nesmí jí nijak měnit. Struktura reprezentuje celou matici, má následující složky:
- m_Rows - ukazatel na počátek spojového seznamu existujících řádek matice,
- m_Cols - ukazatel na počátek spojového seznamu existujících sloupců matice.

**TROWCOL**
tato datová struktura je deklarovaná v testovacím prostředí. Vaše implementace bude s touto strukturou pracovat, ale nesmí jí nijak měnit. Struktura reprezentuje spojový seznam popisující existující řádek nebo sloupec matice, má následující složky:
- m_Next - ukazatel na další řádek/sloupec matice, nullptr pro poslední existující řádek (sloupec),
- m_Idx - index řádku (sloupce),
- m_Cells - ukazatel na počátek spojového seznamu prvků matice, které patří do popisovaného řádku (sloupce). Protože ve spojovém seznamu máme pouze existující řádky (sloupce) matice, nebude hodnota m_Cells nikdy rovná nullptr.

**TCELL**
tato datová struktura je deklarovaná v testovacím prostředí. Vaše implementace bude s touto strukturou pracovat, ale nesmí jí nijak měnit. Struktura reprezentuje jeden prvek matice, má následující složky:
- m_Right - ukazatel na další prvek matice ve stejném řádku (a vyšším sloupci), nullptr pro poslední prvek na řádce,
- m_Down - ukazatel na další prvek matice ve stejném sloupci (a vyšším řádku), nullptr pro poslední prvek ve sloupci,
- m_Row - index řádku,
- m_Col - index sloupce,
- m_Value - hodnota prvku matice.

**initMatrix ( m )**
funkce inicializuje prázdnou matici - efektivně nastaví spojové seznamy řádek a sloupců na hodnoty nullptr.

**addSetCell ( m, row, col, value )**
funkce přidá do matice prvek na zadané řádce a sloupci (row, col) a vyplní jej hodnotou value. Pokud prvek již v matici existoval, pouze nastaví jeho novou hodnotu. Pokud prvek na pozici row, col ještě neexistoval, funkce jej vytvoří, vyplní a správně začlení do spojových seznamů.

**removeCell ( m, row, col )**
funkce odstraní z matice prvek na zadané řádce a sloupci (row, col). Pokud prvek v matici neexistoval, funkce vrátí false a nechá matici beze změny. Pokud prvek existoval, funkce jej z matice odstraní, upraví odpovídající spojové seznamy a vrátí true. Pozor, pokud odstraňujete poslední prvek na řádce (ve sloupci), je potřeba upravit i spojové seznamy existujících řádků (sloupců).

**freeMatrix ( m )**
funkce k uvolnění prostředků alokovaných v matici.

Odevzdávejte zdrojový soubor, který obsahuje implementaci požadovaných funkcí. Do zdrojového souboru přidejte i další Vaše podpůrné funkce, které jsou z nich volané. Implementované funkce budou volané z testovacího prostředí, je proto důležité přesně dodržet zadané rozhraní funkcí. Za základ pro implementaci použijte kód z přiloženého souboru. V kódu chybí vyplnit těla požadovaných funkcí (a případné další podpůrné funkce). Ukázka obsahuje testovací funkci main, uvedené hodnoty jsou použité při základním testu. Všimněte si, že vkládání hlavičkových souborů a funkce main jsou zabalené v bloku podmíněného překladu (#ifdef/#endif). Prosím, ponechte bloky podmíněného překladu i v odevzdávaném zdrojovém souboru. Podmíněný překlad Vám zjednoduší práci. Při kompilaci na Vašem počítači můžete program normálně spouštět a testovat. Při kompilaci na Progtestu funkce main a vkládání hlavičkových souborů "zmizí", tedy nebude kolidovat s hlavičkovými soubory a funkcí main testovacího prostředí.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Rozumná implementace naivního algoritmu by měla projít všemi testy.

**Nápověda:**
- Jako základ Vašeho řešení použijte zdrojový kód z přiloženého souboru.
- Do funkce main si můžete doplnit i další Vaše testy, případně ji můžete libovolně změnit. Důležité je zachovat podmíněný překlad.
- V ukázce je použito makro assert. Pokud je parametrem nenulová hodnota, makro nedělá nic. Pokud je parametrem nepravda (nula), makro ukončí program a vypíše řádku, kde k selhání došlo. Pokud tedy Vaše implementace projde ukázkovými testy, program doběhne a nic nezobrazí.
- Řešení této úlohy nelze použít pro code review.
