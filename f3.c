// ATIVIDADE PARA COMPUTO DE FREQUENCIA - F3
//Informações do estudante
// Nome: JHON WISLIN RIBEIRO CITRON
// Curso: ENGENHARIA DE COMPUTAÇÃO
// RA: 776852

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo No de uma lista ligada

typedef struct No{
    int info;
    struct No * prox;
}No;

No *p = NULL;

//retorna um ponteiro para a lista criada
No * crialista(int n){
    //fazer esta funcao

    if (n == 0)
    {
      return NULL;
    }
    
    n = n - 1;

    while (n >= -1)
    {
      No *atual;
      No *aux;
      atual = malloc(sizeof(No));

      if (p == NULL && n != -1)
      {
        p = atual;
        atual->info = n;
        atual->prox = p;
      }
      else
      {
        aux = p;

        while (aux->prox != p)
        {
          aux = aux->prox;
        }
        aux->prox = atual;
        atual->info = n;
        atual->prox = p;
      }
      n--;
    }

    return p;
}

void imprimelista(No * p){
    //fazer esta funcao

    if ( p == NULL )
    {
      return;
    }

    No *imprime;
    imprime = p;

    do
    {
      printf ("%d", imprime->info);
      imprime = imprime->prox;
    } while ( imprime->prox != p);
}

void apagalista(No * p){
   //fazer esta funcao
   No *Destruaele;
   No *aux;
   aux = p;

   if ( p == NULL )
   {
     return;
   }

   while ( aux->prox != p)
   {
     Destruaele = aux;
     aux = aux->prox;
     free(Destruaele);
   }
   Destruaele = NULL;
}


int main(int argc, char *argv[])
{

    No  * meuno;

    int n;

    //leitura do inteiro que indicara o numero de elementos da lista ligada
    scanf("%d", &n);

    meuno = crialista(n);

    imprimelista(meuno);

    apagalista(meuno);

    meuno = NULL;

    return 0;
}