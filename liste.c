#include "struct.h"


void addTeamAtBeginning(Node** head, Echipa team){
	Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
    	exit(1);
    }
    newNode->val.nume_echipa = strdup(team.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    if(newNode->val.nume_echipa == NULL){
    	exit(1);
    }
    newNode->val.points = team.points;
    newNode->val.pozitie = team.pozitie;
    newNode->next = *head;
    *head = newNode;
}


Node* createTeamList(FILE* fin, int nr_echipe){
	Node* head;
	head = (Node*)malloc(sizeof(Node)); //alocam memorie pt capul listei si verificam daca alocarea a reusit
    if(head == NULL){
    	exit(1);
    }
    head->next = NULL;

    Echipa* teams;
    teams = (Echipa*)malloc(nr_echipe * sizeof(Echipa));
    if(teams == NULL){
        exit(1);
    }

    int i;
    char buff[MAX_NUME];
    for(i = 0; i < nr_echipe; i++){
        fscanf(fin, "%f", &teams[i].points);
        getc(fin); //luam enter-ul dintre numarul participantilor din echipa si numele echipei
        fscanf(fin, "%[^\n]", buff); // punem stringul  in buffer pana la intalnirea lui \n 
        int len = strlen(buff); // aflam lungimea stringului
        buff[len] = '\0'; // adagugam \0 la finalul stringului
        if(buff[len - 1] == ' ')
            buff[len - 1] = '\0'; // adagugam \0 la finalul stringului care are spatiu alb
        teams[i].nume_echipa = strdup(buff); // alocam memorie si copiem ce e in buff in teams[i].nume_echipa
        teams[i].pozitie = i;
        addTeamAtBeginning(&head, teams[i]);  // adaugam echipa la inceputul listei
    }
    return head;
}