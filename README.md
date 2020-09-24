# SZE-MOSZE-2020-Runtime_Terror

Csapat: Runtime_Terror

Tagok: Tömördi Tamás, Jaksics Benedek, Csillag Bence

## 2. feladat

A program két argumentumként vár két json fájlt, amelyekben a Unit-ok adatai vannak tárolva. Ezt a két Unitot ütközteti a program. Ha valamelyik fájl nem létezik, a program hibaüzenetet ír ki.

Elkészült a test.yml workflow is. Ez egy test.sh nevű bash scriptet futtat, amely három egységet ütköztet egymással hat féle képpen, majd ellenőrzi, hogy az output.txt -ben lévő eredmények megegyeznek e az expected-output.txt tartalmával.

## 1. feladat

A játék alapjai: van két egység, amelyek addig ütögetik egymást, amíg egyikőjük meg nem hal.

A main.cpp eddig ezeket tartalmazza:

* Unit class az egységeknek (később ebből tervezünk származtatni külön Player-t, Enemy-t vagy amire még szükség lesz)
* Game class, amely majd a játék mechanizmusát fogja tartalmazni (tehát a tartalma még jelentősen változni fog)
