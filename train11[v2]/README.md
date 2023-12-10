## Úkolem je navrhnout program, který zobrazí všechna dvojková čísla splňující zadané podmínky.

Vstupem programu jsou dvě celá čísla - n a k. Číslo n udává maximální počet dvojkových cifer v zápisu čísla. Číslo k určuje největší délku běhu (run) každé cifry, tj. kolikrát se nejvýše může v čísle objevit ta samá cifra za sebou jako sekvence. Např. pro k rovné 2 se mohou v zápisu čísla objevit nejvýše 2 cifry 0 za sebou (pak by již musela následovat cifra 1). To samé platí pro sekvence cifer 1.

Výstupem programu jsou všechna binární čísla o délce nejvýše n obsahující běhy nejvýše délky k. Každé takové binární číslo je zobrazeno na zvláštním řádku, čísla se nesmí opakovat. Čísla na výstupu nesmí začínat cifrou 0.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- číslo n není platné celé číslo, je nulové, záporné nebo vyšší než 64,
- číslo k není platné celé číslo, je nulové nebo záporné.

**Ukázka práce programu:**
```
Pocet cifer:
5
Max. stejnych po sobe:
1
1
10
101
1010
10101
Celkem: 5

Pocet cifer:
4
Max. stejnych po sobe:
2
1
11
110
1100
1101
10
100
1001
101
1011
1010
Celkem: 11

Pocet cifer:
12
Max. stejnych po sobe:
6
1
11
111
1111
11111
111111
1111110
11111100
111111000
1111110000
11111100000
111111000000
111111000001
11111100001
...
101010101011
101010101010
Celkem: 3903

Pocet cifer:
test
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu).
- Pro generování se vyplatí rekurze. Počet čísel ve výpisu může být vysoký. Je proto potřeba implementovat rozumně efektivní řešení, které negeneruje zbytečné kombinace, které nevedou k cíli.
- Pořadí čísel ve výpisu není určeno a může být libovolné. Testovací prostředí si před porovnáním výstupu čísla uspořádá.
