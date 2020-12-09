# Tagok

| Név             | Github azonosito | Javasolt relatív érdemjegy | Becsült óra | Indoklás                                                                       |
| --------------- | ---------------- | -------------------------- | ----------- | ------------------------------------------------------------------------------ |
| Jaksics Benedek | @Jabezare        | 0                          | 20-30       | Szépen csinálta a dolgát, főként a makefile és a doxygen nagy szakértője volt. |
| Csillag Bence   | @csibe1999       | 0                          | 20-30       | Szépen csinálta a dolgát, főként a unit testek és a docker szakértője volt.    |
| Tömördi Tamás   | @tamastomordi    | +1                         | 30-40       | Önként vállalta a legnehezebb feladatokat, a program gerincének megalkotója.   |

Törekedtünk arra is, hogy mindenki minden típusú feladatba belekóstoljon.

# Videók

- [Gameplay](/videos/gameplay.mp4)
- [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat       | Merge ideje a határidőhöz (nap) | Change request körök | Reviewer                                                          |
| ------------- | ------------------------------- | -------------------- | ----------------------------------------------------------------- |
| Feladat 1     | +4                              | 3                    | @hegyhati                                                         |
| Feladat 2     | 0                               | 1                    | @hegyhati                                                         |
| jsonparser    | +8                              | 2                    | @wajzy                                                            |
| levelup       | +2                              | 1                    | @oliverosz                                                        |
| attackspeed   | 0                               | 1                    | @vizvezetek                                                       |
| documentation | -2                              | 1                    | @karcagtamas, @bencebaranyai, @Cerberuuus / @csibe1999, @Jabezare |
| unittest      | -1                              | 3                    | @karcagtamas @bencebaranyai / @Jabezare, @tamastomordi            |
| makefile      | -2                              | 1                    | @hegyhati                                                         |
| refactor      | -2                              | 0                    | @hegyhati                                                         |
| docker        | +1                              | 1                    | @hegyhati                                                         |
| jsonpimp      | Merge: 11.14                    | 1                    | @Jabezare, @csibe1999                                             |
| map           | Merge: 11.19                    | 2                    | @karcagtamas / @tamastomordi, @Jabezare                           |
| game          | Merge: 11.27                    | 1                    | @karcagtamas / @Jabezare, @csibe1999                              |
| defense       | Merge: 11.27                    | 1                    | @karcagtamas / @tamastomordi, @csibe1999                          |
| damage        | Merge: 11.30                    | 2                    | @karcagtamas @bencebaranyai / @csibe1999, @Jabezare               |
| markedmap     | Merge: 12.03                    | 2                    | @bencebaranyai @Cerberuuus / @Jabezare                            |
| preparedgame  | Merge: 12.06                    | 0                    | @tamastomordi, @csibe1999                                         |
| light radius  | Merge: 12.03                    | 1                    | @bencebaranyai / @Jabezare, @csibe1999                            |
| rendering     | Merge: 12.07                    | 0                    | @Jabezare, @csibe1999                                             |

# Unit tesztek

| Osztály        | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| -------------- | ------------------------ | ----------------------------- | ------------------ |
| `Monster`      | 11                       | 9                             | 2                  |
| `Hero`         | 7                        | 10                            | 4                  |
| `JSON`         | 5                        | 2                             | 6                  |
| `Map`          | 4                        | 4                             | 5                  |
| `Game`         | 10                       | 4                             | 5                  |
| `MarkedMap`    | 2                        | 2                             | 3                  |
| `PreparedGame` | 2                        | 0                             | 0                  |

# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| ------------------------------ | ----------------------------- | ------------------------- |
| `Monster`                      |
| `Hero`                         |
| `JSON`                         |
| `Map`                          |
| `Game`                         |
| `MarkedMap`                    |
| `PreparedGame`                 |
| `Renderer`                     |
| `TextRenderer`                 |
| `SVGRenderer`                  |
| `HeroTextRenderer`             |
| `CharacterSVGRenderer`         |
| `ObserverTextRenderer`         |
| `ObserverSVGRenderer`          |

# Mindenféle számok

- Összes cpp kódsor : 1021
- Egyéb kódsor (make,doxyfile,shellscript, ...)
  - Makefile: 71
  - Shellscript: 18
- cppcheck
  - warning : 0
  - style : 23
  - performance : 7
  - unusedFunction : 5
  - missingInclude : 1

# Implicit megtanult dolgok

Olyanok, amik nem a tárgy anyaga, de hasznos volt elsajátítani:

- alapvető shell scripting
- `std::variant`
- van egy titkos mágikus shell parancsunk, be fogjuk kereteztetni

# Feedback (optional)

- Az egyik olyan tárgy az egyetemen, amely egyszerre nehéz és hasznos is. Összességében elmondhatjuk, hogy ennyit még életünkben nem kódoltunk, és korábban nem is nagyon tanultunk ennyi új dolgot. Elsősorban a kódolás részével volt sok melónk, mert a tárgyat mind a hárman az OOP-vel párhuzamosan vettük fel.

- Az online videós megoldás szeritünk nagyon jó volt, sokkal jobb mintha be kellett volna ülni az órákra. Talán néhol a videók hang és kép minősége lehetett volna egy picit jobb.

# Üzenet a jövőbe (optional)

- Nem jut eszünkbe semmi.
