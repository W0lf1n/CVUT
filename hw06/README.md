## Úkolem je vytvořit program, který bude vyhledávat v telefonním seznamu.

Předpokládejme telefonní seznam, kde si ke každému číslu pamatujeme i odpovídající jméno. Chceme realizovat program, který v takovém seznamu dokáže efektivně vyhledávat. Při vyhledání zadáváme buď hledané číslo, nebo hledané jméno. Navíc nemusíme jméno ani číslo zadávat celé, stačí zadat jeho předponu (prefix). Program prohledá telefonní seznam a vyhledá v něm všechny záznamy, které vyhoví zadanému kritériu.

Při zadávání předpokládáme vždy pouze číselné dotazy. Takový číselný dotaz může buď znamenat přímo prefix hledaného čísla, nebo se může jednat o jméno zadané pomocí T9 (pro vyhledání záznamů začínajících písmeny **Vagner** by byla na vstupu sekvence **824637**).

Vyhledávání bude fungovat interaktivně. Každá řádka vstupu představuje jeden pokyn pro zpracování. Pokynem je buď vložení záznamu do telefonního seznamu, nebo vyhledávání. Zadávání pokynů končí po přečtení celého vstupu (dosažení EOF). Pokyny mají podobu:

- **+ číslo** jméno Tento příkaz přidá záznam do tel. seznamu. Číslo je sekvence znaků 0 až 9, délka čísla je nejméně jedna a nejvýše 20 cifer, pozor, je potřeba správně ukládat i počáteční nuly. Jméno je libovolná sekvence malých a velkých písmen a mezer. Jméno nemůže být prázdné a nesmí začínat ani končit mezerou. Znak +, číslo a jméno na vstupní řádce jsou oddělené právě jednou mezerou.
- **? číslo** Tento příkaz prohledává telefonní seznam. Číslo je sekvence znaků 0 až 9, délka čísla je nejméně jeden znak (délka není omezená). Znak ? a číslo jsou oddělené právě jednou mezerou.

Výstupem programu je vyřešení dotazů. Pro vkládání do seznamu jsou možné 3 odpovědi:

- chyba, příkaz není správně formátovaný,
- chyba, do seznamu se vkládá záznam, který v seznamu již existuje (úplná shoda čísla i jména, včetně shody malých a velkých písmen),
- ok, záznam byl vložen do seznamu.

Pro vyhledávání jsou možné 3 druhy odpovědi:

- chyba, příkaz není správně formátovaný,
- vyhledání záznamů, které odpovídají dotazu, zobrazení vyhledaných záznamů a zobrazení počtu nalezených záznamů. Tento typ odpovědi bude použit, pokud vyhledávaní vyhovuje nejvýše 10 záznamů,
- vyhledání záznamů, které odpovídají dotazu, zobrazení počtu nalezených záznamů. Tato odpověď bude použita, pokud zadanému dotazu vyhovuje více než 10 záznamů v tel. seznamu.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Po detekování chyby program přejde na zpracování další vstupní řádky. Za chybu považujte:

- zadaný neznámý příkaz (příkaz musí začínat buď znakem + nebo znakem ?),
- u vkládání chybí číslo nebo jméno,
- u hledání chybí číslo,
- číslo není tvořeno číslicemi,
- jméno není tvořeno znaky abecedy a mezerami,
- jméno začíná nebo končí mezerou,
-chybí nebo přebývají oddělující mezery příkazu/čísla/jména,
- vkládané číslo má více než 20 cifer.

Před implementací programu si rozmyslete, jakým způsobem budete telefonní seznam reprezentovat. Počet záznamů může být vysoký, délky jmen nejsou shora omezené. Při návrhu se hodí dynamická alokace a struktury.

Vyhledávání může trvat velmi dlouho, zejména pokud je telefonní seznam dlouhý. Časové limity jsou nastavené tak, že rozumně implementovaný základní algoritmus vyhledávání projde všemi testy kromě testu bonusového. Bonusový test vyžaduje pokročilý algoritmus vyhledávání.

**Ukázka práce programu:**
```
+ 123456 Vagner Ladislav
OK
+ 987654321 Vanerka Jiri
OK
+ 824637 Vagner Jiri
OK
+ 8244278 Balik Miroslav
OK
+ 8243245 Vaclavik
OK
+ 192837 Taggart John
OK
+ 98244212 Vogel Josef
OK
? 824
123456 Vagner Ladislav
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
Celkem: 5
? 82
123456 Vagner Ladislav
987654321 Vanerka Jiri
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
Celkem: 6
? 37
Celkem: 0
+ 1000001 Vacatko
OK
+ 1000002 Vaclavek
OK
+ 1000003 Vaclavkova
OK
+ 1000006 Vagner Ladislav
OK
+ 1000007 Vacek
OK
+ 1000008 Vachek
OK
+ 1000009 Varga
OK
? 824
123456 Vagner Ladislav
824637 Vagner Jiri
8244278 Balik Miroslav
8243245 Vaclavik
192837 Taggart John
1000006 Vagner Ladislav
Celkem: 6
? 82
Celkem: 13
+ 123456 Novakova
OK
? 123
123456 Vagner Ladislav
123456 Novakova
Celkem: 2
? 123456
123456 Vagner Ladislav
123456 Novakova
Celkem: 2
? 1234567
Celkem: 0
? 10000
1000001 Vacatko
1000002 Vaclavek
1000003 Vaclavkova
1000006 Vagner Ladislav
1000007 Vacek
1000008 Vachek
1000009 Varga
Celkem: 7
+ 123456 Novakova Jana
OK
+ 234567 Novakova Jana
OK
+ 123456 Novakova Jana
Kontakt jiz existuje.
+ 123456 Novakova Jana
Kontakt jiz existuje.
+ 123456 novakova Jana
OK
? 123456
123456 Vagner Ladislav
123456 Novakova
123456 Novakova Jana
123456 novakova Jana
Celkem: 4
+ 123456 test
OK
+ 1234567 test
OK
+ 123456 testtest
OK
+ 123456 test
Kontakt jiz existuje.
+ 123456    test
Nespravny vstup.
+ 123456789012345678901234567890 foo
Nespravny vstup.
? test
Nespravny vstup.
?
Nespravny vstup.
test
Nespravny vstup.
```

**Poznámky:**
- V ukázkovém běhu programu jsou vizuálně odlišené uživatelské vstupy (standardní font) a výpisy programu (tučné písmo). Toto rozlišení je použité pouze zde na WWW stránce zadání problému, aby se výpis snáze četl. Realizovaný program musí zobrazovat text bez dalších úprav (nepoužívá žádný markup), viz též přiložené soubory.
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Pro reprezentaci tel. čísel nepoužívejte datový typ int.
- Program nelze vytvořit bez dynamické alokace paměti.
- V programu používejte prostředky jazyka C, nepoužívejte C++ (STL).
- Při načítání dat ze vstupu je potřeba rozumně efektivní implementace. Pokud byste potřebovali zvětšovat velikost nějakého dynamicky alokovaného pole, nezvětšujte jej po jednotlivých prvcích.
- Vyplatí se načítat jednotlivé řádky na vstupu a zpracovávat je jako řetězce v paměti.
- **T9 kódování** (malá i velká písmena):
```
   ABC    2
   DEF    3
   GHI    4
   JKL    5
   MNO    6
   PQRS   7
   TUV    8
   WXYZ   9
   mezera 1   
```

- Pořadí nalezených kontaktů v odpovědi programu není důležité. Testovací prostředí si pořadí odpovědí před porovnáním upraví.
- Řešení této úlohy, které projde všemi závaznými a nepovinnými testy na 100%, může být použito pro code review (pro code review není požadované zvládnutí testu rychlosti).
