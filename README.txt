Enache Anca- Mihaela 314CD

Pentru aceasta tema am folosit trei biblioteci C: stdio.h, string.h, 
stdlib.h, cea din urma folosita pentru functia "atoi";

Am realizat sapte functii pentru a avea un cod modular: center, align_left,
align_right, justify, paragraphs, lists, ordered_lists, toate fiind de tip
void;

1. Functia center folosește ca referință cea mai lungă linie din fișier și
adaugă spații la începutul liniilor care sunt mai scurte pentru a le centra.
Am facut acest lucru prin identificarea lungimii maxime si apoi fiecare rand,
salvat in vectorul auxiliar "rand",ce continea caractere a fost mutat spre 
dreapta cu un numar de spatii egal cu diferenta dintre lungimea maxima si 
lungimea randului plus unu, impartitla doi. Iar rezultatul a fost mutat in 
matricea "original".

2. Functia align_left aliniază liniile precizate la marginea din stânga. 
Fiecare rand ce continea caractere este parcurs pana la intalnirea primului
caracter si in acelasi timp se numara spatiile existente sau taburile. Avand
in contor salvata o valoare realizam copierea partiala( fara spatiile de 
inceput) a randului intr-un vector auxiliar si apoi in matricea originala.

3. Functia align_right folosește ca referință cea mai lungă linie din fișier 
și adaugă spații la începutul liniilor care sunt mai scurte pentru a le 
alinia la marginea din dreapta. Am identificat lungimea maxima si apoi 
fiecare rand, salvat in vectorul auxiliar "rand",ce continea caractere a 
fost mutat spre dreapta cu un numar de spatii egal cu diferenta dintre 
lungimea maxima si lungimea randului. Iar rezultatul a fost mutat in 
matricea "original".

4. Functia justify folosește ca referință cea mai lungă linie din fișier și 
distribuie în mod echilibrat spații în interiorul liniilor mai scurte pentru 
ca acestea să ajungă la aceeași lungime și să fie aliniate atât la dreapta, 
cât și la stânga. Am identificat lungimea maxima, apoi am parcurs matricea
rand cu rand, am creat si doua cazuri speciale. Atunci cand indicele este 
egal cu start i- ul creste, cand indicele este egal cu original_line_count 
linia ramane neschimbata( linie ce a fost ulterior aliniata cu functia 
align_left) si un rand liber ramane de asemenea la fel. In rest, creez o 
copie in vectorul auxiliar "rand" si folosesc o bucla ce are conditie 
lungimea maxima pe care o poate atinge randul. Pentru fiecare spatiu pe 
care- l gasesc, fac loc in vector si inserez spatiul.

5. Functia paragraphs realizează indentarea paragrafelor din intervalul 
precizat , cu indent_length spații. Parcurg matricea rand cu rand, pentru 
cazul in care i = 0(primul rand) indentez, inserand numarul de spatii dat,
iar in rest caut randurile ce contin doar '\n' si randul ce urmeaza il 
indentez cu numarul de spatii dat.

6. Functia lists formatează liniile corespunzătoare ca pe o listă (aliniată 
la stânga) a cărei indici sunt definiți în funcție de parametrii list_type
și special_character. Pentru listele numerotate folosesc functia spritf si 
realizez doua cazuri, unul pentru cifre si unul pentru numere de doua cifre.
In final mutand rezultatul in matricea "original". La lista alfabetica cu 
litere mici ma folosesc de strcpy pentru a formata liniile, realizand un caz 
separat pentru liniile goale( lucru facut dupa ce am verificat testele 
combinate). La lista alfabetica cu litera mare este folosita aceeasi gandire
ca la cea precedenta, diferenta este ca variabila de tip char, litera ia 
valoarea 'A' si creste cu fiecare linie. La bullet list ma folosesc de strcat 
pentru a formata liniile.

7. Functia ordered_lists contine doar ordonarea alfabetica sau invers 
alfabetica, restul formatarii fiind realizata cu ajutorul functiei precedente.
Pentru ambele ordonari am facut doua cazuri. Primul fiind destinat intregului
text, iar cel de- al doilea doar portiunii [start,end]. Compararea randurilor
o fac cu strcmp, iar interschimbarea lor cu ajutorul unui vector auxiliar si
al functiei strcpy.

In main, citirea din fisier, introducerea datelor in matrice, respectiv 
scrierea in fisier este realizata cu ajutorul scheletului sugerat.

Argumentele din argv[1] le introduc prima data intr- un vector, pe care il 
impart cu ajutorul functiei strtok dupa ","(virgula) in comenzi pe care le 
introduc in matricea ARGS. Pe aceasta o parcurg cu ajutorul unui for. Din 
fiecare comanda extrag primul element cu ajutorul lui strtok, element ce
reprezinta de fapt litera corespunzatoare comenzii. Cu litera stocata in 
pointer-ul litera o sa intru in urmatoarele 8 if-uri, fiecare corespunzand
unei operatii.

In fiecare if identific argumentele specifice fiecarei comenzi, verific
erorile ce pot aparea dupa aflarea valorilor argumentelor si apelez functiile.

In primul if, destinat comenzii wrap, se afla si rezolvarea acesteia, deoarece
mi- a facut probleme la rularea in checker.Folosind strtok- ul descopar 
urmatorul element din sir si il transform in intreg cu ajutorul functiei
atoi, rezultand max_line_length. Pentru a realiza operatia wrap ce adauga 
caractere \n(new line), pentru a respecta limita, am folosit o matrice 
auxiliara. Am parcurs matricea originala rand cu rand. Salvand fiecare rand
pe rand in vectorul auxiliar "rand" pentru a putea realiza fara probleme
operatiile necesare. In caz ca vectorul "rand" continea doar caracterul
"\n" contorul ce-mi retine lungimea( length) se face 0, inserez pe ultima 
pozitie din rand caracterul \n, pentru a elimina spatiul si pentru a schimba
linia, iar pe randul ce l-am descoperit a fi gol inseres "\n", pentru a-l 
pastra neschimbat. Daca nu intalnesc rand gol decupez primul cuvant si 
realizez un while ce contine si verificarea lungimii cuvantului, respectiv
afisarea erorii "Cannot wrap!" cat si inserarea cuvintelor pe rand pana cand
se atinge lungimea dorita. Realizez un if cu doua ramuri pe prima ramura se
intra daca lungimea actuala a randului nu depaseste limita si concateneaza
la randul deja existent cuvantul si spatiul, lungimea actuala crescand cu 1
pentru spatiul adaugat, iar pe a doua ramura intra in caz contrar, punand
pe ultima pozitie a randului "\n", eliminand spatiul pus ulterior si schimband
linia, se reinitializeaza lungimea actuala(length) cu 0 si se adauga cuvantul
si spatiul, la lungimea actuala adaugandu- se lungimea cuvantului si 1 pentru
spatiu. Cand se iese din if se decupeaza urmatorul cuvant. Dupa parcurgerea
tuturor cuvintelor se insereaza pe ultima pozitie "\n" si se incheie matricea
prin inserarea "\0". Original_line_count isi schimba valoarea. In final
copiez rezultatul din matricea auxiliara in cea originala.

In if-ul destinat comenzii center, la fel ca la align_left, align_right si 
justify, decupez din comanda urmatoarele doua elemente si daca exista le 
transform in intreg cu ajutorul functiei atoi, rezultand variabilele start 
si end. De asemenea verific erorile ce ar putea sa apara, posibila existenta
a unui argument in plus, valoarea lui start sa fie mai mare ca end, s.a.m.d.
Si apelez functiile specifice.

In plus la justify, inainte de a apela functia cu acelasi nume, apelez functia
align_left.

In if-ul destinat comenzii paragraphs, decupez din comanda urmatoarele 3 
elemente, ultimele 2 nefiind obligatorii, in caz ca primul element, indent
length nu exista se iese, nerealizandu- se nicio schimbare asupra matricei.
In final apelez functia specifica.

In if-ul destinat comenzii lists, la fel ca la ordered_lists, cea din urma 
avand in plus parametrul ordering, decupez, retin si transform urmatoarele
elemente: list_type, special_character, ordering(doar pentru listele ordonate),
start si end. In final apelez functiile align_left si lists pentru liste si
ordered_lists, align_left si lists pentru listele ordonate.







