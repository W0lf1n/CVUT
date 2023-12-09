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

**Ukázka práce programu:**
```
Recenze:
+ 2023-11-10 10 Short_review
+ 2023-11-10 53 Long_review
+ 2023-11-10 15 Negative_review
+ 2023-11-11 45 Some_text
+ 2023-11-16 42 Useless_comment
+ 2023-11-16 98 Fake_review
? 100
2023-11-10 - 2023-11-10: 78
  10: Short_review
  53: Long_review
  15: Negative_review
? 42
2023-11-11 - 2023-11-11: 45
  45: Some_text
? 57
2023-11-11 - 2023-11-11: 45
  45: Some_text
? 140
2023-11-16 - 2023-11-16: 140
  42: Useless_comment
  98: Fake_review
? 200
2023-11-11 - 2023-11-16: 185
  45: Some_text
  42: Useless_comment
  98: Fake_review
# 2000
2023-11-10 - 2023-11-16: 263
# 10
2023-11-11 - 2023-11-11: 45
+ 2023-11-16 15 Updated_review
+ 2023-11-17 1000 Sponsored
? 200
2023-11-11 - 2023-11-16: 200
  45: Some_text
  42: Useless_comment
  98: Fake_review
  15: Updated_review
# 2000
2023-11-10 - 2023-11-17: 1278

Recenze:
+ 2023-11-10 10 Short_review
+ 2023-11-10 20 Short_review
+ 2023-11-11 10 Short_review
+ 2023-11-11 10 Short_review
+ 2023-11-12 10 Short_review
? 30
2023-11-11 - 2023-11-12: 30
  10: Short_review
  10: Short_review
  10: Short_review
+ 2023-11-15 8 Short_review
+ 2023-11-16 100 Short_review
+ 2023-11-16 200 Short_review
? 304
2023-11-15 - 2023-11-16: 308
  8: Short_review
  100: Short_review
  200: Short_review

Recenze:
+ 2023-11-10 10 A_review_with_long_text
? 20
2023-11-10 - 2023-11-10: 10
  10: A_review_with_long_text
+ 2023-11-09 10 A_review_with_short_text
Nespravny vstup.

Recenze:
+ 2000-02-29 10 Review_#1
+ 2004-02-29 10 Review_#2
+ 2020-02-29 10 Review_#3
? 20
2004-02-29 - 2020-02-29: 20
  10: Review_#2
  10: Review_#3
+ 2023-02-28 10 Review_#4
? 20
2020-02-29 - 2023-02-28: 20
  10: Review_#3
  10: Review_#4
+ 2023-02-29 10 Review
Nespravny vstup.

Recenze:
+ 2100-02-29 10 Review_#1
Nespravny vstup.

Recenze:
+ 2000-02-29 0 Review_#1
Nespravny vstup.
```

**Poznámky:**
- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Pro rozhodování o platných datech použijte platná pravidla Gregoriánského kalendáře. Na vstupu jsou zadávané roky v rozumném rozsahu (1800 - 3000).
- Výsledný interval musí obsahovat alespoň jednu recenzi. Proto je v prvním ukázkovém běhu pro zadání # 10 výsledkem interval se součtem hodnocení 45. Prázdný interval se součtem hodnocení 0 by byl hodnotě 10 blíže, ale datum od/do by nebylo jednoznačné.
- Pro nalezený interval požadujeme, aby první i poslední den intervalu obsahoval nějakou recenzi. Například pro první ukázkový běh a dotaz ? 100 je odpověď 2023-11-10 - 2023-11-10: 78. Stejný součet hodnocení má ale i interval 2023-11-09 - 2023-11-10: 78 a další s menším počátečním datem. Aby odpověď byla jednoznačná, požadujeme v odpovědi interval takový, který má první i poslední den nějakou recenzi.
- Úloha nabízí bonusový test pro algoritmicky efektivní řešení. Body navíc dostane řešení, které dokáže rychle zpracovat dotazy pro dlouhé seznamy recenzí. V testech rychlosti jsou zadávané převážně dotazy typu # (výpis recenzí velmi zdržuje).
- Řešení této úlohy, které projde všemi závaznými a nepovinnými testy na 100%, může být použito pro code review (pro code review není požadované zvládnutí testu rychlosti).
