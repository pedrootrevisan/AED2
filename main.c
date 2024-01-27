#include <stdio.h>
#include <stdlib.h>

void bubblesort(int vetor[], int tam){
    int temp, i,j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam-1-i; j++){
            if(vetor[j+1]<vetor[j]){
                temp = vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=temp;
            }
        }
    }
}
/*Para otimizar o algoritmo(bubblesort) e evitar que o processo continue após o vetor estar ordenado,
 você pode adicionar uma variável de controle que indica se houve ou não trocas durante uma passagem completa pelo vetor.
Se nenhuma troca ocorrer durante uma passagem, significa que o vetor já está ordenado,
 e o algoritmo pode ser interrompido.*/
 void bubblesort2(int vetor[], int tam){
    int temp, i, j;
    int trocas;

    for(i = 0; i < tam; i++){
        trocas = 0;
        for(j = 0; j < tam-1-i; j++){
            if(vetor[j+1] < vetor[j]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                trocas = 1;
            }
        }
        if (trocas == 0) {
            break;
        }
    }
}


int main(){
    int i;
    int v[8]={25,48,53,37,13,86,33,96};
    bubblesort(v,8);
    printf("vetor ordenado: \n");
    for(i=0;i<8;i++){
        printf("%d \n", v[i]);
    }
    return 0;
}
