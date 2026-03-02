#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int main()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER inicio, fim;
    double elapsedtime;
    
    
    int opc;
    bool sair = false;
    bool arquivo = false;
    bool opc3 = false;
    char path[50];

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&inicio);
    
    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Carregar arquivo de dados\n");
        printf("2. Buscar elemento (linear ou binaria)\n");
        printf("3. Ordenar dados (Insert., Bubble, Selection, Merge, Quick, EXTRA)\n");
        printf("4. Gerar relatorio (Log)\n");
        printf("5. Sair\n");
        printf("==================================\n");
        printf("Escolha: ");
        scanf("%d", &opc);


        switch(opc)  
        {         
            case 1:
                 carregarArquivo(path);
                 printf("Arquivo carregado com sucesso!\n");
                 arquivo = true;     
                break;

            case 2:
                if (!arquivo) {
                    printf(" Aviso: Voce deve carregar um arquivo (Opcao 1) antes de buscar.\n");
                } else {
                    int subopc;
                    printf("1. Busca Linear\n2. Busca Binaria\n"); 
                    printf("Escolha: ");
                    scanf("%d", &subopc);
                    if (subopc == 1) {
                        printf("Busca linear executada.\n");
                        //buscarElemento(vet, n, subopc, x);
                    } else if (subopc == 2) {
                        printf("Busca binaria executada.\n");
                        //buscarElemento(vet, n, subopc, x);
                    } else {
                        printf("Opcao Invalida\n");
                    }
                }
                break;
            
            case 3:
                 
                  if (!arquivo) 
                {
                printf("Aviso: Voce deve carregar um arquivo (Opcao 1) antes de buscar.\n");
                } else {
                    opc3=true;
                
                    printf("\n--- SUBMENU ORDENACAO ---\n"); 
                    printf("1. Insertion Sort\n2. Bubble Sort\n3. Selection Sort\n");
                    printf("4. Merge Sort\n5. Quick Sort\n6. EXTRA\n");
                    int subopc;
                    scanf("%d", &subopc);

                    switch (subopc)
                        {
                        
                        case 1:
                        //InsertSort (vet, n);
                        break;

                        case 2:
                        //BubbleSort(vet, n);
                        break;

                        case 3:
                        //SelectionSort( vet, n);
                        break;

                        case 4:
                        //MergeSort(vet, inicio,fim);
                        break;

                        case 5:
                        //QuickSort(vet,inicio,fim);
                        break;
                        
                        case 6:
                        printf("Ok");
                        //extra(); // funcao extra a ser escolhida
                        break;    
                        
                        
                        default:
                            break;

                    }
                }
                break;

            case 4:
                if (!opc3 ) {
                    printf("Nenhum Algoritimo foi executado, Retorne (Opcao 3).\n");
                } else {
                    printf("Gerando Relatorio (LOG)...\n");
                }
                break;

            case 5:
               printf("falo");
                sair = true; 
                break;
                
            default:
                printf("Opcao inexistente.\n");
                break;
        }
    } while(sair == false); 

    QueryPerformanceCounter(&fim);
    elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
    printf(" %2d - Time: %.16lf ms\n", elapsedtime);
    
  
    return 0;
}