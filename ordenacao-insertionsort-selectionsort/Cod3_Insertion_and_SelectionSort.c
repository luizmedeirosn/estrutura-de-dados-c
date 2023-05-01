#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSortString(char l[][21], int tam){
  for (int i = 1 ; i < tam ; i++) {
    char eleito[21];
    strcpy(eleito,l[i]);
    int j = i - 1;

    while (j >= 0 && strcmp(l[j],eleito) >= 0) {
      strcpy(l[j+1],l[j]);
      j = j - 1;
    }
    strcpy(l[j+1],eleito);
  }
}

int main(void) {
  char l[][21] = {"Luiz","Neto","Medeiros","Helena","Dandinha"};
  int tam = 5;

  printf("\nInsertionSortStrings:\n");
  insertionSortString(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%s ",l[i]);

  
  printf("\n");
  return 0;
}