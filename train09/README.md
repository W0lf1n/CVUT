Během náročné distanční výuky bylo rozhodnuto, že komunikace mezi studenty a učiteli musí být zabezpečena proti nežádoucím elementům. Proto bylo vyhlášeno výběrové řízení na novou šifru, kterou odteď budou všichni používat.

Šifra samotná je velmi komplexní a její vytvoření stálo jistě nemalé množství úsilí (a peněz z kapes daňových poplatníků). Princip spočívá v naXORování tajného klíče na jednotlivé pozice zašifrovaného textu.

Vaším úkolem je vytvořit funkci (či sadu funkcí), které umožní obsah zpráv číst.

Funkce decrypt dešifruje tajnou zprávu a vrátí seznam slov ze zprávy.

Parametry funkce jsou:

    char ** decrypt (const char * key, const char * str);

- key - šifrovací klíč. Klíč se cyklicky opakuje až do konce zprávy. Tedy pro zprávu dlouhou 26 znaků a klíč <3progtest bude dešifrovací klíč vypadat <3progtest<3progtest<3prog. Tento parametr je const, tedy funkce jej může pouze číst.
- str - zašifrovaná data, pro která má dojít k rozšifrování. Původní (nezašifrovaný) text je ukončen binární nulou (\0), tato binární nula se šifrováním změní na jiný znak. Abyste správně poznali konec textu, musíte šifrovaná data průběžně dešifrovat (XORovat) klíčem a kontrolovat, zda jste rozšifrováním nedostali znak ‘\0’. Parametr str je const, tedy funkce jej může pouze číst.
- Návratovou hodnotou funkce je pole řetězců se slovy. Poslední ukazatel v poli je nastaven na hodnotu NULL. Vrácené pole a všechny řetězce v něm obsažené musí být dynamicky alokované (malloc, calloc nebo realloc). Volající řetězce použije a po jejich použití je uvolní z paměti (zavolá funkci destroyLogs).
- V případě chybných parametrů nebo neplatného obsahu vrací funkce NULL.

Za chybu je považováno:

- NULL v prvním či druhém argumentu,
- klíč je prázdný řetězec (nulová délka),
- dva a více po sobě jdoucích bílých znaků v rozšifrovaném textu.

Ukázka použití funkcí je v přiloženém archivu.

**Poznámky:**

- Maximální délka řádky není omezena. Řetězce nelze rozumně realizovat pomocí polí fixní délky.
- Počet slov v textu není explicitně omezen. Vracené pole řetězců nelze rozumně realizovat s fixní délkou.
- Při dělení slov podle bílých znaků se vám může hodit funkce isspace z knihovny ctype.h
- Při zpracování dat je potřeba rozumně efektivní implementace. Pokud byste potřebovali zvětšovat velikost nějakého dynamicky alokovaného pole, nezvětšujte jej po jednotlivých prvcích.
- Při implementaci používejte prostředky jazyka C. C++ knihovna STL je pro tuto úlohu úmyslně vyřazena.
- Rozšifrovaný text nesmí obsahovat dvojici po sobě jdoucích bílých znaků. To neomezuje jednotlivé bílé znaky na začátku nebo na konci textu. Tedy jeden bílý znak může být i na začátku/konci/obou stranách rozšifrovaného textu.
- Popsaná šifra je jednou z variant Vigenèrovy šifry. Na svou dobu to byl poměrně silný kryptografický nástroj. Šifra byla prolomena až ve druhé polovině 19 století.
