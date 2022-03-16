# Proiect-1-POO
Popescu Matei Calin, grupa 134

Am implementat doua clase, point si triangle

point:
* are ca date membre doua numere reale x si y
* constructorul default seteaza coordonatele la 0, cel parametrizat seteaza coordonatele in functie de parametri
* setter-ul modifica x si y in functie de parametri
* doi getteri pentru x si y
* operatori supraincarcati: >>, <<, +, -, *, /, +=, -=, *=, /=, ==, !=
* adunare si scadere intre doua puncte
* inmultire si impartire cu scalar, numar real
* distance - returneaza distanta dintre doua puncte
* collinear - returneaza 1 daca 3 puncte sunt coliniare, altfel 0
* line - afiseaza ecuatia dreptei formate de doua puncte
* middle - returneaza mijlocul a doua puncte

triangle:
* are ca date membre 3 puncte A, B, C si 3 numere reale AB, AC, BC, reprezentand distantele dintre puncte
* constructorul default seteaza punctele la (0, 0) si distantele la 0
* doi constructori parametrizati, unul cu 6 parametri reali, reprezentand coordonatele fiecarui punct
* celalalt constructor primeste ca parametri 3 puncte
* ambii constructori seteaza punctele in functie de parametri si distantele folosind metoda distance din clasa point
* doi setteri care functioneaza exact ca cei doi constructori
* trei setteri pentru fiecare punct al triunghiului - actualizeaza coordonatele punctului, dar si distantele laturilor
* getteri pentru fiecare punct si fiecare distanta
* getteri pentru cosinusul fiecarui unghi folosind teorema generalizata a lui Pitagora
* getteri pentru sinusul fiecarui triunghi folosind cosinus
* operatori supraincarcati: >>, <<
* perimeter - returneaza AB + AC+ BC
* area
* center - returneaza centrul de greutate al triunghiului
* isSimilar - returneaza 1 daca doua triunghiuri sunt asemenea, verificand daca doua unghiuri ale unui triunghi sunt egale cu doua unghiuri din al doilea
