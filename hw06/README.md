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


