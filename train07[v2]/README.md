## Úkolem je realizovat funkci (ne celý program, pouze funkci), která provede cyklickou rotaci obsahu pole.

Funkce má následující rozhraní:

    void rotateArray ( int array[], int arrayLen, int rotateBy );

- array je vstupně-výstupní parametr. Odkazuje na pole, jehož prvky mají být rotovány,
- arrayLen udává počet prvků ve zpracovávaném poli,
- rotateBy určuje velikost posuvu. Hodnota 0 znamená ponechat pole beze změn. Kladná hodnota posouvá prvky směrem ke konci pole, záporná pak směrem k začátku pole. Například pro rotateBy=2 se array[0] posune do array[2], array[1] do array[3], …, array[arrayLength - 2] do array[0] a array[arrayLength-1] do array[1].
- funkce musí být rozumně efektivní, zejména v paměťových nárocích. Funkce nesmí alokovat kopii vstupního pole, na to nebude mít k dispozici dostatek paměti (k dispozici je paměť pro několik celočíselných proměnných).

Ukázka použití funkce je v přiloženém archivu.

**Poznámky:**

- Jako základ Vašeho řešení použijte zdrojový kód z přiloženého souboru.
- Do funkce main si můžete doplnit i další Vaše testy, případně ji můžete libovolně změnit. Důležité je zachovat podmíněný překlad.
- V ukázce je použito makro assert. Pokud je parametrem nenulová hodnota, makro nedělá nic. Pokud je parametrem nepravda (nula), makro ukončí program a vypíše řádku, kde k selhání došlo. Pokud tedy Vaše implementace projde ukázkovými testy, program doběhne a nic nezobrazí.
- Dostupné hlavičkové soubory jsou vidět v přiloženém vzoru. Jiné hlavičkové soubory nejsou k dispozici a nejsou ani potřeba. Nevkládejte další hlavičkové soubory pomocí #include, program skončí chybou kompilace.

- V přiloženém zdrojovém kódu chybí dvě funkce: rotateArray a identicalArrays. Druhá uvedená funkce je pomocná, porovnává obsah polí v automatizovaných testech, Předpokládáme, že implementujete obě funkce, ale testována bude pouze funkce rotateArray.
- Během testů se kontrolují paměťové nároky. Pokud alokujete příliš paměti, test paměťových nároků selže.
- V základní implementaci může být vhodné rozdělit posuvy s kladnou a zápornou hodnotou rotateBy.
- Pro zvládnutí bonusového testu je potřeba paměťově i časově efektivní algoritmus. Naivní (kvadratický) algoritmus projde všemi testy kromě testu bonusového. Pro zvládnutí bonusového testu je potřeba lineární algoritmus.
