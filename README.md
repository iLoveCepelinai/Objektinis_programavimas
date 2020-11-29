# Objektinis programavimas (Namų darbas)
Matas Amšiejus

## Svarbu!!:
Kadangi kažkodėl klaidingai supratau kaip veikia Github, nuo pat pradžių blogai kėliau failus. Todėl pradėjau redaguoti tik 2020 11 20 (išklausiau pratybų ir supratau, kad pas mane, siunčiantis source code zip failą, atsiunčia klaidingus dalykus). Todėl dabar kursiu 5 naujas šakas (v_0.11-array, v_0.11-vector, v_0.21, ..., v_0.51) tam, kad jūs galėtumėte matyti, kad originalios šakos buvo įkeltos laiku (v_0.1 šaką perdariau nepamąstęs, kad išsitrins įkėlimo laikai. Dėl to tiesiog prašau jūsų pasitikėti, kad ta versija buvo įkelta laiku). Atsiprašau dėl sukeltų nepatogumų ir neaiškumų.

P.S pats kodas niekur nebuvo redagutas kuriant naujas šakas
## Nuorodos:
*Į projektų versijas:*
* [Projektas](https://github.com/iLoveCepelinai/Objektinis_programavimas/releases)

*Į namų darbo šakas (naujos):*
* [Programa v0.11(array)](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.11(array))
* [Programa v0.11(vector)](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.11(vector))
* [Programa v0.21](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.21)
* [Programa v0.31](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.31)
* [Programa v0.41](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.41)
* [Programa v0.51](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.51)
* [Programa v1.0](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_1.0)

*Į namų darbo šakas (senos):*
* [Programa v0.1](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.1)
* [Programa v0.2](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.2)
* [Programa v0.3](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.3)
* [Programa v0.4](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.4)
* [Programa v0.5](https://github.com/iLoveCepelinai/Objektinis_programavimas/tree/v_0.5)

## Taip pat naudinga:
**Darbas buvo atliekamas naudojant "Visual Studio 2019"**

## Eksperimento su v0.4 ir 0.5 išvados
Palyginus vektorių ir sąrašų spartą (10 000 000, release x64) matome, kad vektoriai viską atlieka sparčiau.

## Išvados 1.0
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


:-)
