## Úkolem je vytvořit program, který bude generovat silná kouzla.

Na vstupu programu je seznam slov. Slova jsou tvořena libovolnými znaky, bílé znaky jsou oddělovače slov. Zadávání slov skončí po dosažení konce vstupu (EOF).

Úkolem programu je změnit pořadí slov na vstupu tak, aby slova tvořila co nejsilnější kouzlo. Síla kouzla se určí tak, že se vezmou všechna slova kouzla a vynechají se bílé znaky a všechna písmena kouzla se změní na malá. Kouzlo je tím silnější, čím je větší takto vzniklý řetězec (lexikograficky větší). Například slova Lorem ipSum dolOR lze uspořádat následujícími způsoby:
```
Lorem ipSum dolOR  => loremipsumdolor
Lorem dolOR ipSum  => loremdoloripsum
ipSum dolOR Lorem  => ipsumdolorlorem
ipSum Lorem dolOR  => ipsumloremdolor
dolOR Lorem ipSum  => dolorloremipsum
dolOR ipSum Lorem  => doloripsumlorem
```
a z nich je nejsilnější (lexikograficky největší) varianta loremipsumdolor, tedy odpovědí je Lorem ipSum dolOR.

Výstupem programu je nalezená kombinace slov tvořící nejsilnější kouzlo. Pokud je stejně silných kombinací více, bude upřednostněna taková kombinace slov, kde delší slova předcházejí kratší slova. To je vidět v ukázkovém běhu číslo 3. Výstup bude navíc úhledně zformátován:

slova budou oddělena právě jednou mezerou,
před prvním a za posledním slovem nebude žádný zbytečný bílý znak navíc,
řádka výstupu bude co nejdelší, ale nepřekročí 80 znaků (včetně mezer),
pokud je nějaké slovo delší než 80 znaků, bude celé zobrazeno na jedné samostatné řádce.
Pokud je vstup neplatný, program to musí detekovat, zobrazit chybové hlášení a ukončit se. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

na vstupu není zadané žádné slovo,
stejné slovo je na vstupu zadané vícekrát (nerozlišujeme malá/velká písmena).

**Ukázka práce programu:**
```
Slova:
Lorem ipsum dolor sit amet consectetur adipiscing elit
sed do eiusmod tempor incididunt ut labore et dolore
magna aliqua
ut tempor sit sed magna Lorem labore ipsum incididunt et elit eiusmod dolore
dolor do consectetur amet aliqua adipiscing
Slova:
ab        a				aab 	 	 aaab
ab aab aaab a
Slova:
ba bba b BBBBBba bBBb cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
bBBb b BBBBBba bba ba
Slova:
aaa AaA
Nespravny vstup.
```

**Poznámky:**
- V ukázkovém běhu programu jsou vizuálně odlišené uživatelské vstupy (standardní font) a výpisy programu (tučné písmo). Toto rozlišení je použité pouze zde na WWW stránce zadání problému, aby se výpis snáze četl. Realizovaný program musí zobrazovat text bez dalších úprav (nepoužívá žádný markup), viz též přiložené soubory.
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- V programu používejte prostředky jazyka C, nepoužívejte C++ (STL) ani std::string.
- Vstupní slova mohou být dlouhá.
- Řešení této úlohy, které projde všemi závaznými a nepovinnými testy na 100%, může být použito pro code review (pro code review není požadované zvládnutí testu rychlosti).
