#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercala(char l[][21],int ini, int fim, int meio) {
  char aux[fim-ini+1][21];
  int p_aux = 0;
  int ini1 = ini, ini2 = meio + 1;

  while( (ini1 <= meio) && (ini2 <= fim) ) {
    if (strcmp(l[ini1],l[ini2]) <= 0 )
      strcpy(aux[p_aux],l[ini1++]);
    else
      strcpy(aux[p_aux],l[ini2++]);
    p_aux++;
  }

  for (int i = ini1 ; i <= meio ; i++)
    strcpy(aux[p_aux++],l[i]);
  
  for (int i = ini2 ; i <= fim ; i++)
    strcpy(aux[p_aux++],l[i]);
  
  for (int i = ini, j = 0 ; i <= fim ; i++,j++)
    strcpy(l[i],aux[j]);
}

void mergeSort(char l[][21], int ini, int fim) {
  if (ini < fim) {
    int meio = (ini + fim) / 2;
    mergeSort(l,ini,meio);
    mergeSort(l,meio+1,fim);
    intercala(l,ini,fim,meio);
  }
}

int buscaBin(char l[][21], int tam, char num[]) {
  int ini = 0, fim = tam -1;
  int meio = (ini + fim) / 2;

  while (ini <= fim) {
    if (!strcmp(l[meio], num))
      return meio;
    else {
      if (strcmp(num, l[meio]) <= 0)
        fim = meio - 1;
      else
        ini = meio + 1;

      meio = (ini + fim) / 2;
    }
  }
  return -1;
}

int main(){
  char l[][21] = {"Neto","Medeiros","Luiz"}, tam = 3;
  
  mergeSort(l, 0, 2);
  for (int i = 0 ; i <= 2 ; i++)
    printf("%s ",l[i]);
  printf("\n");
  
  printf("Achei Luiz em %d \n",buscaBin(l, tam, "Luiz"));
  printf("Achei Neto em %d \n",buscaBin(l, tam, "Neto"));
  
  return 0;
}