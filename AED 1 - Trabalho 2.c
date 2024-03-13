//NOME: JHON WISLIN RIBEIRO CITRON
//RA: 776852
//CURSO: ENGENHARIA DE COMPUTAÇÃO

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa
{
    int posicao;
    Pessoa *prox;
};

/* lista inicialmente vazia */
Pessoa *inicio = NULL;
Pessoa *surpresa = NULL; //Aponta para a última posição adicionada.

//DECLARAR MAIS VARIAVEIS GLOBAIS SE NECESSARIO

void *mallocsafe(unsigned tam)
{
    void *p;
    p = malloc(tam);
    if (p == NULL)
    {
        printf("Deu ruim! malloc() falou\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

/* Insere no fim da lista */
void insereLista(int pos)
{
//IMPLEMENTAR
  int i = 1;
  while (i <= pos)
  {
    Pessoa *Adiciona;
    Adiciona = malloc(sizeof(Pessoa));
    
    if (inicio == NULL)
    {
      inicio = Adiciona;
      Adiciona->posicao = i;
      Adiciona->prox = inicio;
      surpresa = Adiciona;
    }
    else
    {
      surpresa->prox = Adiciona;
      Adiciona->posicao = i;
      Adiciona->prox = inicio;
      surpresa = Adiciona;
    }
    i++;
  }
}

/* Remove o elemento imediatamente após o elemento p presente na lista */
/* Supõe que a lista tem pelo menos dois elementos */
void removeLista(Pessoa *p)
{
    //IMPLEMENTAR
    Pessoa *Deleta;
    Deleta = p->prox;
    p->prox = p->prox->prox;
    free(Deleta);
    Deleta = NULL;

}

/* Imprime cada elemento dentro da lista */
void imprimeLista()
{
    //IMPLEMENTAR
    Pessoa *imprime;

    imprime = inicio;

    while (imprime->prox != inicio)
    {
      printf ("%d\n", imprime->posicao);
      imprime = imprime->prox;
    }
    printf ("%d\n", imprime->posicao);
}

void liberaLista()
{
    //IMPLEMENTAR
    free(surpresa);
    free(inicio);
}

int resolveJosephus(int n, int m)
{
    //IMPLEMENTAR
    inicio = NULL;
    surpresa = NULL;
    Pessoa *Antecede_morto;
    Pessoa *Quem_Aniquila;
    int contador = 1;//Contador do salto.
    int cont = 0;//Contador do número de pessoas removidas.
    int primeira = 0;//Contador para verificar se ja houve //remoção.

    insereLista(n);

    //Remoção de pessoa da lista.
    while (cont < (n-1))
    {
      if (primeira == 0)
      {
        Quem_Aniquila = inicio;
        Antecede_morto = Quem_Aniquila;

        for (contador = 1; contador < m; contador++)
        {
          Antecede_morto = Antecede_morto->prox;
        }
        removeLista(Antecede_morto);
        Quem_Aniquila = Antecede_morto->prox;
        primeira++;
        cont++;
      }
      else
      {
        Antecede_morto = Quem_Aniquila;

        for (contador = 1; contador < m; contador++)
        {
          Antecede_morto = Antecede_morto->prox;
        }

        if (Quem_Aniquila == Antecede_morto->prox)
        {
          Antecede_morto = Antecede_morto->prox;
        }

        removeLista(Antecede_morto);
        Quem_Aniquila = Antecede_morto->prox;
        cont++;
      }
    
    }

  return Quem_Aniquila->posicao;
}

int main()
{
    int nroexecs;

    scanf("%d", &nroexecs);
    int *n = malloc(nroexecs * sizeof(int));
    int *m = malloc(nroexecs * sizeof(int));

    for (int i = 0; i < nroexecs; i++)
    {
        scanf("%d", &n[i]);
        scanf("%d", &m[i]);
    }

    inicio = NULL; // inicializa a lista como vazia

    //INICIALIZAR OUTRAS VARIAVEIS GLOBAIS SE NECESSARIO

    for (int i = 0; i < nroexecs; i++)
    {
        printf("Usando n=%d, m=%d, resultado=%d\n", n[i], m[i], resolveJosephus(n[i], m[i]));
    }

    return 0;
}