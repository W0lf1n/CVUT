## Úkolem je realizovat program, který dokáže vyřešit hlavolam kakuro.

Vstupem programu je zadání hlavolamu. Hlavolam je zadaný jako obdélníková matice políček, políčka jsou na vstupu zadávaná po řádcích, každý řádek vstupu odpovídá jedné řádce matice. Na řádce jsou políčka oddělená mezerami (alespoň jednou mezerou). Políčko může obsahovat:

**znak X**
označující nepoužité (černé) políčko,

**znak .**
označující prázdné políčko, které má být vyplněno číslicí 1-9,

**číslo1\číslo2**
označuje políčko, které definuje, že součet následujících prázdných políček směrem dolů má být číslo1 a zároveň součet následujících prázdných políček směrem vpravo má být číslo2,

**číslo1\X**
podobně jako předešlé, ale pouze pro políčka směrem dolů,

**X\číslo2**
podobně jako předešlé, ale pouze pro políčka směrem vpravo.

Výstupem programu informace o vyplněném kakuru. Pokud má zadané kakuro právě jedno řešení, program jej zobrazí. V opačném případě program určí, kolik různých řešení kakuro má a jejich počet zobrazí (viz ukázka níže).

Program musí kontrolovat správnost vstupních dat. Pokud je na vstupu nesprávně zadané kakuro, program to detekuje a vypíše chybové hlášení podle ukázky. Za nesprávný vstup se považuje:

- jiný formát buněk než uvádí seznam výše,
- jiný než obdélníkový tvar kakura (počet políček není shodný na všech řádkách),
- horizontální sekvence prázdných políček nemá vlevo určený součet,
- vertikální sekvence prázdných políček nemá nahoře určený součet,
- je určený horizontální/vertikální součet, ale v daném směru nejsou zadaná volná políčka,
- více než 9 sousedících prázdných políček (v řádce/sloupci),
- součet menší než 1 nebo vyšší než 45,
- vstup větší než 32x32 (testovací prostředí nezadává větší velikosti plochy).

Stručná pravidla pro vyplňování kakura: cílem je vyplnit všechna prázdná políčka hodnotami 1-9. Sekvence sousedících prázdných políček má vždy určený součet (horizontální i vertikální). Čísla 1-9 je potřeba umístit tak, aby součty souhlasily. Navíc, v horizontální/vertikální sekvenci sousedících políček se žádné číslo nesmí opakovat.

Program je implementačně náročnější. Jedná se o soutěžní úlohu pro studenty, kteří již mají zkušenosti s programováním a vypracovávání běžných domácích úkolů je pro ně nudné. Odevzdaný program bude hodnocen ve dvou krocích. Pokud program projde standardními testy, bude ohodnocen nominálním hodnocením. Pokud navíc Vaše řešení bude optimální, dostanete další hodnocení:

- 5 bodů, pokud Vaše řešení bude správné a získá skóre vyšší než 75% skóre referenčního řešení,
- 5 bodů, pokud Vaše řešení bude patřit mezi 10% odevzdaných řešení s nejvyšším skóre.

Dodatečné hodnocení (bonus 5+5 bodů) bude přidělen až budou odevzdaná všechna studentská řešení, tedy až po uzavření úlohy. Pro soutěžní úlohu nemáte k dispozici nápovědu.

Program je standardně spouštěn v omezeném testovacím prostředí, je omezen dobou běhu a volnou pamětí. Limity jsou vidět v ohodnocení referenčního řešení. Aby program uspěl v soutěžním testu, musí být optimalizovaný. Na vstupu soutěžního testu jsou zadání kakuro, která mají mnoho řešení. Výsledkem jsou pak hodnoty až 100000 různých řešení, která musí být nalezena v daném časovém limitu.

**Ukázka práce programu:**
```
Zadejte kakuro:
X     X     16\X  16\X  X     X     15\X  16\X  X     X     X     X
X     X\8   .     .     7\X   X\13  .     .     X     7\X   12\X  X
X     16\17 .     .     .     29\9  .     .     19\15 .     .     X
X\9   .     .     6\23  .     .     .     11\11 .     .     .     X
X\16  .     .     .     23\19 .     .     .     .     9\X   X     X
X     X     X\22  .     .     .     19\8  .     .     .     30\X  6\X
X     X     6\X   15\21 .     .     .     .     11\19 .     .     .
X     X\22  .     .     .     11\21 .     .     .     4\8   .     .
X     X\7   .     .     X\3   .     .     X\9   .     .     .     X
X     X     X     X     X\12  .     .     X     X\12  .     .     X
Kakuro ma jedno reseni:
X     X     16\X  16\X  X     X     15\X  16\X  X     X     X     X
X     X\8   1     7     7\X   X\13  4     9     X     7\X   12\X  X
X     16\17 7     9     1     29\9  2     7     19\15 6     9     X
X\9   7     2     6\23  6     9     8     11\11 7     1     3     X
X\16  9     6     1     23\19 7     1     3     8     9\X   X     X
X     X     X\22  5     9     8     19\8  1     4     3     30\X  6\X
X     X     6\X   15\21 6     5     8     2     11\19 6     8     5
X     X\22  5     9     8     11\21 7     5     9     4\8   7     1
X     X\7   1     6     X\3   2     1     X\9   2     1     6     X
X     X     X     X     X\12  9     3     X     X\12  3     9     X

Zadejte kakuro:
X     5\X   7\X   9\X
X\6   .     .     .
X\15  .     .     .
Celkem ruznych reseni: 4

Zadejte kakuro:
X     3\X   5\X
X\3   .     .
X\4   .     .
Reseni neexistuje.

Zadejte kakuro:
X     3\X   5\X
X\3   .
X\5   .     .
Nespravny vstup.
```
