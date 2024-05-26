#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_NUME 50

typedef struct team{
    char* nume_echipa;
    float points;
    int pozitie;
}Echipa;

typedef struct Elem{
    Echipa val;
    struct Elem* next;
}Node;

typedef struct Q{
    Node* front;
    Node* rear;
}Queue;

typedef struct Graf{
    int** a;
}graph;


void task(FILE* , FILE* , FILE*);
Node* createTeamList(FILE* , int );
void addTeamAtBeginning(Node** , Echipa );
void enQueue(Queue *, Echipa );
Queue* createQueue();
Echipa deQueue(Queue* );
int isQueueEmpty(Queue* );
void deleteQueue(Queue* );
void playMatches(Queue* , Queue* , Queue* , graph* , FILE* , int , int , int);