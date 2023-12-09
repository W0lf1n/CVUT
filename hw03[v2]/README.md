**Úkolem je realizovat funkci (ne celý program, pouze funkci), která bude počítat trojúhelníky. Předpokládejme trojúhelníky, které mají celočíselné délky stran. Funkce bude počítat, kolik existuje trojúhelníků, které mají délky stran v zadaném uzavřeném intervalu hodnot (od - do). Dále půjde omezit tvar počítaných trojúhelníků (ostroúhlé, pravoúhlé, tupoúhlé a jejich kombinace). Požadovaná funkce bude mít následující rozhraní:**

    int countTriangles ( int lo, int hi, int filter )

funkce vypočte počet trojúhelníků s celočíselnými délkami stran, kde délky stran počítaných trojúhelníků patří do uzavřeného intervalu lo až hi (první a druhý parametr funkce) a tvar počítaných trojúhelníků je omezený hodnotou parametru filter.
Parametr filter omezuje možné tvary započtených trojúhelníků. Jeho hodnotou je nějaká z konstant TRIANG_xxx, případně jejich kombinace. Například TRIANG_ACUTE započítává pouze ostroúhlé trojúhelníky, TRIANG_ACUTE | TRIANG_RIGHT započítává ostroúhlé a pravoúhlé trojúhelníky. Definované konstanty TRIANG_xxx lze v parametru libovolně kombinovat pomocí operátoru bitové nebo (kolmítko).

Návratovou hodnotou funkce je počet nalezených trojúhelníků, které splňují zadaná omezení. Funkce vrátí hodnotu -1, pokud jsou zadané nesmyslné hodnoty parametrů (nulové nebo záporné meze, neplatný interval, nesprávný filtr).

    TRIANG_ACUTE

je konstanta definovaná v testovacím prostředí. Její použití přidá do výběru ostroúhlé trojúhelníky.

    TRIANG_RIGHT

je konstanta definovaná v testovacím prostředí. Její použití přidá do výběru pravoúhlé trojúhelníky.

    TRIANG_OBTUSE

je konstanta definovaná v testovacím prostředí. Její použití přidá do výběru tupoúhlé trojúhelníky.

    TRIANG_DUPLICATES

je konstanta definovaná v testovacím prostředí, která řídí započítávání shodných trojúhelníků:
- pokud TRIANG_DUPLICATES není zahrnutá ve filtru, rozlišujeme při výpočtu pouze tvarově odlišné trojúhelníky. Tedy například trojúhelníky se stranami 3,4,5 a 6,8,10 jsou považované za dva různé trojúhelníky, ale trojúhelníky se stranami 3,4,5 a 4,5,3 jsou považované za identické, tedy do výsledku jsou započtené jako jeden trojúhelník.
- pokud TRIANG_DUPLICATES je zahrnutá ve filtru, rozlišujeme všechny trojúhelníky včetně pořadí jejich stran. Tedy například trojúhelníky se stranami 3,4,5 a 4,5,3 jsou považované za odlišné a každý z nich bude zahrnut do výsledku.
Odevzdávejte zdrojový soubor, který obsahuje implementaci požadované funkce countTriangles. Do zdrojového souboru přidejte i další Vaše podpůrné funkce, které jsou z ní volané. Funkce countTriangles bude volaná z testovacího prostředí, je proto důležité přesně dodržet zadané rozhraní funkce. Za základ pro implementaci použijte kód z přiloženého souboru. V kódu chybí vyplnit tělo požadované funkce (a případné další podpůrné funkce). Ukázka obsahuje testovací funkci main, uvedené hodnoty jsou použité při základním testu. Všimněte si, že vkládání hlavičkových souborů a funkce main jsou zabalené v bloku podmíněného překladu (#ifdef/#endif). Prosím, ponechte bloky podmíněného překladu i v odevzdávaném zdrojovém souboru. Podmíněný překlad Vám zjednoduší práci. Při kompilaci na Vašem počítači můžete program normálně spouštět a testovat. Při kompilaci na Progtestu funkce main a vkládání hlavičkových souborů "zmizí", tedy nebude kolidovat s hlavičkovými soubory a funkcí main testovacího prostředí.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Rozumná implementace naivního algoritmu by měla projít všemi testy kromě testu rychlosti. Pro zvládnutí testu rychlosti je potřeba použít výkonnější algoritmus, který zbytečně netestuje všechny možné trojúhelníky.

**Nápověda:**
Jako základ Vašeho řešení použijte zdrojový kód z přiloženého souboru.
Do funkce main si můžete doplnit i další Vaše testy, případně ji můžete libovolně změnit. Důležité je zachovat podmíněný překlad.
V ukázce je použito makro assert. Pokud je parametrem nenulová hodnota, makro nedělá nic. Pokud je parametrem nepravda (nula), makro ukončí program a vypíše řádku, kde k selhání došlo. Pokud tedy Vaše implementace projde ukázkovými testy, program doběhne a nic nezobrazí.
Pro práci s parametrem filter se velmi hodí bitové operátory. Nemáte-li v nich jasno, projděte si je znovu. Řešení bez bitových operátorů jsou zbytečně těžkopádná. Rozmyslete si, jak se kombinace symbolických konstant projeví ve dvojkovém zápisu hodnoty.
Pozor, volba TRIANG_DUPLICATES je trochu chyták. Její použití nezpůsobí pouze vynásobení výsledku hodnotou 6.
