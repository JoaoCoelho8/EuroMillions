#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int uniforme(int rand_min_val, int rand_max_val);
void geraAleatoriosSemRepetidos();
void printArray(int v[], int n);
void bubbleSortMelhorado(int v[], int n);


int main()
{
    srand((unsigned)time(NULL));
    geraAleatoriosSemRepetidos();

    return 0;
}

void printArray(int v[], int n)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        printf("\n%d\n",v[i]);
    }
}

void bubbleSortMelhorado(int v[], int n)
{
    int i=0,pass=0,aux=0,ha_troca=1;
    for(pass=1; pass<n; pass++)
    {
        ha_troca=0;
        for(i=0; i<n-pass; i++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                ha_troca=1;
            }
            else
            {
                ha_troca=0;
            }
        }
        if(ha_troca==0)
            break;
        else
            continue;
    }
}

int uniforme(int rand_min_val, int rand_max_val)
{
    return rand_min_val+(rand()%rand_max_val);
}

void geraAleatoriosSemRepetidos()
{
    int euromilhoes_numeros[5], euromilhoes_estrelas[2];
    int i=0,val=0,val1=0;

    for(i=0; i<5; i++)
    {
        euromilhoes_numeros[i]=uniforme(1,50);

        if(i>0)
        {
            if(euromilhoes_numeros[i]==euromilhoes_numeros[i-1])
            {
                val=uniforme(1,50);
                if(val!=euromilhoes_numeros[i])
                {
                    euromilhoes_numeros[i]=val;
                }
            }
        }
    }
    printf("Numeros\n");
    bubbleSortMelhorado(euromilhoes_numeros,5);
    printArray(euromilhoes_numeros,5);

    for(i=0; i<2; i++)
    {
        euromilhoes_estrelas[i]=uniforme(1,11);

        if(i>0)
        {
            if(euromilhoes_estrelas[i]==euromilhoes_estrelas[i-1])
            {
                val1=uniforme(1,11);
                if(val1!=euromilhoes_estrelas[i])
                {
                    euromilhoes_estrelas[i]=val1;
                }
            }
        }
    }
    printf("\nEstrelas\n");
    bubbleSortMelhorado(euromilhoes_estrelas,2);
    printArray(euromilhoes_estrelas,2);
}
