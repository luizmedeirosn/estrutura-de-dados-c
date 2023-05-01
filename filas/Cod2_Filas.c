#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi);
void apagar(FILA *fi);

void enqueue(FILA *fi, int dado);
int getFront(FILA *fi);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){

  //Implementando todas as Funções com a FILA_1

  printf("FILA_1 : \n");
  FILA fila1;
  criar(&fila1);

  enqueue(&fila1, 100);
  enqueue(&fila1, 50);
  enqueue(&fila1, 200);
  
  imprimir(&fila1);
  printf("getFront: %d\n",getFront(&fila1));
  imprimir(&fila1);
  printf("Dequeue em FILA_1 -> %d\n\n",dequeue(&fila1));
  imprimir(&fila1);
  printf("getFront: %d\n",getFront(&fila1));
  imprimir(&fila1);
  printf("Dequeue em FILA_1 -> %d\n\n",dequeue(&fila1));

  imprimir(&fila1);
  printf("Tamanho da FILA_1: %d\n",tamanho(&fila1));
  
  apagar(&fila1);
  printf("FILA_1 apagada : ");
  imprimir(&fila1);

  //Implementando as todas as Funções com uma 2º FILA
  printf("\n\nFILA_2 : \n");
  FILA fila2;
  criar(&fila2);

  enqueue(&fila2, 10);
  enqueue(&fila2, 5);
  enqueue(&fila2, 20);
  enqueue(&fila2, 30);
  
  imprimir(&fila2);
  printf("getFront: %d\n",getFront(&fila2));
  imprimir(&fila2);
  printf("Dequeue em FILA_2 -> %d\n\n",dequeue(&fila2));
  imprimir(&fila2);
  printf("getFront: %d\n",getFront(&fila2));
  imprimir(&fila2);
  printf("Dequeue em FILA_2 -> %d\n\n",dequeue(&fila2));

  imprimir(&fila2);
  printf("Tamanho da FILA_2: %d\n",tamanho(&fila2));
  
  apagar(&fila2);
  printf("FILA_2 apagada : ");
  imprimir(&fila2);

  return 0;
}

void criar(FILA *fi){
  fi->ini = fi->fim = NULL;
}

void apagar(FILA *fi){
  struct sNODE *aux = fi->ini, *ant = NULL;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  fi->ini = fi->fim = NULL;
}

void enqueue(FILA *fi, int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!fi->ini)
	fi->ini = fi->fim = novo;
  else{
	fi->fim->prox = novo;
	fi->fim = novo;
  }
}

int getFront(FILA *fi){
  if (fi->ini){
	  int dado = fi->ini->dado;
	  return dado;
  }
  
  else {
	  printf("Não há elementos. Fila vazia.\n");
	  exit(1);
  }
}

int dequeue(FILA *fi){
  if (fi->ini) {
	  int dado = fi->ini->dado;
	  struct sNODE *tmp = fi->ini;
    
	  if (fi->ini == fi->fim)
  	  fi->ini = fi->fim = NULL;
	  else
  	  fi->ini = fi->ini->prox;

	free(tmp);
	return dado;
  }
  
  else {
	  printf("Não há elementos. Fila vazia.\n");
	  exit(1);
  }
}

int tamanho(FILA *fi){
  struct sNODE *aux = fi->ini;
  int tam = 0;
 
  while (aux){
	  tam++;
	  aux = aux->prox;
  }
 
  return tam;
}

void imprimir(FILA *fi){
  struct sNODE *aux = fi->ini;
 
  printf("F[ ");
  while (aux){
	  printf("%d ", aux->dado);
	  aux = aux->prox;
  }
  printf("]\n");
}