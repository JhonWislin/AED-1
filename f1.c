// ATIVIDADE PARA COMPUTO DE FREQUENCIA - F1
//Informações do estudante
// Nome: JHON WISLIN RIBEIRO CITRON
// Curso: ENGENHARIA DE COMPUTAÇÃO
// RA: 776852

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int somaalg(int n)
{
    int ult = (n % 10);
    int soma = ult;
    int num = n - ult;

    if (num > 0)
    {
      soma = soma + somaalg(num/10);
    }
    
    // implemente essa função recursiva*/

  return soma;
}


int main(int argc, char *argv[])
{
    int n;
    //leitura do inteiro que tera seus digitos somados
    scanf("%d", &n);
    printf("%d",somaalg(n));

    return 0;
}