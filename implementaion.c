#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue
{
    int front, rear;
    unsigned capacity;
    int *arr;
} Queue_t, *Queue;

Queue newQueue(unsigned capacity)
{
    
    Queue q = (Queue)calloc(1, sizeof(Queue_t));
    q->front = -1;
    q->capacity = capacity;
    q->rear = -1;
    q->arr = (int *)calloc(capacity, sizeof(int));
    // printf("done");

    return q;
}

void push(Queue q, int data)
{
    if (q->rear == (q->capacity - 1))
    {
        return ;
    }

    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[0] = data;
    }

    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
    // printf("done");
}

int pop(Queue q)
{
    // printf("%d\n",st->top);
    if (q->front == -1)
    {
        return -1;
    }

    else if (q->front == q->rear)
    {
        int ele = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        return ele;
    }

    else
    {
        int ele = q->arr[q->front];
        for (int i = 1; i <= q->rear; i++)
        {
            q->arr[i - 1] = q->arr[i];
        }
        q->rear--;
        return ele;
    }
}

int front(Queue q)
{
    return q->front>=0?q->arr[q->front]:-1;
}

void printQueue(Queue q)
{
    for (int i = 0; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    Queue q = newQueue(5);
    push(q,1);
    push(q,2);
    push(q,3);
    printf("%d \n",front(q));
    printQueue(q);
    pop(q);
    pop(q);
    pop(q);
    printf("%d \n",front(q));
    printQueue(q);
    push(q,4);
    push(q,5);
    printf("%d \n",front(q));
    printQueue(q);
    pop(q);
    printf("%d \n",front(q));
    printQueue(q);


}