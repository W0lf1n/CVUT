Po sériích globálních pandemií v Evropě, krachu mezinárodní burzy a invazi mimozemské rasy se poctiví občané Nového evropského císařství rozhodli zavést nový druh voleb. V těchto volbách občané volí, která strana si zaslouží odměnit. Z každé strany se tak zvolí několik jedinců, kteří půjdou /za odměnu/ pracovat na rok do uranových dolů Zážeh (dřívější Zábřeh). Díky této pozitivní motivaci se snížila v tomto postapokalyptickém císařství korupce na minimum.

Vaším cílem je implementovat aplikaci, která pomocí **D’Hondtovy metody** rozdělí místa v uranovém dole mezi jednotlivé strany.

Na vstupu dostanete:

- N počet stran (celé číslo v rozmezí 2 až 26), každá strana je reprezentována pro jednoduchost jedním znakem anglické abecedy (A - Z),
- na dalších N řádcích dostanete dvojici znak (identifikátor strany) a počet hlasů (kladné celé číslo),
- vstup končí počtem rozdělovaných míst.

Vaším úkolem je vypočítat přiřazení míst pomocí D’Hondtovy metody jednotlivým stranám a vypsat je. D’Hondtova metoda přiřazuje jednotlivá místa stranám postupně. V každém kroku najde stranu s největší preferencí a tato strana obdrží 1 místo, zároveň se sníží preference dané strany. Preference strany je definována jako pocet hlasu / ( 1 + pocet mist ), pokud strana žádné místo ještě nemá, pak je preference pocet hlasu / 1.42.

|             | **Strana A** | **Strana B** | **Strana C** |
|-------------|--------------|--------------|--------------|
| Počet hlasů |	100          | 60           | 45           |
| Místo 1     |	**70.42**    | 42.25        | 31.69        |
| Místo 2     | **50**       | 42.25        | 31.69        |
| Místo 3     |	33.33        | **42.25**    | 31.69        |

Tabulka ukazuje počet hlasů jednotlivých stran. A preference strany pro každé udělované místo. Tučně je zvýrazněna vítězná strana pro dané kolo. Ve výsledku strana A získá dvě místa, strana B získá jedno místo a strana C žádné. Formát vstupu a výstupu je vidět níže na ukázce práce programu. Strany jsou ve výsledku zobrazené v pořadí podle názvu počínaje stranou A.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za nesprávný vstup považujte:

- počet stran je menší než 2 nebo větší než 26,
- název strany není velké písmeno anglické abecedy (A-Z),
- název strany není v rozmezí A až počet stran (př. 5 => E),
- duplicitní strana (př. strana A je na vstupu 2x),
- chybějící strana nebo počet hlasů,
- počet hlasů je nulový nebo záporný,
- počet míst v dolech není kladný.

**Ukázka práce programu:**
```
Pocet stran:
3
Strany a pocet hlasu:
A 100
B 60
C 45
Pocet horniku:
3
Pridelene pocty:
A: 2
B: 1
C: 0

Pocet stran:
3
Strany a pocet hlasu:
A 70
B 42
C 32
Pocet horniku:
3
Pridelene pocty:
A: 2
B: 1
C: 0

Pocet stran:
5
Strany a pocet hlasu:
C 24823
A 83647
D 20646
B 63181
E 9131
Pocet horniku:
8
Pridelene pocty:
A: 4
B: 3
C: 1
D: 0
E: 0

Pocet stran:
2
Strany a pocet hlasu:
A 10
B 10
Pocet horniku:
1
Nelze rozdelit.

Pocet stran:
2
Strany a pocet hlasu:
A 100
A 200
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu).
- Povinné a nepovinné testy nepředpokládají situaci, kdy dochází k nerozhodnému počtu preferenčních bodů a nedostatku potřebných míst. Bonusový test zkouší zda zvládáte i takové situace. V ukázkovém běhu a v přiložených testovacích datech je ukázka běhu pro situaci, kdy dojde k rovnosti (2 strany, každá 10 hlasů, jedno místo k obsazení). Tato vstupní data jsou pouze v ukázkách, při testování na Progtestu jsou ze základního testu vynechaná.
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriál (Courses -> Video tutoriály), jak testovací data použít a jak testování zautomatizovat.
- Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít problém).
