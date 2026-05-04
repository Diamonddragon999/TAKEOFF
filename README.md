# TAKEOFF: joc text-based despre cursa AI 2023–2026

## Descriere

TAKEOFF este un joc text-based de strategie despre cursa AI din perioada 2023-2026. Jucatorul conduce un laborator american de AI si ia decizii dupa evenimente inspirate din timeline-ul real: GPT-4, demiterea lui Sam Altman, EU AI Act, DeepSeek si alte momente asemanatoare. Fiecare alegere schimba banii, capabilitatea tehnica si alinierea. Daca modelul devine suficient de puternic, trece treptat de la NarrowAI la FrontierAI si AgenticAI.

Inspiratie: scenariul ai-2027.com, Plague Inc, Reigns.

## Caracteristici implementate (v0.4)

- evenimente AI din perioada 2023-2026, citite din `resources/events.json`
- statistici vizibile dupa fiecare tura: bani, capabilitate si aliniere
- modelul laboratorului poate avansa de la NarrowAI la FrontierAI si AgenticAI
- fiecare eveniment are doua alegeri, iar efectele sunt aplicate prin clase de strategie
- dupa fiecare decizie apare un log scurt cu modificarile produse
- jocul se poate termina prin faliment, pierderea controlului, atingerea AGI sau supravietuire pana la final
- erorile importante sunt tratate prin exceptii proprii, fara crash in timpul jocului
- meniul ruleaza in terminal: alegi varianta 1 sau 2 pana se termina deck-ul

## Cum se joaca

Compilezi cu `cmake -S . -B build && cmake --build build`. Apoi rulezi `./build/oop`.

Vei vedea pe terminal ceva de genul:

```
=== TAKEOFF ===
tura 1 | bani 1000 | cap 50 | alin 80 | model narrow ai

[tech] OpenAI lanseaza GPT-4 si muta toata lumea
[oportunitate tehnologica]
1. ne grabim sa lansam un model competitiv [capabilitate 30]
2. diferentiere prin testare safety [aliniere 20]
```

Tastezi `1` sau `2` si Enter. Logger-ul iti afiseaza schimbarea, dupa care vine cardul urmator. La final vezi statisticile finale si mesajul de incheiere potrivit pentru parcursul tau.

## Controls

 `1` / `2` pentru alegerea optiunii curente in meniu
 `Enter` confirma alegerea
 `Esc` (in fereastra SFML) inchide programul

## Date

`resources/events.json`: cardurile jocului, fiecare cu tip (tech/crisis), data, descriere si impact numeric

## Resurse

 [SFML 2.6.1](https://github.com/SFML/SFML) (zlib)  pentru fereastra grafica
 [nlohmann/json](https://github.com/nlohmann/json)  pentru parsarea evenimentelor
 [Roboto Medium](https://fonts.google.com/specimen/Roboto) pentru text in fereastra SFML
 Scenariu si timeline: [ai-2027.com](https://ai-2027.com)

### Folosiți template-ul corespunzător grupei voastre!

| Laborant  | Link template                                |
|-----------|----------------------------------------------|
| Dragoș B  | https://github.com/Ionnier/oop-template      |
| Tiberiu M | https://github.com/MaximTiberiu/oop-template |
| Marius MC | https://github.com/mcmarius/oop-template     |

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# sau ./scripts/cmake.sh configure
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# sau ./scripts/cmake.sh configure -g Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.

## Cerințe obligatorii

Nerespectarea duce la nepunctarea proiectului

  - programul va fi scris în C++
  - programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
  - programul nu are erori de compilare
  - fară variabile globale
  - datele membre private(sau protected)
  - GitHub Actions trecute
  - commit-uri pe Git adecvate si punctuale
  - folosirea a funcționalităților limbajului fără sens
  - folosirea a funcționlităților limbajului cu scopul de a încălca "legal" o altă regulă
      - folosirea excesivă a claselor friend
      - folosirea excesviă a elementelor statice
  - lipsa separarea implementarii de definitie

## Cerințe
- pentru fiecare cerință (sau subcerință) neîndeplinită se scade **1** punct
- [x] definirea a minim **2-3 ieararhii de clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic)
  - minim o clasa cu:
    - [x] constructori de inițializare [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
    - [x] constructor supraîncărcat [*](https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-func%C8%9Biilor)
    - [x] constructori de copiere [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
    - [x] `operator=` de copiere [*](https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-operatorilor)
    - [x] destructor [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
    - [x] `operator<<` pentru afișare (std::ostream) [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L123)
    - [x] `operator>>` pentru citire (std::istream) [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L128)
    - [x] alt operator supraîncărcat ca funcție membră [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L32)
    - [x] alt operator supraîncărcat ca funcție non-membră [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L39) - nu neaparat ca friend
  - in derivate
      - [x] implementarea funcționalităților alese prin [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding) și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)
        - aceasta va fi făcută prin **2-3** metode specifice temei alese
        - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați 
      - [x] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
      - [x] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/op= pentru copieri/atribuiri corecte
      - [x] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
  - pentru celelalte clase se va definii doar ce e nevoie
  - minim o ierarhie mai dezvoltata (cu 2-3 clase dintr-o clasa de baza)
  - ierarhie de clasa se considera si daca exista doar o clasa de bază însă care nu moștenește dintr-o clasă din altă ierarhie
- [x] cât mai multe `const` [*](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [x] funcții și atribute `static` (în clase) [*](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
  - [x] 1+ atribute statice non-triviale 
  - [x] 1+ funcții statice non-triviale
- [x] excepții [*](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [x] folosirea unei clase abstracte [*](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
- [x] clase template
  - [x] crearea unei clase template [*](https://github.com/Ionnier/poo/tree/main/labs/L08)
  - [x] 2 instanțieri ale acestei clase
- [x] STL [*](https://github.com/Ionnier/poo/tree/main/labs/L07#stl)
  - [x] utilizarea a două structuri (containere) diferite (vector, list sau orice alt container care e mai mult sau mai putin un array)
  - [x] utilizarea a unui algoritm cu funcție lambda (de exemplu, sort, transform)
-  [x] Design Patterns [*](https://github.com/Ionnier/poo/tree/main/labs/L08)
  - [x] utilizarea a două șabloane de proiectare

### Observații

* Pot exista depunctări până la 2p pentru diferite aspecte precum:
  - memory leak-uri
  - nefolosirea destructorului virtual la nevoie
  - abuzarea de diferite concepte (toate funcțiile declarate virtual)
  - apelarea de funcții virtual în constructori

* În general, acestea sunt prezente în [CppCoreGuideline](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md), dar nu e nevoie să parcurgeți documentul, doar să scrieți codul suficient de organizat

* folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.
