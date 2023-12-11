## Úkolem je realizovat sadu funkcí, které budou pracovat s jednosměrně zřetězeným spojovým seznamem. Požadované funkce jsou:

- Funkce insertStart ( l, x ) přidá prvek s hodnotou x na začátek seznamu l.
- Funkce insertEnd ( l, x ) přidá prvek s hodnotou x na konec seznamu l.
- Funkce removeMax ( l ) odstraní ze seznamu všechny prvky s nejvyšší hodnotou. Vrací celé číslo - počet odstraněných prvků (počet může být větší než 1, pokud se v seznamu prvek s nejvyšší hodnotou opakuje, může být i 0 pro prázdný seznam).
- Funkce destroyAll ( l ) uvolní paměť alokovanou pro prvky obsažené v seznamu.
- Struktura TDATA reprezentuje spojový seznam. Obsahuje složky m_First (první prvek spojového seznamu) a m_Last (ukazuje na poslední prvek spojového seznamu). Struktura TDATA je deklarovaná v testovacím prostředí, Vaše implementace deklaraci nemůže nijak měnit. Pro prázdný seznam jsou obě složky nastavené na hodnotu NULL.
- Struktura TITEM reprezentuje jeden prvek ve spojovém seznamu. Obsahuje složky m_Next (odkaz na další prvek e spojovém seznamu, NULL pro poslední hodnotu v seznamu) a složku m_Val (ukládané číslo).

V přiloženém archivu naleznete deklarace požadovaných funkcí a ukázkové testy. Odevzdávejte zdrojový soubor, který obsahuje implementaci požadovaných funkcí. Za základ použijte ukázku z přiloženého archivu. Pokud zachováte bloky podmíněného překladu, lze soubor použít jak pro lokální testování, tak i pro odevzdání na Progtest. Při implementaci dejte pozor na správnou práci s dynamicky alokovanou pamětí a s ukazateli obecně. Před odevzdáním si určitě program zkontrolujte paměťovým debuggerem.

Tato úloha je za 0.1 bodu, pro plný bodový zisk je potřeba vyřešit úlohy obě.
