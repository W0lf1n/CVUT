## Úkolem je vytvořit program, který bude rozhodovat zda jsou řetězce palindromy.

Vstupem programu je seznam řetězců oddělených odřádkováním (\n), jejich zpracování skončí po dosažení konce vstupu (EOF).

Výstupem programu je pro každý řetězec rozhodnutí, zda se jedná o palindrom, palindrom nezávislý na velikosti písmen (case-insensitive), nebo zda řetězec není palindrom.

Program při zjišťování, zda je řetězec palindrom, ignoruje bílé znaky (kromě odřádkování \n).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

- prázdný řetězec (pouze odřádkování)
- řetězec není ukončen odřádkováním \n
- řetězec se skládá pouze z bílých znaků

**Ukázka práce programu:**
```
Zadejte retezec:
kajak
Retezec je palindrom (case-sensitive).
Kobyla ma maly bok
Retezec je palindrom (case-insensitive).
xXx_666_progtesttsetgorp_666_xXx
Retezec je palindrom (case-sensitive).
PalindromE
Retezec neni palindrom.
Murder for a jar of red RUM
Retezec je palindrom (case-insensitive).

Zadejte retezec:
aaa
Retezec je palindrom (case-sensitive).
bcb
Retezec je palindrom (case-sensitive).
   
Nespravny vstup.
```

**Poznámky:**

- Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol zobrazit text bez zvýrazňování (bez HTML markupu).
- Maximální délka vstupu není určena. V této úloze je potřeba paměť alokovat dynamicky.
- Pro načítání řádek textu se hodí funkce getline případně fgets. Nepoužívejte funkci gets.
- Pro zpracování bílých znaků se hodí funkce isspace.
