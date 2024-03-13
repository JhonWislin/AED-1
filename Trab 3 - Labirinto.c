// Trabalho 3 - Labirinto
//Informações do estudante
// Nome: JHON WISLIN RIBEIRO CITRON
// Curso: ENGENHARIA DE COMPUTAÇÃO
// RA: 776852
#include<stdlib.h>
#include <stdio.h>

#define N 4

//Tipo No de uma fila implementada usando lista ligada
typedef struct no{
    int lin;
    int col;
    struct no * prox;
}No;

No * fila;
No * Terminal;

//retorna um ponteiro para o inicio da fila criada
No * cria(){
   return fila;
}

No * entra(No * inicio, int lin, int col){
   //fazer
   No *adicionar = malloc(sizeof(No));

   if (inicio == NULL)
   {
     inicio = adicionar;
     adicionar->lin = lin;
     adicionar->col = col;
     adicionar->prox = NULL;
     Terminal = adicionar;
   }
   else
   {
     Terminal->prox = adicionar;
     adicionar->lin = lin;
     adicionar->col = col;
     adicionar->prox = NULL;
     Terminal = adicionar;
   }
  return inicio;
}

No * sai(No * inicio, int * lin, int * col){
   //fazer
   No *aux = inicio;
   No *conexao = inicio->prox;
   inicio = conexao;
   *lin = aux->lin;
   *col = aux->col;
   free(aux);
   aux = NULL;
   return conexao;
}

int vazia(No * inicio){
    //fazer
    if (inicio == NULL)
    {
      return 1;
    }
  return 0;
}

int procuraLab(int lab[N][N], int x, int y, int sol[N][N])
{
  if (x == N-1 && y == N-1)
  {
    sol[x][y] = 1;
    return 1;
  }

  if (lab[x][y] == 1 && (x >= 0 && x < N) && (y >= 0 && y < N))
  {
    sol[x][y] = 1;

    if (procuraLab(lab,x+1,y,sol))
    {
      return 1;
    }
    else if (procuraLab (lab,x,y+1,sol))
    {
      return 1;
    }
    else
    {
      sol[x][y] = 0;
    }
  }
  return 0;
}

void printSolution(int sol[N][N])
{
    fila = cria();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            printf(" %d ", sol[i][j]);
            if(sol[i][j] == 1)
                fila = entra(fila,i,j);
        }
        printf("\n");
    }
    int lin, col;
    while(fila!=NULL){
        fila = sai(fila,&lin,&col);
        printf("(%d,%d)->",lin,col);
    }
}

void resolveLabirinto(int labirinto[N][N])
{
  int zero[N][N] = {0};

  if(procuraLab(labirinto, 0, 0, zero))
  {
    printSolution(zero);
  }
  else
  {
    printf("\nSEM SOLUCAO\n");
  }
}

int main()
{
    int labirinto1 [N][N] = { { 1, 0, 0, 0 },
                              { 1, 1, 0, 1 },
                              { 0, 1, 0, 0 },
                              { 1, 1, 1, 1 } };

    int labirinto2 [N][N] = { { 1, 1, 1, 0 },
                              { 0, 0, 1, 1 },
                              { 0, 0, 0, 1 },
                              { 1, 1, 1, 1 } };

    int labirinto3 [N][N] = { { 1, 1, 1, 0 },
                              { 0, 1, 0, 1 },
                              { 0, 1, 1, 0 },
                              { 1, 1, 1, 1 } };


    int labirinto4 [N][N] = { { 1, 1, 1, 0 },
                              { 1, 0, 0, 1 },
                              { 1, 0, 1, 0 },
                              { 1, 1, 1, 1 } };

    int labirinto5 [N][N] = { { 1, 1, 0, 0 },
                              { 0, 0, 0, 1 },
                              { 0, 0, 1, 0 },
                              { 0, 1, 1, 1 } };

    resolveLabirinto(labirinto1);
    printf("\n");
    resolveLabirinto(labirinto2);
    printf("\n");
    resolveLabirinto(labirinto3);
    printf("\n");
    resolveLabirinto(labirinto4);
    printf("\n");
    resolveLabirinto(labirinto5);
    return 0;
}
