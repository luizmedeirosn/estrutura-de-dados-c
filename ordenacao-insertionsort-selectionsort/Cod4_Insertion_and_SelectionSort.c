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
struct sNODE *indexMin(struct sNODE *no, int tam);
void selectionSort(int tam);

int main(){
  for(int i = 1 ; i  < 6 ; i++)
    inserir(i);
  for(int i = 5; i > 0; i--)
    inserir(i);
  printf("\nAntes:\n");
  imprimir();
  
  printf("\nselectionSort:\n");
  selectionSort(tamanho());
  imprimir();

  apagar();
  return 0;
}

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

struct sNODE *indexMin(struct sNODE *no, int tam){
  struct sNODE *aux = no, *im = no;
  int menor = no->dado;
  
  while(aux){
    if (aux->dado < menor) {
      im = aux;
      menor = aux->dado;
    }
    aux = aux->prox;
  }
    
  return im;
}

void selectionSort(int tam){
  struct sNODE *aux = ini;
  for (int i = 0 ; i < tam - 1 ; i++) {
    int eleito = aux->dado;
    struct sNODE *im = indexMin(aux->prox, tam);
    if (im->dado < eleito)
      troca(&aux->dado,&im->dado);
    aux = aux->prox;
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