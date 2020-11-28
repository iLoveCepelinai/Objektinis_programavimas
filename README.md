# Programos versija 1.0
Maišyti skirstymo į list/vector būdai
## Failai:
* [Main: amsiejus_v1.0.cpp](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/amsiejus_v1.0/amsiejus_v1.0.cpp)
* [Header: v1.0_bib.h](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/amsiejus_v1.0/v1.0_bib.h)
* [CPP funkcijos: v1.0_bib.cpp](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/amsiejus_v1.0/v1.0_bib.cpp)
## Nuorodos į release'us
* [1.0 release (WIP)](https://github.com/iLoveCepelinai/Objektinis_programavimas/releases/tag/v1.0)
## Naudojimosi instrukcija
Numatytoji (default) programos versija yra padaryta naudojant list 3 skirtymo metodą (mano versija). Todėl norint pakeisti į kitą skirstymo/konteinerių versiją reikia:
**Jei pakeitėte konteinerių tipą ar norite pakeisti rūšiavimo būdą, reikia:**

***a)Darant su vector, 1 būdas:***

***b)Darant su list, 1 būdas:***

***c)Darant su vector, 2 būdas:***

***d)Darant su list, 2 būdas:***

***e)Darant su vector, 3 (mano) būdas:***
* Pakeisti 13 eilutėje į vector vietoje list
* Pakeisti 13 eilutėje *dundukai* į *sukciukai*
* Visas main'e (amsiejus_v1.0.cpp) esančias funkcijas *skaitymasList(<...>)* pakeisti į *skaitymasVec(<...>)*
* Visas main'e esančias funkcijas *skirstymasManoList(grupe, dundukai)* pakeisti į *skirstymasManoVector(grupe, sukciukai)*
* Visas main'e esančias funkcijas *surasymasList(dundukai, grupe, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* pakeisti į *surasymasVec(sukciukai, grupe, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* (failų pavadinimų keisti nereikia)
* Visas main'e esančias funkcijas *dundukai.clear();* pakeisti į *sukciukai.clear();*

***f)Darant su list, 3 (mano) būdas:***
* Nieko daryti nereikia, nes čia numatytasis (default) būdas
## Papildoma info
**2020 11 28**
* Padarytas šioks toks šablonas, įdėtos jau dvi skirtymo funkcijos (abi mano, iš versijų 0.4 ir 0.5)
