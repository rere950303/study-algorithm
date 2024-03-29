//
//  ArrayIntQueue.c
//  4.3(p144)
//
//  Created by hyungwook on 2021/03/08.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

int Initialize(ArrayIntQueue *q, int max)
{
    q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL)
    {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(ArrayIntQueue *q, int x)
{
    if (q->num >= q->max)
        return -1;
    else {
        q->que[q->num++] = x;
        return 0;
    }
}

int Deque(ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)
        return -1;
    else
    {
        *x = q->que[0];
        for(int i = 0; i < q->num - 1; i++)
        {
            q->que[i] = q->que[i + 1];
        }
        (q->num)--;
        return 0;
    }
}

int Peek(const ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)
        return -1;
    *x = q->que[q->num - 1];
    return 0;
}

int Capacity(const ArrayIntQueue *q)
{
    return q->max;
}

int Size(const ArrayIntQueue *q)
{
    return q->num;
}

void Print(const ArrayIntQueue *q)
{
    int i;

    for (i = 0; i < q->num; i++)
        printf("%d ", q->que[i]);
    putchar('\n');
}

void Terminate(ArrayIntQueue *q)
{
    if (q->que != NULL)
        free(q->que);
    q->max = q->num = 0;
}
