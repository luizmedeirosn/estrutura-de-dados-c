#include <stdio.h>
#include <stdlib.h>

void insertionSortInverso(int l[], int tam){
  for (int i = 1 ; i < tam ; i++) {
    int eleito = l[i];
    int j = i - 1;

    while (j >= 0 && l[j] < eleito) {
      l[j+1] = l[j];
      j = j - 1;
    }
    l[j+1] = eleito;
  }
}

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int indexMinInverso(int l[], int ini, int tam){
  int im = ini;
  int menor = l[ini];

  for (int i = ini -1 ; i >= 0 ; i--)
    if (l[i] < menor) {
      im = i;
      menor = l[i];
    }
  
  return im;
}

void selectionSortInverso(int l[], int tam){
  for (int i = tam -1 ; i > 2; i--) {
    int eleito = l[i];
    int im = indexMinInverso(l, i-1, tam);
    if (l[im] < eleito)
      troca(&l[i],&l[im]);
  }
}

int main(void) {
  int l1[] = {1,2,3,4,5}, l2[] = {10,20,30,40,50}, tam = 5;

  insertionSortInverso(l1, tam);
  printf("\nInsertionSortInverso:\n");
  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l1[i]);

  selectionSortInverso(l2, tam);
  printf("\n\nSelectionSortInverso:\n");
  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l2[i]);
  
  printf("\n");
  return 0;
}