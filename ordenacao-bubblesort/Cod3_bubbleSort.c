#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
int tamanho();
void imprimir();
void apagar();

void troca(int *a, int *b);
void bubbleSort(int tam);

int main(){
  for(int i = 5; i > 0; i--)
    inserir(i);
  for(int i = 1; i < 6; i++)
    inserir(i);
  printf("\nAntes:\n");
  imprimir();
  
  printf("\nbubbleSort:\n");
  bubbleSort(tamanho());
  imprimir();

  apagar();
  return 0;
}

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int tam){
  int trocou = 1;
  for (int i = 0 ; i < tam && trocou; i++) {
    trocou = 0;
    struct sNODE *aux = ini;

    for (int j = 0 ; j < tam - 1 - i; j++){
      if (aux->dado > aux->prox->dado) {
        troca(&aux->dado, &aux->prox->dado);
        trocou = 1;
      }
      aux = aux->prox;
    }
  }
}

void inserir(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	ini = fim = novo;
  else{
	fim->prox = novo;
	fim = novo;
  }
}

int tamanho(){
  struct sNODE *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  struct sNODE *aux = ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}

void apagar(){
  struct sNODE *aux = ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}