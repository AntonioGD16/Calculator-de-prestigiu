#include "struct.h"


Queue* createQueue(){
	Queue* q;
	q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL){
		exit(1);
	}	
	q->front = q->rear = NULL;
	return q;	
}

void enQueue(Queue *q, Echipa team){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        exit(1);
    }
    newNode->val.nume_echipa = strdup(team.nume_echipa);  //folosim functia strdup pt a aloca memorie si pt a copia continutul
	if(newNode->val.nume_echipa == NULL){
        exit(1);
    }
	newNode->val.points = team.points;
    newNode->val.pozitie = team.pozitie;
	newNode->val.victorii = team.victorii;
	newNode->val.prestigiu = team.prestigiu;
    newNode->next = NULL;

    if(isQueueEmpty(q)){
        q->front = q->rear = newNode;
    } 
	else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
 
Echipa deQueue(Queue* q){  
	Node* aux;
	Echipa team;
	Echipa emptyTeam;
	emptyTeam.points = 0.0;
	emptyTeam.nume_echipa = NULL;
	if(isQueueEmpty(q)) 
		return emptyTeam;
	
	aux = q->front; 
	team.points = aux->val.points;
	team.nume_echipa = strdup(aux->val.nume_echipa);
    team.pozitie = aux->val.pozitie;
	team.prestigiu = aux->val.prestigiu;
	team.victorii = aux->val.victorii;
	if(team.nume_echipa == NULL){
    	exit(1);
    }

	q->front = (q->front)->next;
	free(aux);
	return team;  	
} 

int isQueueEmpty(Queue* q){
	return (q->front == NULL);
}

void deleteQueue(Queue* q){
	Node* aux;
	while(!isQueueEmpty(q)){
		aux = q->front;
		q->front = q->front->next;
		free(aux);
	}
	free(q);
}