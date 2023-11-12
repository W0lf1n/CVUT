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
