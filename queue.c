#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue {
    int front, rear;
    int data[SIZE];
};

typedef struct queue QUEUE;

void enqueue(QUEUE *q, int item) {
    if (q->rear == SIZE - 1) {
        printf("\nQueue Overflow! Cannot insert.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = item;
    printf("\nInserted element: %d\n", item);
}

void dequeue(QUEUE *q) {
    if (q->front == -1) {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }
    printf("\nDeleted element is %d\n", q->data[q->front]);
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

void display(QUEUE q) {
    int i;
    if (q.front == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue contents are:\n");
        for (i = q.front; i <= q.rear; i++) {
            printf("%d\t", q.data[i]);
        }
        printf("\n");
    }
}

int main() {
    int item, ch;
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
