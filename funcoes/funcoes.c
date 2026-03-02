#include "funcoes.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


void carregarArquivo(char path[])
{
}

int buscarElemento(int vet[], int n, int opc, int x)
{
    if (opc == 1) {
        //  busca linear
        for(int i = 0; i < n; i++)
        {
            if(vet[i] == x)
            {
                printf("Elemento enconitrado!");
                return;
            }
        }

    } else if (opc == 2) {
        // busca binária



    } else {
        printf("Opcao de busca invalida.\n");
    }
}

void ordernarDados(int vet[], int n)
{


}

void gerarRelatorio()
{
   
}

void BubbleSort(int vet[], int n)
{
    int i, j;

    for(i = 0; i < n-1; i++)
    {
        bool troca = false;

        for(j = 0; j < (n-1) - i; j++)
        {
            if (vet[j] > vet[j + i])
            {
                int temp = vet[j];

                vet[j] = vet[j + 1];
                vet[j + 1] = temp; 

                troca = true;
            }
        }

        // se não houve troca, rompe o laço
        if (!troca)
        {
            break;
        }
    }
}

void InsertSort (int vet[], int n)
{
    int i, key, j;

    for (i = 0; i < n-1; i++)
    {
        // novo elemento a ser inserido
        key = vet[i];

        j = i - 1;

        // elementos maiores que a key vão ser movidos para direita
        while(j >= 0 && vet[j] > key)
        {
            vet[j + 1] = vet[j];
            j = j - 1;  
        }

        // a key será colocada na posição certa
        vet[j + 1] = key;
    }
}

void SelectionSort(int vet[], int n)
{
    int i, j, menor, troca;

    for (i = 0; i < n - 1; i++)
    {
        menor = i;

        // Encontra o menor elemento
        for (j = i + 1; j < n; j++)
        {
            if (vet[j] < vet[menor])
            {
                menor = j;
            }
        }
       
        // Troca o menor elemento econtrado para a posicao mais a esquerda
        if (menor != i)
        {
            troca = vet[i];
            vet[i] = vet[menor];
            vet[menor] = troca;
        }
    }
}

void MergeSort(int vet[], int inicio, int fim){

    
    int inicio = 0, fim = 0, meio;

    //esqueleto, usar alocaçao dinamica
    // declarando o tamanho de fim.
    for (int i = 0; i < fim; i++)
    {
        fim++;
    }
    
    if (inicio < fim)
    {
        meio = floor((inicio+fim )/2);
        Mergesort(vet, inicio, fim );
        Mergesort(vet, meio+1, fim );
        Merge(vet, inicio, meio, fim);
    }
    
}


void Merge(int vet[], int inicio, int meio, int fim)
{
    int *VetAux, M1, M2, tam, i, j, k;
    int fim1 = 0, fim2 = 0 ;
    tam = fim1 - inicio+1;

    M1 = inicio;
    M2 = meio+1;

    VetAux = (int*)malloc(tam*sizeof(int));
    if (tam != NULL) 
    {
        for ( i = 0; i < tam; i++)
        {
            if (!fim1 && !fim2)
            {
                if (vet[M1] < vet[M2])
                {
                    VetAux[i] = vet[M1++];
                }
                else
                {
                    VetAux[i] = vet[M2++];
                }
                if(M1>meio) fim1=1;
                if(M2>fim) fim2=1;
                
            }

            // se ainda houver algum elemento nos vetores (M1 e M2), o elemento sera inserido no vetor 
            else 
            {
                if (!fim)
                {
                    VetAux[i] = vet[M1++];
                }    
                else 
                {
                    VetAux[i] = vet[M2++];
                    
                }
            }
        }
        
        // copia do auxiliar e passa para o definitivo
        for (j = 0, k = inicio; j < tam; j++, k++)
        {
         vet[k] = VetAux[j];   
        }

        free(VetAux);
    }
    
}

void QuickSort(int vet[], int inicio, int fim)
{
    // sleciona o pivo e retorna a função quickc
    int pivo;
    if (fim > inicio)
    {
        pivo = Particiona(vet, inicio, fim);
        QuickSort(vet, inicio, pivo -1);
        QuickSort(vet, pivo+1, fim );        
    }
    
}

int Particiona(int vet[], int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = vet[inicio];
    
    while (esq < dir)
    {
        // esq anda para a direita
        while(esq <= fim && vet[esq] <= pivo)
        {
            esq++;
        }

        // dir retrocede a posicao para esquerda
        while(dir > inicio && vet[dir] > pivo)
        {
            dir--;
        }

        // troca o elemento da esquerda com o elemento da direita
        if (esq > dir)
        {
            troca(esq, dir);
        }
    }

    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}