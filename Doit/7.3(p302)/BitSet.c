//
//  BitSet.c
//  7.3(p302)
//
//  Created by hyungwook on 2021/03/13.
//

#include <stdio.h>
#include "BitSet.h"

int IsMember(BitSet s, int n)
{
    return s & SetOf(n);
}

void Add(BitSet *s, int n)
{
    *s |= SetOf(n);
}

void Remove(BitSet *s, int n)
{
    *s &= ~SetOf(n);
}

int Size(BitSet s)
{
    int n = 0;
    for (; s != BitSetNull; n++)
        s &= s - 1;
    return n;
}

void Print(BitSet s)
{
    int i;
    printf("{ ");
    for (i = 0; i < BitSetBits; i++)
        if (IsMember(s, i))
            printf("%d ", i);
    printf("}");
}

void PrintLn(BitSet s)
{
    Print(s);
    putchar('\n');
}
