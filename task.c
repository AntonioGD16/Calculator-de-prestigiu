#include "struct.h"


float calculatePr(int l, int r, float q){
    float putereaR = pow(2.0 - q, r);
    float putereaL = pow(2.0 - q, l);
    
    float numarator = q * putereaR;
    float numitor = pow(2.0, l) + putereaL * (q - 1.0);
    
    return numarator/numitor;
}

void playMatches(Queue* q, Queue* winnersQueue, Queue* losersQueue, graph* G, FILE* fout, int i, int nr_runde, int nr_echipe, int l, float Q){
    while(!isQueueEmpty(q)){
        // Extragem primele doua echipe din coada pentru un meci
        Echipa echipa1 = deQueue(q);
        Echipa echipa2 = deQueue(q);

        // Simularea meciului si actualizarea prestigiului
        if(echipa1.points > echipa2.points){
            echipa1.victorii++;
            echipa1.prestigiu = calculatePr(l, echipa1.victorii, Q);
            echipa2.prestigiu = calculatePr(l, echipa2.victorii, Q);
            enQueue(losersQueue, echipa2);
            enQueue(winnersQueue, echipa1);
            G->a[echipa2.pozitie][echipa1.pozitie] = 1;

        } 
        else if(echipa1.points < echipa2.points){
            echipa2.victorii++;
            echipa2.prestigiu = calculatePr(l, echipa2.victorii, Q);
            echipa1.prestigiu = calculatePr(l, echipa1.victorii, Q);
            enQueue(winnersQueue, echipa2);
            enQueue(losersQueue, echipa1);
            G->a[echipa1.pozitie][echipa2.pozitie] = 1;
        }
        else if(echipa1.points == echipa2.points){
            if(strcmp(echipa1.nume_echipa, echipa2.nume_echipa) > 0){
                echipa1.victorii++;
                echipa1.prestigiu = calculatePr(l, echipa1.victorii, Q);
                echipa2.prestigiu = calculatePr(l, echipa2.victorii, Q);
                enQueue(winnersQueue, echipa1);
                enQueue(losersQueue, echipa2);
                G->a[echipa2.pozitie][echipa1.pozitie] = 1;
            }
            else if(strcmp(echipa1.nume_echipa, echipa2.nume_echipa) <= 0){
                echipa2.victorii++;
                echipa2.prestigiu = calculatePr(l, echipa2.victorii, Q);
                enQueue(winnersQueue, echipa2);
                enQueue(losersQueue, echipa1);
               G->a[echipa1.pozitie][echipa2.pozitie] = 1;
            }
        }
    }
}

void task(FILE* fin, FILE* fout1, FILE* fout2){
    Node* head = NULL;
    head = createTeamList(fin, NR_ECHIPE);
    Node* hc = head;
    
    int nr_runde = (int)log2(NR_ECHIPE);
    
    graph* G = malloc(sizeof(graph));
    G->a = (int**)calloc(NR_ECHIPE, sizeof(int*));
    for(int i = 0; i < NR_ECHIPE; i++){
        G->a[i] = (int*)calloc(NR_ECHIPE, sizeof(int));
    }
    
    Queue* q = createQueue();
    Stack* temp;
    createStack(temp);
    hc = head;
    while(hc->next != NULL){
       push(temp, hc->val);
       hc = hc->next;
    }

    while(!isStackEmpty(*temp)){
        Echipa aux = pop(temp);
        enQueue(q, aux);
    }
    deleteStack(&temp->top);
    
    Queue* winnersQueue = createQueue();
    Queue* losersQueue = createQueue();
    int l = nr_runde + 1;
    float Q = 0.15;
    for(int i = 0; i < nr_runde; i++){
        playMatches(q, winnersQueue, losersQueue, G, fout1, i, nr_runde, NR_ECHIPE, l, Q);
        while(!isQueueEmpty(winnersQueue)){
            Echipa aux = deQueue(winnersQueue);
            enQueue(q, aux);
        }
    }

    for(int i = 0; i < NR_ECHIPE; i++){
        for(int j = 0; j < NR_ECHIPE; j++){
            fprintf(fout1, "%d ", G->a[i][j]);
        }
        fprintf(fout1, "\n");
    }

    while(!isQueueEmpty(losersQueue)){
        Echipa aux = deQueue(losersQueue);
        fprintf(fout2, "%.4f %s\n", aux.prestigiu, aux.nume_echipa);
    }

    fprintf(fout2, "%.4f %s\n", q->front->val.prestigiu, q->front->val.nume_echipa); // afisam si echipa castigatoare

    deleteQueue(q);
    deleteQueue(winnersQueue);
    deleteQueue(losersQueue);
    while(head != NULL){
        free(head);
        head = head->next;
    }
}

