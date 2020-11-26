# SZE-MOSZE-2020-Runtime_Terror

Csapat: Runtime_Terror

Tagok: Tömördi Tamás, Jaksics Benedek, Csillag Bence


## Összegzés

Az első három feladat óta az alábbi feature-ök kerültek be a programba:

### JSON parser fejlesztése

A JSON parser annyi plusz funkciót kapott, hogy képes az egyszintű JSON-ökből adat listát is beolvasni. Például, ha valahol több Monster kerül átadásra.

### Osztály átnevezések

A korábbi Unit új neve Monster, a korábbi Player új neve Hero.

### Map class

A Map osztály egy fájlból képes beolvasni egy pályát, amin a játék történik majd.

### Game class

A Game osztály lehetőséget ad egy Map beállítására, Hero-k és Monster-ek pályára helyezésére, illetve egy loop-ot futtat, amely különböző irányokat vár bemenetként, ezzel irányítható a Hero. Ha a hős a pályán Monster-ekkel találkozik, azokkal harcba száll. A játék akkor ér véget, ha a Hero meghal vagy az összes Monster legyőzésre kerül.

### Defense

Az egységek már védekező erővel is rendelkeznek. Csak akkor vihető be sebzés, ha a damage nagyobb mint a defense.

## 3. feladat


### JsonParser és Google test

Egy olyan osztály lett létrehozva, ami 3 különböző bemenetről tud adatot beolvasni, és feldolgozni.

Az újonnan létrehozott osztály függvényeit Google teszttel ellenőrizve.

### Levelup

A játék kiegészítésre került egy Player osztállyal, amely abban különbözik a Unit-tól, hogy az áltatala bevitt sebzés értékével megegyező xp-t kap. 100 xp-nként szintet lép, ekkor változik a health és damage értéke. 

Illetve a kódon a test workflow már statikus kódanalízist és memory leak check-et is futtat minden push után.

### Attackspeed

A JSON fájlok bővültek egy új adattaggal, ami egy Unit két ütése között eltelt "időt" jelzi. A program most már ezt a tulajdonságot figyelembe véve ütközteti az ellenfeleket.

Emellett minden osztály kibővült DoxyGen dokumentációhoz használt kommentekkel. Ezt a dokumentációt a pushdocs.yml workflow generálja a gh-pages branchre minden push után. 

Dokumentáció: https://teaching-projects.github.io/SZE-MOSZE-2020-Runtime_Terror/


## 2. feladat

A program két argumentumként vár két json fájlt, amelyekben a Unit-ok adatai vannak tárolva. Ezt a két Unitot ütközteti a program. Ha valamelyik fájl nem létezik, a program hibaüzenetet ír ki.

Elkészült a test.yml workflow is. Ez egy test.sh nevű bash scriptet futtat, amely három egységet ütköztet egymással hat féle képpen, majd ellenőrzi, hogy az output.txt -ben lévő eredmények megegyeznek e az expected-output.txt tartalmával.

## 1. feladat

A játék alapjai: van két egység, amelyek addig ütögetik egymást, amíg egyikőjük meg nem hal.

A main.cpp eddig ezeket tartalmazza:

- Unit class az egységeknek (később ebből tervezünk származtatni külön Player-t, Enemy-t vagy amire még szükség lesz)
- Game class, amely majd a játék mechanizmusát fogja tartalmazni (tehát a tartalma még jelentősen változni fog)
