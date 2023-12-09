## Úkolem je realizovat program, který bude rozhodovat o možnostech přestupu mezi vlaky na nádraží.

Předpokládáme, že na nádraží jezdí za den právě 3 vlaky - vlak A, B a C. Vlaky jezdí denně, přijíždějí a odjíždějí vždy ve stejný čas. Pro každý vlak známe hodinu a minutu příjezdu a odjezdu. Úkolem programu je rozhodnout, mezi kterými vlaky lze přestoupit. Z vlaku X lze přestoupit do vlaku Y pokud vlak Y odjíždí alespoň 5 minut po příjezdu vlaku X (5 minut je na přestup). Dále, přestoupit můžeme pouze tehdy, pokud od příjezdu X do příjezdu Y jsou nejvýše 3 hodiny včetně. Pokud by vlak Y přijel později, zdrželi bychom se na nástupišti déle než 3 hodiny a byli bychom z nádraží vykázáni jako potenciální bezdomovci. Oba limity (5 min, 3h) jsou brané včetně, je to i demonstrováno v ukázkách níže.

Vstupem programu je 6 časových údajů o příjezdech a odjezdech vlaků, každý údaj je tvořen hodinou a minutou. Hodiny a minuty jsou oddělené dvojtečkou.

Výstupem programu je rozhodnutí, mezi kterými vlaky lze přestupovat. Odpovědi jsou postupně pro vlaky A, B a C, každá na zvláštním řádku. Formát výstupu je zřejmý z ukázek níže. Pokud lze přestupovat na více vlaků, jsou vlaky, na které lze přestoupit, uvedeny abecedně:

    Z vlaku B lze prestoupit na vlaky A a C.

Naopak, následující odpověď by byla vyhodnocena jako nesprávná:

    Z vlaku B lze prestoupit na vlaky C a A.

Nezapomeňte na odřádkování za každou (tedy i poslední) řádkou výpisu.
Pokud vstup není platný (na vstupu jsou nečíselné nebo nesmyslné hodnoty), program tuto situaci detekuje a vypíše chybové hlášení. Formát chybového hlášení je opět uveden v ukázkách níže. Za chybu je považováno, pokud je na vstupu:

- nečíselná hodnota,
- chybějící oddělovač (dvojtečka) nebo
- nesmyslná hodnota (hodnota mimo rozsah 0-23, resp. 0-59).

Pokud program detekuje chybu, přestane se dotazovat na další vstupní hodnoty, vypíše chybové hlášení a ukončí se. Chybu je tedy potřeba detekovat okamžitě po načtení hodnoty (neodkládejte kontrolu vstupních údajů až za načtení celého vstupu). Chybové hlášení vypisujte na standardní výstup (nevypisujte jej na standardní chybový výstup).

**Ukázka práce programu:**
```
Cas prijezdu vlaku A:
12:00
Cas odjezdu vlaku A:
12:30
Cas prijezdu vlaku B:
12:10
Cas odjezdu vlaku B:
12:20
Cas prijezdu vlaku C:
12:40
Cas odjezdu vlaku C:
13:00
Z vlaku A lze prestoupit na vlaky B a C.
Z vlaku B lze prestoupit na vlaky A a C.
Z vlaku C nelze prestupovat.

Cas prijezdu vlaku A:
10:00
Cas odjezdu vlaku A:
10:10
Cas prijezdu vlaku B:
10:05
Cas odjezdu vlaku B:
10:15
Cas prijezdu vlaku C:
10:06
Cas odjezdu vlaku C:
10:16
Z vlaku A lze prestoupit na vlaky B a C.
Z vlaku B lze prestoupit na vlaky A a C.
Z vlaku C lze prestoupit na vlak B.

Cas prijezdu vlaku A:
10:00
Cas odjezdu vlaku A:
10:30
Cas prijezdu vlaku B:
13:00
Cas odjezdu vlaku B:
13:10
Cas prijezdu vlaku C:
13:01
Cas odjezdu vlaku C:
14:00
Z vlaku A lze prestoupit na vlak B.
Z vlaku B lze prestoupit na vlak C.
Z vlaku C lze prestoupit na vlak B.

Cas prijezdu vlaku A:
23:00
Cas odjezdu vlaku A:
23:30
Cas prijezdu vlaku B:
23:50
Cas odjezdu vlaku B:
0:15
Cas prijezdu vlaku C:
0:10
Cas odjezdu vlaku C:
0:45
Z vlaku A lze prestoupit na vlaky B a C.
Z vlaku B lze prestoupit na vlak C.
Z vlaku C lze prestoupit na vlak B.

Cas prijezdu vlaku A:
12:00
Cas odjezdu vlaku A:
12:65
Nespravny vstup.

Cas prijezdu vlaku A:
12:00
Cas odjezdu vlaku A:
12:abc
Nespravny vstup.
```

**Poznámky:**
- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
- Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
