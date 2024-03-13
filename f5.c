// ATIVIDADE PARA COMPUTO DE FREQUENCIA - F5
//Informações do estudante
// Nome: JHON WISLIN RIBEIRO CITRON
// Curso: ENGENHARIA DE COMPUTAÇÃO
// RA: 776852

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo No de uma fila implementada usando lista ligada
typedef struct no{
    int info;
    struct no * prox;
}No;

No *fina = NULL;

//retorna um ponteiro para o inicio da fila criada
No * cria()
{
  No *ini;
  ini = NULL;
  return ini;
}
//recebe o inicio da fila e o valor do no a ser inserido
//retorna um ponteiro atualizado para o inicio da fila
No * entra(No * inicio, int val)
{
  No *adicionar;
  adicionar = malloc(sizeof(No));
  
  if (inicio == NULL)
  {
    inicio = adicionar;
    adicionar->info = val;
    adicionar->prox = NULL;
    fina = adicionar;
  }
  else
  {
    fina->prox = adicionar;
    adicionar->info = val;
    adicionar->prox = NULL;
    fina = adicionar;
  }

  return inicio;
}

//recebe o inicio da fila e  um ponteiro para uma variavel cujo valor vai sair da fila
//retorna um ponteiro atualizado para o inicio da fila
No * sai(No * inicio, int * val)
{
  No *aux = inicio;
  No *conexao = inicio->prox;
  inicio = conexao;
  *val = aux->info;
  free(aux);
  aux = NULL;
  return conexao;
}

//recebe o inicio da fila
//retorna 1 se fila vazia, 0 caso contrario
int vazia(No * inicio)
{
  int x = 0;
  if (inicio == NULL)
  {
    return x = 1;
  }
  return x;
}

int main(int argc, char *argv[])
{


    No * fila = NULL; //aponta para o inicio da fila

    fila = cria();

    int n, i, x;

    //leitura do inteiro que indicara o numero de elementos da fila
    scanf("%d", &n);

    //entra os elementos de 0 a n-1 na fila
    for ( i = 0; i < n; i++)
        fila = entra(fila,i);

    //imprime(fila); //so usada para verificacao de insercao, nao pertence ao TAD fila

    //sai os elementos que entraram na fila
    for ( i = 0; i < n; i++){
        fila = sai(fila,&x);
        printf("%d",x);
    }

    return 0;
}