## Úkolem je vytvořit program, který bude zobrazovat vybrané citáty.

Vstupem programu je jedno celé číslo. Toto číslo je z rozsahu 0 až 8 a určuje citát, který má být zobrazen.

Výstupem programu je citát odpovídající zadanému číslu na vstupu. Citáty odpovídající jednotlivým číslům jsou uvedené v ukázkových bězích programu níže. Pozor, za textem citátu je odřádkování (\n).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

    - ze vstupu nelze přečíst celé číslo,
    - číslo přečtené ze vstupu je mimo interval 0 až 8.

Povšimněte si, že program zobrazuje různá chybová hlášení. První chybové hlášení se uplatní, pokud program nemůže ze vstupu přečíst platné celé číslo. Druhé chybové hlášení se pak použije, pokud je načtené číslo mimo rozsah

**Ukázka práce programu:**
```
ml' nob:
0
Qapla'
noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.

ml' nob:
1
Qapla'
bortaS bIr jablu'DI' reH QaQqu' nay'.

ml' nob:
2
Qapla'
Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.

ml' nob:
3
Qapla'
bISeH'eghlaH'be'chugh latlh Dara'laH'be'.

ml' nob:
4
Qapla'
qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.

ml' nob:
5
Qapla'
Suvlu'taHvIS yapbe' HoS neH.

ml' nob:
6
Qapla'
Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.

ml' nob:
007
Qapla'
Heghlu'meH QaQ jajvam.

ml' nob:
           8
Qapla'
leghlaHchu'be'chugh mIn lo'laHbe' taj jej.

ml' nob:
29
Qih mi' 29

ml' nob:
-5
Qih mi' -5

ml' nob:
abc
Neh mi'
```

**Poznámky:**
- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
- Výzvy programu a citáty jsou úmyslně zvoleny tak, aby bylo obtížné je ručně opisovat. Úloha se Vás snaží mj. naučit efektivní práci s počítačem, tedy např. s funkcemi copy & paste (které bohužel někteří studenti neznají nebo neumějí použít). Vyzkoušejte si a naučte se copy & paste jak pod Windows tak pod UNIXem (Linuxem), u závěrečného testu se to bude hodit!
- Ruční kontrola shody Vašeho a referenčního výstupu je nudná, člověk při porovnávání často přehlédne drobný rozdíl. Obzvláště to platí u textu v úloze, který pro většinu lidí není srozumitelný. Toto je opět záměr. Využijte volna na začátku semestru a naučte se v této jednoduché úloze efektivně testovat Vaše programy. Podívejte se na zmíněný videotutoriál (courses -> výuková videa) a využijte pro porovnání Váš počítač. V dalších úlohách tím ušetříte mnoho času.
- Vstup typu 1.23 případně 1abcd není správný. Jeho ošetření je ale pracnější. Program proto můžete realizovat v jednodušší podobě, která takový vstup akceptuje jako číslo 1. Takový program bude hodnocen nominálním počtem bodů (100 %). Pro zájemce je k dispozici bonusový test, který zkouší zadávat právě tento typ vstupů. Pokud správně ošetříte i tento typ chyb, bude váš program hodnocen body navíc. Ukázka práce programu pro tento typ vstupu:
```
ml' nob:
1.23
bIjatlh 'e' yImev
```
