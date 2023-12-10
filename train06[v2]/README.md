## Úkolem je realizovat funkci (ne celý program, pouze funkci), která spočte průměr ze 3 celých čísel.

Funkce má následující rozhraní:

    long long avg3 ( long long a, long long b, long long c );

- vstupními parametry funkce jsou tři čísla, jejich průměr bude funkce počítat,
- návratovou hodnotou funkce je vypočtená hodnota průměru,
- pokud průměr vychází neceločíselný, funkce zahodí desetinnou část (zaokrouhlení směrem k 0),
- funkce nemůže selhat, pro každou trojici vstupujících čísel je průměr definovaný.

**Ukázka použití funkce:**
```
assert ( avg3 ( 1, 2, 3 ) == 2 );
assert ( avg3 ( -100, 100, 30 ) == 10 );
assert ( avg3 ( 1, 2, 2 ) == 1 );
assert ( avg3 ( -1, -2, -2 ) == -1 );
assert ( avg3 ( LLONG_MAX, LLONG_MAX, LLONG_MAX ) == LLONG_MAX );
```

**Poznámky:**

- Jako základ Vašeho řešení použijte zdrojový kód z přiloženého souboru.
- Do funkce main si můžete doplnit i další Vaše testy, případně ji můžete libovolně změnit. Důležité je zachovat podmíněný překlad.
- V ukázce je použito makro assert. Pokud je parametrem nenulová hodnota, makro nedělá nic. Pokud je parametrem nepravda (nula), makro ukončí program a vypíše řádku, kde k selhání došlo. Pokud tedy Vaše implementace projde ukázkovými testy, program doběhne a nic nezobrazí.
- Na první pohled je problém triviální. Toto zdání klame, funkce musí správně pracovat pro všechny vstupní hodnoty, tedy například i pro nejvyšší hodnotu LLONG_MAX v ukázce.
- Datový typ long long má na cílové platformě velikost 64 bitů. Není k dispozici žádný větší datový typ. Nestandardní typy __int128 a __float128 nelze použít (jsou odpojené).
- Test mezních hodnot je hodnocen buď 0% (pro nějaké hodnoty funkce vrací špatný výsledek) nebo 100% (vše funguje správně).
- Update: dostupné hlavičkové soubory jsou vidět v přiloženém vzoru. Jiné hlavičkové soubory nejsou k dispozici a nejsou ani potřeba. Nevkládejte další hlavičkové soubory pomocí #include, program skončí chybou kompilace.
