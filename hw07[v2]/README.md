## Úkolem je vytvořit program, který bude navrhovat převodovky.

Předpokládáme, že máme hotové převodovky, pro které známe jejich převodový poměr. Převodový poměr je dán počtem zubů ozubených kol, počet zubů musí být v intervalu 10 až 1000 včetně. Převodovka s převodovým poměrem např. 13:17 může být použita jak pro zvýšení počtu otáček (13:17), tak pro snížení počtu otáček (17:13).

Program následně dostane za úkol zkombinovat zadané převodovky tak, aby co nejpřesněji dosáhl zadaného převodového poměru. Pokud má program na vstupu převodovky např.:

```
+ 13:17
+ 15:12
+ 11:24
+ 18:16
+ 27:47
```

a má je sestavit do převodového poměru 30:11, pak může zkombinovat převodovky 15:12 a 24:11 (použije se opačně, než je zadaná) a dosáhne přesně zadaného poměru. Pro jiný požadovaný převodový poměr, např. pro 75:14, se nepodaří zadané převodovky zkombinovat tak, aby poměr vyšel přesně. V takovém případě program nalezne kombinaci převodovek, které se od požadovaného poměru liší co nejméně. O porovnání poměrů je více v poznámkách dole.

Na vstupu jsou nejprve zadané jednotlivé převodovky. Zadání má obecný tvar + X:Y, kde X a Y jsou počty zubů ozubených kol. Po zadání převodovek následuje zadání problémů k vyřešení. Problém je zadaný obecně jako ? X:Y, kde X:Y je požadovaný převodový poměr. Zadávání převodovek a problémů k vyřešení není prokládané, tj., po zadání prvního problému k vyřešení již není zadávaná žádná další převodovka.

Výstupem programu je zobrazení nalezeného (nejbližšího) převodového poměru pro každý vstupní požadavek. Po zobrazení nalezeného poměru následuje seznam použitých převodovek, kterými lze tento poměr dosáhnout. Pro některé vstupy může existovat více stejně správných řešení. V takovém případě je akceptováno libovolné takové (správné) řešení. Pro některé požadavky může být nejlepším výsledkem převodový poměr 1:1. Pro takový výsledek je seznam převodovek prázdný (viz ukázka).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- chybný formát zadání převodovky (chybí oddělovač nebo číslo),
- počet zubů v zadání převodovky je mimo limit (ozubené kolo v zadání převodovky musí mít nejméně 10 a nejvýše 1000 zubů),
- chybný formát zadání problému (chybí oddělovač nebo číslo),
- nesmyslný požadovaný převodový poměr (záporné nebo nulové číslo v požadovaném převodovém poměru). Na čísla v převodovém poměru se nevztahují omezení na počty zubů, tedy např. převodový poměr 1:5000 je platný vstup,
- na vstupu jsou promíchaná zadání převodovek a problémů k vyřešení (je přidána další převodovka po zadání prvního problému k vyřešení).
- Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Řešený problém je poměrně komplikovaný z hlediska času potřebného pro výpočet. Očekává se základní řešení, které postupně zkusí všechny možnosti kombinace převodovek. Testovaných kombinací může být velmi mnoho, je proto potřeba rozumně efektivní implementace.

**Ukázka práce programu:**
```
Prevody:
+ 13:17
+ 15:12
+ 11:24
+ 18:16
+ 27:47
? 1:428
572:3995 = [13:17] * [12:15] * [11:24] * [16:18] * [27:47]
? 30:11
30:11 = [15:12] * [24:11]
? 75:14
235:44 = [15:12] * [24:11] * [18:16] * [47:27]
? 1:2
3159:6392 = [13:17] * [18:16] * [27:47]

Prevody:
+ 13:17
+ 15:12
+ 11:24
+ 18:16
+ 27:47
+ 20:50
+ 40:50
? 1:2
1:2 = [20:50] * [50:40]
? 5:4
5:4 = [50:40]
? 15:4
702:187 = [13:17] * [24:11] * [18:16] * [50:20] * [40:50]
? 33:64
33:64 = [11:24] * [18:16]

Prevody:
+ 10:1000
+ 27:590
+ 59:730
+ 365:23
+ 460:67
? 27:67
27:67 = [27:590] * [59:730] * [365:23] * [460:67]
? 67:27
67:27 = [590:27] * [730:59] * [23:365] * [67:460]

Prevody:
+ 12:19
+ 19:12
? 144:361
144:361 = [12:19] * [12:19]

Prevody:
+ 500:10
? 3:1
1:1
? 1:3
1:1

Prevody:
+ 1000:10
+ 100:10
? 10:1
10:1 = [100:10]
? 1:10
1:10 = [10:100]
? 31:1
10:1 = [100:10]
? 1:31
1:10 = [10:100]
? 3162:100
10:1 = [100:10]
? 100:3162
1:10 = [10:100]
? 3163:100
100:1 = [1000:10]
? 100:3163
1:100 = [10:1000]
? 32:1
100:1 = [1000:10]
? 1:32
1:100 = [10:1000]
? 73:1
100:1 = [1000:10]
? 1:73
1:100 = [10:1000]

Prevody:
+ 24:46
+ 24:46
+ 36:69
? 23:12
23:12 = [69:36]

Prevody:
? 5:2
1:1

Prevody:
+ 13*18
Nespravny vstup.

Prevody:
+ 13:18
+ 13:18
? 15:12
18:13 = [18:13]
+ 21:16
Nespravny vstup.
```

**Poznámky:**
- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Na vstupu je zadáváno nejvýše 50 převodovek.
- Převodové poměry reprezentujte jako celá čísla typu long long (64 bitová). Menší typ (32 bitový int) velmi snadno přeteče. Velkou péči je potřeba věnovat správnému porovnání převodového poměru. Pro snazší porovnání použjte desetinná čísla typu double. Mějme zadaný problém z ukázky, kde je k dispozici převodovka s poměrem 500:10 a chceme nalézt řešení pro převodový poměr 1:3 (=0.33333...). Buď zvolíme převodovku v režimu 10:500 (=0.02), nebo nepoužijeme žádnou převodovku a poměr bude 1:1 (=1.0). Prostým porovnáním čísel zjistíme, k požadovanému poměru 0.33333... má blíže číslo 0.02 (převodovka 10:500, otáčky se sníží 50x, tedy budou 50/3=16.6666...x nižší) než číslo 1.0 (bez převodovky, otáčky budou jen 3x vyšší než požadované). Proto prosté porovnání převodových poměrů nestačí a je potřeba poměry porovávat následujícím postupem:
  - testovaný převodový poměr a vydělit požadovaným převodovým poměrem x, tj. určit podíl a / x. Pokud podíl vyjde menší než 1, nahradit jej převrácenou hodnotou, tj. x / a. Pro ideální shodu tak bude podíl roven 1 a bude tím větší, čím více se nalezený převodový poměr liší od požadavku,
  - použít dosud nejlepší nalezený převodový poměr b a vydělit jej požadovaným převodovým poměrem x, tj. určit podíl b / x. Pokud podíl vyjde menší než 1, nahradit jej převrácenou hodnotou x / b,
  - pokud je podíl z bodu (1) menší (tj. blíže hodnotě 1) než podíl z bodu (2), je převodový poměr a výhodnější než dosud nejlepší nalezený převodový poměr b.
- Řešení této úlohy, které projde všemi závaznými a nepovinnými testy na 100%, může být použito pro code review.
