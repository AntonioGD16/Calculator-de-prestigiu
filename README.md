Aplicatia este alcatuita din 7 fisiere si este folosita pentru a calcula prestigiul unui meci castigat si pentru a genera graful meciurilor.

Fisierul header struct.h in care am definit toate structurile si toate prototipurile functiilor pe care le-am folosit.

Fisierul main.c care este partea principala a aplicatiei unde se deschid fisierele necesare si se apeleaza functia care rezolva cerinta.

Fisierul task.c este folosit pentru a rezolva toate cele 2 cerinte. In acest fisier gasim toate functiile care rezolva problema.
- Functia task creaza o lista cu echipele din fisier, un graf caruia i se aloca memorie pentru matricea de adiacenta si in care se pune 0 pe fiecare pozitie, o coada in care vom pune aceste echipe dupa ce le punem intr-o stiva temporara pentru a le ordona, o coada pentru castigatori si o coada pentru invinsi. Cu ajutorul functiei playMatches, vom simula meciurile dintre echipe, luand din coada cu echipe cate 2 echipe si comparandu-le punctele. In cazul in care echipele au acelasi punctaj, ele vor fi comparate dupa nume in ordine alfabetica descrescatoare. Dupa ce am comparat echipele, echipei castigatoare ii creste numarul de victorii cu 1 si se calculeaza prestigiul ambelor echipe cu ajutorul unei formule. Acest prestigiu este calculat cu ajutorul functiei calculatePr. Dupa ce am calculat prestigiul, punem echipa castigatoare in coada castigatorilor si cea invinsa in coada pierzatorilor, urmand ca dupa sa actualizam matricea de adiacenta a grafului cu 1 pe pozitia ij, unde i este echipa invinsa si j este echipa castigatoare. Dupa ce am terminat de simulat toate meciurile afisam intr-un fisier de output matricea de adiacenta a grafului si in alt fisier de output echipele si prestigiul lor in ordine crescatoare in functie de cand au fost eliminate.

Fisierul liste.c contine toate functiile pe care le-am folosit pentru a lucra cu liste, cum ar fi: createTeamList, addTeamAtBeggining.

Fisierul cozi.c contine toate functiile pe care le-am folosit pentru a lucra cu cozi, cum ar fi: enQueue, deQueue, isQueueEmpty etc.

Fisierul stive.c contine toate functiile pe care le-am folosit pentru a lucra cu stive, cum ar fi: push, pop, isStackEmpty etc.

Fisierul Makefile in care sunt comenzile din Linux care compileaza toate aceste fisiere si creeaza fisierul obiect care poate fi executat si care sterge fisierul obiect dupa ce acesta isi termina executia.
