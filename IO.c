#include "matriz/matriz.h"
#include<stdio.h>
#include<pthread.h>
#include<time.h>
int quantidadelinhas;
int quantidadedecolunas;
int** matriz;
void* printrow(void* args){
    int arg=(int)args;
    for (size_t i = 0; i < quantidadedecolunas; i++)
    {
        printf("%d",matriz[arg][i]);
    }
    printf("\n");
}
int main(){
    printf("digite a quantidade de colunas");
    scanf("%d", &quantidadedecolunas);
    printf("digite a quantidade de linhas");
    scanf("%d", &quantidadelinhas);
    pthread_t thread[quantidadelinhas];
    matriz=create_matrix(quantidadedecolunas,quantidadelinhas);
    generate_elements(matriz,quantidadedecolunas,quantidadelinhas,20);
    for (size_t i = 0; i < quantidadelinhas; i++)
    {
        pthread_create(&thread[i],NULL,printrow,(void*)i);
    }
    pthread_exit(&thread);   
}