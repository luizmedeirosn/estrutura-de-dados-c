#include <stdio.h>
#include <stdlib.h>

int buscaBin(int l[],int num, int ini, int fim) {
  if (ini <= fim){
    int meio = (ini + fim) / 2;
    
    if (l[meio] == num)
      return meio;
    
    else {
      if (num < l[meio])
        return buscaBin(l, num, ini, meio - 1);
      else
        return buscaBin(l, num, meio + 1, fim);
    }
  }
  return -1;
}

int main(){
  int l[] = {1,3,5,7,9,11}, tam = 6;
  int ini = 0, fim = tam -1;

  printf("Achei 3 em %d \n",buscaBin(l, 3, ini, fim));
  printf("Achei 9 em %d \n",buscaBin(l, 9, ini, fim));
  
  return 0;
}