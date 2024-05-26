#include "struct.h"


void playMatches(Queue* q, Queue* winnersQueue, Queue* losersQueue, graph* G, FILE* fout, int i, int nr_runde, int nr_echipe){
    
    while(!isQueueEmpty(q)){
        // Extrage primele două echipe din coadă pentru un meci
        Echipa echipa1 = deQueue(q);
        Echipa echipa2 = deQueue(q);

        // Simularea meciului și actualizarea punctajelor
        if(echipa1.points > echipa2.points){
            enQueue(winnersQueue, echipa1);
            enQueue(losersQueue, echipa2);
            G->a[echipa2.pozitie][echipa1.pozitie] = 1;
        } 
        else if(echipa1.points < echipa2.points){
            enQueue(winnersQueue, echipa2);
            enQueue(losersQueue, echipa1);
            G->a[echipa1.pozitie][echipa2.pozitie] = 1;
        }
        else if(echipa1.points == echipa2.points){
            if(strcmp(echipa1.nume_echipa, echipa2.nume_echipa) > 0){
                enQueue(winnersQueue, echipa1);
                enQueue(losersQueue, echipa2);
                G->a[echipa2.pozitie][echipa1.pozitie] = 1;
            }
            else
                enQueue(winnersQueue, echipa2);
                enQueue(losersQueue, echipa1);
               G->a[echipa1.pozitie][echipa2.pozitie] = 1;
        }
    }
}

void task(FILE* fin, FILE* fout1, FILE* fout2){
    Node* head = NULL;
    head = createTeamList(fin, 32);
    Node* hc = head;
    int nr_echipe = 32; // sa fac cumva sa scot nr de echipe
    int nr_runde = (int)log2(nr_echipe);
    graph* G = malloc(sizeof(graph));
    G->a = (int**)calloc(nr_echipe, sizeof(int*));
    for(int i = 0; i < nr_echipe; i++){
        G->a[i] = (int*)calloc(nr_echipe, sizeof(int));
    }
    
    Queue* q = createQueue();
    hc = head;
    while(hc->next != NULL){
       enQueue(q, hc->val);
       hc = hc->next;
    }

    Queue* winnersQueue = createQueue();
    Queue* losersQueue = createQueue();
    for(int i = 0; i < nr_runde; i++){
        playMatches(q, winnersQueue, losersQueue, G, fout1, i, nr_runde, nr_echipe);
        while(!isQueueEmpty(losersQueue)){
            deQueue(losersQueue);
        }
        while(!isQueueEmpty(winnersQueue)){
            Echipa aux = deQueue(winnersQueue);
            enQueue(q, aux);
        }
    }

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            fprintf(fout1, "%d ", G->a[i][j]);
        }
        fprintf(fout1, "\n");
    }
}