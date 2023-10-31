## Úkolem je realizovat funkci (ne celý program, pouze funkci), která pro zadané datum rozhodne, kolikátý den v roce to je.

Funkce má následující rozhraní:

    int dateToIndex (int day, int month, int year, int * idx);

- vstupními parametry funkce jsou den, měsíc a rok, které mají být ověřeny,
- idx je výstupní parametr udávající pořadové číslo zadaného dne od začátku roku. Pro 1. ledna je návratová hodnota 1. Pokud funkce uspěje, zapíše pořadové číslo dne do svého výstupního parametru idx. Pokud funkce selže (neplatné hodnoty parametrů), ponechá výstupní parametr beze změn,
- návratovou hodnotou funkce je signalizace úspěchu (hodnota 1) a v případě chybných parametrů signalizace neúspěchu (hodnota 0).

Za chybu je považováno:

- year je menší než 2000 (všechna data před rokem 2000 považujeme za neplatná),
- month je mimo rozsah 1 až 12,
- day je neplatný (mimo 1 až počet dní v měsíci),

Ukázka použití funkce:

    assert(dateToIndex( 1,  1, 2000, &days) == 1 && days == 1);
    assert(dateToIndex( 1,  2, 2000, &days) == 1 && days == 32);
    assert(dateToIndex(29,  2, 2000, &days) == 1 && days == 60);
    assert(dateToIndex(29,  2, 2001, &days) == 0);
    assert(dateToIndex( 1, 12, 2000, &days) == 1 && days == 336);
    assert(dateToIndex(31, 12, 2000, &days) == 1 && days == 366);
    assert(dateToIndex( 1,  1, 1999, &days) == 0);
    assert(dateToIndex( 6,  7, 3600, &days) == 1 && days == 188);
    assert(dateToIndex(29,  2, 3600, &days) == 1 && days == 60);
    assert(dateToIndex(29,  2, 4000, &days) == 0);
