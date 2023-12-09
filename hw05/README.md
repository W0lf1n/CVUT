## Úkolem je vytvořit program, který bude pomáhat s úpravami statistiky vhodným výběrem dat.

Předpokládáme, že v e-shopu zaznamenáváme recenze našich zákazníků. Recenze přicházejí postupně. U každé recenze máme zadané datum, vlastní číselné hodnocení (celé kladné číslo) a text recenze. Data na vstupu jsou v neklesajícím pořadí, během jednoho dne ale může být zadáno více recenzí. Příkladem recenze na vstupu je:

    + 2023-11-10 10 Short_review

Zde je dne _10.11.2023_ vložena recenze s hodnocením _10_ a komentářem _Short_review_ (komentář neobsahuje bílé znaky a má délku nejvýše 4096 znaků). Další recenze musí mít datum _10.11.2023_ nebo pozdější (ne dřívější).

Při vytváření statistiky chceme najít souvislý úsek recenzí od nějakého počátečního dne do nějakého koncového dne takový, že součet hodnocení udělených v tomto období je co nejpodobnější zadané hodnotě. Tedy například pro vstup:

    ? 100
    
chceme najít neprázdný časový interval takový, aby součet hodnocení v tomto intervalu byl co nejbližší 100. Takových intervalů může existovat obecně více, například dva různé intervaly se součtem 90 a třetí se součtem 110. Pokud existuje více intervalů se stejně podobným hodnocením, budeme považovat za výsledek interval s pozdějším koncovým datem (viz druhý ukázkový běh, první dotaz). Pokud by i pro stejné koncové datum existovaly dva stejně vhodné intervaly, dáme přednost tomu intervalu s větším součtem hodnocení (druhý ukázkový běh, druhý dotaz).

Při hledání intervalu pracujeme s granularitou jednoho dne. Pokud je v počátečním/koncovém dni nalezeného intervalu zadáno více recenzí, musíme je do výsledku zahrnout všechny (nelze použít pouze některé z recenzí počátečního/koncového dne). Toto je vidět v ukázkovém běhu na dotazu _? 57_. Nalezená odpověď je 45 (celý den 11.11), přestože by blíže byl součet 60 = 45 + 15 (celý den 11.11 a část 10.11).

Na vstupu je prokládané zadávání recenzí a požadavků na vyhledání intervalu. Vyhledávání se vyhodnocuje okamžitě, tedy pracuje pouze s dosud zadanými recenzemi (je to vidět v prvním ukázkovém běhu).

Výstupem programu jsou vyhledané intervaly. Program nejprve zobrazí časový interval (počáteční datum a koncové datum), za kterým následuje součet hodnocení z tohoto intervalu. Na dalších řádcích pak program zobrazí hodnocení a komentář recenzí z nalezeného intervalu; recenze jsou zobrazené v pořadí ve kterém byly zadány na vstupu.

Vyhledávání má dvě varianty. Pro zadání typu _? 100_ chceme nalézt a vypsat časový interval, součet hodnocení, a odpovídající recenze. Pro zadání typu _# 100_ chceme nalézt a vypsat pouze časový interval a součet hodnocení (nechceme vypisovat jednotlivé recenze).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- chybný formát zadání recenze nebo chybný formát vyhledávání,
- neplatné datum v recenzi,
- datum v zadání recenze je menší než datum v předchozí recenzi,
- nečíselná, nulová nebo záporná hodnota hodnocení v recenzi (hodnocení musí být alespoň 1),
- nečíselná, nulová nebo záporná hodnota požadovaného součtu ve vyhledávání,
- pokus o vyhledávání bez dosud zadaných recenzí.
