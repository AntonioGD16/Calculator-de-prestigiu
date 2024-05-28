#include "struct.h"


void createStack(Stack* stack){
    stack->top = NULL;
}

int isStackEmpty(Stack stack){
	return stack.top == NULL;
}
	
void deleteStack(Node** top){
	Node* temp;
	while((*top)!=NULL){
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}	

Echipa pop(Stack* stack){
	Echipa aux;
	if (isStackEmpty(*stack)){
		aux.pozitie = 0;
		aux.nume_echipa = NULL;
		aux.points = 0.0;
        aux.victorii = 0;
        aux.prestigiu = 0;
		return aux;
	}	 
	Node* temp = stack->top;  		
	aux.nume_echipa = strdup(temp->val.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    if(aux.nume_echipa == NULL){
    	exit(1);
    }
    aux.pozitie = temp->val.pozitie;
    aux.points = temp->val.points;	
    aux.prestigiu = temp->val.prestigiu;
    aux.victorii = temp->val.victorii;		
	stack->top = stack->top->next;      		
	free(temp);
	return aux;
}

void push(Stack* stack, Echipa team){
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
	newNode->val.victorii = team.victorii;
	newNode->val.prestigiu = team.prestigiu;
	newNode->next = stack->top;
	stack->top = newNode;
}
