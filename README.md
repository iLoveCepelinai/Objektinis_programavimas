# Programos versija 1.0
Maišyti skirstymo į list/vector būdai
## Failai:
* [Main: amsiejus_v1.0.cpp](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/amsiejus_v1.0/amsiejus_v1.0.cpp)
* [Header: v1.0_bib.h](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/amsiejus_v1.0/v1.0_bib.h)
* [CPP funkcijos: v1.0_bib.cpp](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/amsiejus_v1.0/v1.0_bib.cpp)
## Nuorodos į release'us
* [1.0 release](https://github.com/iLoveCepelinai/Objektinis_programavimas/releases/tag/v1.0)
## Naudojimosi instrukcija
Numatytoji (default) programos versija yra padaryta naudojant list 3 skirtymo metodą (mano versija). Todėl norint pakeisti į kitą skirstymo/konteinerių versiją reikia:

***a)Darant su vector, 1 būdas:***
* Nukopijuoti [vector1_main](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/vector1_main) iš gitHub repozitorijos ir įklijuoti į main'ą (amsiejus_v1.0.cpp)

  arba
  
* 13 eilutė turi būti tokia: vector <studentas> grupe, dundukai, sukciukai;
* Visas main'e (amsiejus_v1.0.cpp) esančias funkcijas *skaitymasList(<...>)* pakeisti į *skaitymasVec(<...>)*
* Visas main'e esančias funkcijas *skirstymasManoList(grupe, dundukai)* pakeisti į *skirstymas1Vec(grupe, dundukai, sukciukai)*
* Visas main'e esančias funkcijas *surasymasList(dundukai, grupe, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* pakeisti į *surasymasVec(dundukai, sukciukai, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* (failų pavadinimų keisti nereikia)
* Visas main'e esančias funkcijas *grupe.clear();* pakeisti į *sukciukai.clear();*
  
***b)Darant su list, 1 būdas:***
* Nukopijuoti [list1_main](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/list1_main) iš gitHub repozitorijos ir įklijuoti į main'ą (amsiejus_v1.0.cpp)

  arba
  
* 13 eilutė turi būti tokia: list <studentas> grupe, dundukai, sukciukai;
* Visas main'e esančias funkcijas *skirstymasManoList(grupe, dundukai)* pakeisti į *skirstymas1List(grupe, dundukai, sukciukai)*
* Visas main'e esančias funkcijas *surasymasList(dundukai, grupe, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* pakeisti į *surasymasList(dundukai, sukciukai, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* (failų pavadinimų keisti nereikia)
* Visas main'e esančias funkcijas *grupe.clear();* pakeisti į *sukciukai.clear();*
  
***c)Darant su vector, 2 būdas:***
* Nukopijuoti [vector2_main](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/vector2_main) iš gitHub repozitorijos ir įklijuoti į main'ą (amsiejus_v1.0.cpp)

  arba
  
* Pakeisti 13 eilutėje iš *list* į *vector*
* Visas main'e (amsiejus_v1.0.cpp) esančias funkcijas *skaitymasList(<...>)* pakeisti į *skaitymasVec(<...>)*
* Visas main'e esančias funkcijas *skirstymasManoList(grupe, dundukai)* pakeisti į *skirstymas2Vector(grupe, dundukai)*
* Visas main'e esančias funkcijas *surasymasList(<...>)* pakeisti į *surasymasVec(<...>)* (konteinerių ir failų pavadinimų keisti nereikia)

***d)Darant su list, 2 būdas:***
* Nukopijuoti [list2_main](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/list2_main) iš gitHub repozitorijos ir įklijuoti į main'ą (amsiejus_v1.0.cpp)

  arba
  
* Visas main'e esančias funkcijas *skirstymasManoList(grupe, dundukai)* pakeisti į *skirstymas2List(grupe, dundukai)*

***e)Darant su vector, 3 (mano) būdas:***
* Nukopijuoti [vectorMano_main](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/vectorMano_main) iš gitHub repozitorijos ir įklijuoti į main'ą (amsiejus_v1.0.cpp)

  arba
  
* Pakeisti 13 eilutėje į vector vietoje list
* Pakeisti 13 eilutėje *dundukai* į *sukciukai*
* Visas main'e (amsiejus_v1.0.cpp) esančias funkcijas *skaitymasList(<...>)* pakeisti į *skaitymasVec(<...>)*
* Visas main'e esančias funkcijas *skirstymasManoList(grupe, dundukai)* pakeisti į *skirstymasManoVector(grupe, sukciukai)*
* Visas main'e esančias funkcijas *surasymasList(dundukai, grupe, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* pakeisti į *surasymasVec(grupe, sukciukai, "dundukai[kiekis].txt", "sukciukai[kiekis].txt")* (failų pavadinimų keisti nereikia)
* Visas main'e esančias funkcijas *dundukai.clear();* pakeisti į *sukciukai.clear();*

***f)Darant su list, 3 (mano) būdas:***
* Nukopijuoti [listMano_main](https://github.com/iLoveCepelinai/Objektinis_programavimas/blob/v_1.0/listMano_main) iš gitHub repozitorijos ir įklijuoti į main'ą (amsiejus_v1.0.cpp) jei kažką keitėte main'e

  arba
  
* Nieko daryti nereikia, nes čia numatytasis (default) būdas

## Išvados
Mano versijoje v1.0 buvo skirstoma 6 būdais: 4 iš jų duoti dėstytojo, 2 - mano pasirinkti ankstesnėse versijose (v0.4 ir v0.5). Mano būdai buvi grįsti pirma surūšiavimu pagal galutinį pažymį, paskui:
* vektorių būdu: tie, kurie surinko >=5 yra kopijuojami nuo galo į sukciukai vektorių, o iš bendro (grupe) vektoriaus šalinami (pop)
* list'ų būdu: atliekama splice funkcija, iškerpanti iš sąrašo grupe dundukus (<5) ir perkelianti į dundukai list'ą. Automatiškai list'e grupe lieka tik sukciukai (>=5)

Taigi, pagal laikus (žiūrėsiu tik į release x64 10 000 000 greičius, bet visi greičiai yra OPP aplankale) gauname (lėtėjimo eiliškumu):
* vector pirmas būdas (~1.29s)
* vector antras būdas (~1.49s)
* list antras būdas (~2.58s)
* list pirmas būdas (~2.92s)
* vector mano būdas (~3.37s)
* list mano būdas (~9.95s)

Buvau nustebintas, kad sąrašų trynimo būdas (2) buvo šiek tiek greitesnis už sąrašų dubliavimo (1) būdą. Taip pat galima matyti, kad rūšiuoti nei vektorių, nei listų neapsimoka, nors tai, atminties atžvilgiu, yra pats efektyviausias būdas.

## Kompiuterio parametrai
* Intel core i7-7700HQ
* 8 GB RAM DDR4
* Failas įrašomas/nuskaitomas iš HDD, bet Visual Studio įrašyta į SSD

## Papildoma info
**2020 11 28**
* Padarytas šioks toks šablonas, įdėtos jau dvi skirtymo funkcijos (abi mano, iš versijų 0.4 ir 0.5)
* Vėliau padarytos abi rūšiacimo funkcijos 1 būdui bei pritaikytos skaitymo ir rašymo funkcijos pagal konteinerius
**2020 11 29**
* Viskas užbaigta. Tačiau yra problemų su setup failu. Nors ir viską suinstaliuoja puikiai, programa neveikia, nes nesukuriami/nerandami 1000.txt (ir t.t.) failai. Reikalinga gilesnė analizė.
