Úkolem je realizovat sadu funkcí pro práci se spojovými seznamy. Spojový seznam reprezentuje seznam zločinců v evidenci policie. Zločinec je reprezentován jménem a odkazy na ostatní zločince, na které má kontakt. S takovým seznamem chceme provádět tyto operace: přidání zločince, přidání kontaktu, kopírování seznamu a mazání seznamu.

**TCRIMINAL**
tato datová struktura je deklarovaná v testovacím prostředí. Vaše implementace bude s touto strukturou pracovat, ale nesmí jí nijak měnit. Struktura reprezentuje jednoho zločince. Zločinci jsou uloženi v podobě jednosměrně zřetězeného spojového seznamu. Struktura má následující složky:
- m_Next - odkaz na dalšího zločince ve spojovém seznamu. Poslední záznam v seznamu má odkaz m_Next nastaven na hodnotu nullptr.
- m_Name - ASCIIZ (nulou ukončený) řetězec udávající jméno zločince.
- m_Contacts - pole s odkazy na další zločince, na které má tento zločinec kontakt. V poli se může vyskytovat ten samý odkaz vícekrát (evidence nemá čištěná data) a ve výjimečných případech může být v poli i odkaz na sebe sama.
- m_Cnt - počet vyplněných odkazů v poli m_Contacts.
- m_Capacity - prostor alokovaný polem m_Contacts.

**createRecord ( name, next )**
funkce vytvoří nový prvek ve spojovém seznamu a umístí jej na první pozici. Parametrem je name - jméno nového zločince a next - odkaz na dosavadní počátek spojového seznamu zločinců. Návratovou hodnotou funkce je ukazatel na první prvek nového spojového seznamu zločinců. Funkce je zodpovědná za alokaci struktury a za vyplnění jejích složek. Nově přidávaný zločinec bude mít prázdné pole kontaktů (nulová délka i kapacita).

**addContact ( record, newContact )**
funkce přidá do záznamu record nový kontakt (newContact). Záznam bude přidán na konec pole m_Contacts, funkce podle potřeby alokuje paměťový prostor tohoto pole.

**freeList ( list )**
funkce k uvolnění prostředků alokovaných ve spojovém seznamu. Parametrem funkce je odkaz na první prvek spojového seznamu zločinců dříve vytvořených pomocí funkce createRecord.

**cloneList ( list )**
funkce vytvoří kopii spojového seznamu zločinců. Nově vytvořený seznam musí zachovat jména zločinců, jejich pořadí v seznamu a musí správně zkopírovat i pole s kontakty tak, aby kontakty odkazovaly na správné kopie záznamů v nově vytvořeném seznamu. Pozor, nově vytvořený seznam musí být zcela nezávislý na originále, tedy i odkazy na zástupce musí směřovat na prvky nově vytvořeného seznamu. Návratovou hodnotou funkce je odkaz na první prvek vytvořené kopie seznamu.
