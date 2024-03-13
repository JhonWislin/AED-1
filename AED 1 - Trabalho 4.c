// Trabalho 4
//Informações do estudante
// Nome: JHON WISLIN RIBEIRO CITRON
// Curso: ENGENHARIA DE COMPUTAÇÃO
// RA: 776852

#include <stdio.h>

//função que retorna quantas inversões são necessarias //para ordenar o genoma v.
int OrdenaGenoma(int v[], int N)
{
  int cont = 0;//contador de inversões.
  int inverte;//variavel auxiliar ao que esta sendo invertido.
  int i, j;

  for (i = 0; i < N; i++)
  {
    for (j = 1; j < N - i; j++)
    {
      if (v[j - 1] > v[j])
      {
        inverte = v[j - 1];
        v[j - 1] = v[j];
        v[j] = inverte;
        cont++;
      }
    }
  }

  return cont;
}

int main(void) {
  int N;
  int i;

  //Tamanho do genoma.
  scanf("%d\n", &N);

  int v[N];

  //valores do genoma.
  for (i = 0; i < N; i++)
  {
    scanf("%d", &v[i]);
  }

  printf("%d\n", OrdenaGenoma(v, N));
  return 0;
}