#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocaInt(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSortIntInverso(int l[], int tam){
  int trocou = 1;
  for (int i = 0 ; i < tam && trocou; i++) {
    trocou = 0;
    for (int j = 0 ; j < tam - 1 - i; j++)
      if (l[j] < l[j+1]) {
        trocaInt(&l[j],&l[j+1]);
        trocou = 1;
      }
  }
}

void trocaString(char a[], char b[]) {
  char t[21];
  strcpy(t,a);
  strcpy(a,b);
  strcpy(b,t);
}


void bubbleSortString(char l[][21], int tam){
  int trocou = 1;
  for (int i = 0 ; i < tam && trocou; i++) {
    trocou = 0;
    for (int j = 0 ; j < tam - 1 - i; j++)
      if(strcmp(l[j],l[j+1])>= 0) {
        trocaString(l[j],l[j+1]);
        trocou = 1;
      }
  }
}

int main(void) {
  int l1[] = {5, 1, 2, 4, 3}, tam = 5;
  char l2[][21] = {"Luiz","Neto","Medeiros","Helena","Dandinha"};

  printf("\nbubbleSortStrings:\n");
  bubbleSortString(l2, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%s ",l2[i]);
  printf("\n");

  printf("\n\nbubbleSortIntInverso:\n");
  bubbleSortIntInverso(l1, tam);
  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l1[i]);
  printf("\n");
  return 0;
}