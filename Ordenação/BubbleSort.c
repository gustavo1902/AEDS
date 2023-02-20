//Data:06/10/22
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int piItem[], int iQtdElementos)
{
    register int i,j;
    register int iAux;
    _Bool bTroca;
    for(i=1;i<iQtdElementos;i++)
    {
        bTroca = 0;//falso
        for(j=iQtdElementos-1;j>=i;j--)
        {
            if(piItem[j-1]>piItem[j])
            {
                iAux = piItem[j-1];
                piItem[j-1] = piItem[j];
                piItem[j] = iAux;
                bTroca = 1; //verdadeiro
            }
        }
        if(!bTroca)
            {
                return;
            }
    }
    return;
}

int main(void)
{
    int iContador;
    //int aBubble[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int aBubble[10];
    srand(time(NULL));
    bubble(aBubble, 10);
    printf("Ordenado: ");
    for(iContador = 0; iContador <10; iContador++)
    {
        aBubble[iContador] = rand()%100;
        printf("%d ", aBubble[iContador]);
    }
    printf("\n");
    return 0;
}