#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define EXIT_SUCCESS 0
#define QUEUE_LENGTH 10

typedef struct Queue {
    int32_t end;
    int32_t data[QUEUE_LENGTH];    
}Queue;

int main(){
    Queue q;
    q.end = 0;
    
    q.data[q.end] = 1;
    q.end++;
    q.data[q.end] = 2;
    q.end++;

    printf("list size: %d\n", q.end);

    for(int i = 0; i < q.end; i++){
        printf("Pop %d \n", q.data[i]);
        q.data[i] = q.data[i + 1];
    }
    q.end--;

    for(int i = 0; i < q.end; i++){
        printf("List: %d", q.data[i]);
    }



    return EXIT_SUCCESS;
}