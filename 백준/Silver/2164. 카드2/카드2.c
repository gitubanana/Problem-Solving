#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX 500001

typedef struct s_queue
{
    int arr[MAX];
    int head;
    int tail;
}   t_queue;

void    enqueue(t_queue *queue, int data)
{
    queue->arr[queue->tail] = data;
    queue->tail = (queue->tail + 1) % MAX;
}

int dequeue(t_queue *queue)
{
    int ret;

    ret = queue->arr[queue->head];
    queue->head = (queue->head + 1) % MAX;
    return (ret);
}

void    init_queue(t_queue *queue, int n)
{
    queue->head = queue->tail = 0;
    for (int i = 0; i < n; i++)
        enqueue(queue, i + 1);
}

void    print_queue(t_queue *queue)
{
    for (int i = queue->head; i < queue->tail; i++)
        printf("%d ", queue->arr[i]);
    printf("\n");
}

int    main(void)
{
    int     n;
    t_queue queue;

    scanf("%d", &n);
    if (n == 1)
    {
        printf("1");
        return (0);
    }
    init_queue(&queue, n);
    while (1)
    {
        queue.head++; // 카드 하나 버리고
        if (queue.head + 1 == queue.tail)
            break ;
        enqueue(&queue, dequeue(&queue));
        // print_queue(&queue);
    }
    printf("%d", queue.arr[queue.head]);
    return (0);
}

