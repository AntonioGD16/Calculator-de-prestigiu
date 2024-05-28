#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_NUME 50
#define NR_ECHIPE 32


// Structurile folosite
typedef struct team{
    char* nume_echipa;
    float points;
    int pozitie;
    int victorii;
    float prestigiu;
}Echipa;

typedef struct Elem{
    Echipa val;
    struct Elem* next;
}Node;

typedef struct Q{
    Node* front;
    Node* rear;
}Queue;

typedef struct stiva{
        Node* top;
}Stack;

typedef struct Graf{
    int** a;
}graph;

// Functiile folosite pentru rezolvarea task-ului
void playMatches(Queue* , Queue* , Queue* , graph* , FILE* , int , int , int, int, float);
float calculatePr(int , int , float );
void task(FILE* , FILE* , FILE*);

// Functii pentru liste
Node* createTeamList(FILE* , int );
void addTeamAtBeginning(Node** , Echipa );

// Functii pentru cozi
void enQueue(Queue *, Echipa );
Queue* createQueue();
Echipa deQueue(Queue* );
int isQueueEmpty(Queue* );
void deleteQueue(Queue* );

// Functii pentru stive
void push(Stack* , Echipa );
Echipa pop(Stack* );
int isStackEmpty(Stack );
void createStack(Stack* );
void deleteStack(Node** );
