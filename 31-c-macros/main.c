#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define EXIT_SUCCESS 0

typedef struct Node {
    int32_t value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front; // first node element 
    Node* rear; // last node element
} Queue;

void init_queue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

bool is_empty(Queue* q){
    return q->front == NULL;
}

void enqueue(Queue* q, int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node) return;
    new_node->value = value;
    new_node->next = NULL;
    if(is_empty(q)){
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(Queue* q){
    if(is_empty(q)){
        fprintf(stderr, "Empty queue\n");
        return NULL;
    }
    Node* temp = q->front;
    int value = temp->value;

    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int front(Queue* q){
    if(is_empty(q)){
        fprintf(stderr, "Fila vazia.\n");
        return -1;
    }
    return q->front->value;
}

void free_queue(Queue* q){
    while(!is_empty(q)){
        dequeue(q);
    }
}

int main() {
    Queue q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Front: %d\n", front(&q));
    
    while(!is_empty(&q)){
        printf("Removido: %d\n", dequeue(&q));
    }

    free_queue(&q);

    return EXIT_SUCCESS;
}