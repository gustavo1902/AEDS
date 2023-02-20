//Ordenação MergeSort
//Autor: Gustavo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int v[], int inicio, int fim)
{
    int i, j, k, meio,*auxiliar;
    if(inicio == fim)
    {
        return;
    } 
    //ordenação recursiva das duas metades
    meio = (inicio + fim)/2;
    mergesort(v, inicio, meio);
    mergesort(v, meio+1, fim);
    //intercalação no vetor auxiliar
    i = inicio;
    j = meio + 1;
    k = 0;
    auxiliar = (int*)malloc(sizeof(int)*(fim-inicio+1));
    while(i < meio + 1 || j < fim + 1)
    {
        if(i == meio + 1)
        {
            auxiliar[k] = v[j];
            j++;
            k++;
        }
        else
        {
            if(j == fim + 1)
            {
                auxiliar[k] = v[i];
                i++;
                k++;
            }
            else
            {
                if(v[i] < v[j])
                {
                    auxiliar[k] = v[i];
                    i++;
                    k++;
                }
                else
                {
                    auxiliar[k] = v[j];
                    j++;
                    k++;
                }
            }
        }
    }
    //copia vetor intercalado para o vetor original
    for(i = inicio; i <= fim; i++)
    {
        v[i] = auxiliar[i-inicio];
    }
    free(auxiliar);
    return;
}
int main(void)
{
    int iContador;
    //int aMerge[] = {5, 9, 8, 4, 3, 1, 2, 7, 6};    //com vetor definido no programa
    /*int i;
    int aMerge[10];
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &aMerge[i]);
    }*/   //com vetor definido pelo usuário
    int aMerge[10];
    int i;
    srand(time(NULL));
    for(i = 0; i < 10; i++)
        aMerge[i] = rand() % 100;
    
    mergesort(aMerge, 0, 9);
    
    printf("Primeiro vetor ordenado: ");
    for(iContador = 0; iContador < 9; iContador++)
    {
        printf("%d ", aMerge[iContador]);
    }
    printf("\n");
    
   
/*
    int bMerge[] = {50, 100, 20, 30, 70};
    mergesort(bMerge, 0, 5);
     printf("Segundo vetor ordenado: ");
    for(iContador = 0; iContador < 5; iContador++)
    {
        printf("%d ", bMerge[iContador]);
    }
    printf("\n");
    */

    return 0;
}