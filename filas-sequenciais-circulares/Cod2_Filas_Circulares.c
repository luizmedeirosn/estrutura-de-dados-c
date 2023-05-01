#include <stdio.h>
#include <stdlib.h>

typedef struct sFila{
  int MAX, *arr, ini, fim;
}FILA;

void criar(FILA *fi, int tam_MAX);
void apagar(FILA *fi);

void enqueue(FILA *fi, int elemento);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
  //Implementando todas as funções passando uma FILA como argumento
  printf("\nFILA_1:\n\n");
  FILA fila1;
  criar(&fila1,10);

  enqueue(&fila1, 100);
  enqueue(&fila1, 50);
  enqueue(&fila1, 200);

  imprimir(&fila1);
  printf("Dequeue em Fila1 -> %d\n",dequeue(&fila1));
  imprimir(&fila1);
  printf("TAM Fila1: %d\n",tamanho(&fila1));

  apagar(&fila1);

  printf("\nFILA_2:\n\n");
  FILA fila2;
  criar(&fila2,10);

  enqueue(&fila2, 100);
  enqueue(&fila2, 50);
  enqueue(&fila2, 200);
  enqueue(&fila2, 70);

  imprimir(&fila2);
  printf("Dequeue em Fila2 -> %d\n",dequeue(&fila2));
  imprimir(&fila2);
  printf("TAM Fila2: %d\n",tamanho(&fila2));

  apagar(&fila2);

  return 0;
}

void criar(FILA *fi, int tam_MAX){
  fi->arr = (int*) malloc(sizeof(int) * tam_MAX);
  fi->MAX = tam_MAX;
  fi->ini = 0;
  fi->fim = 0;
}

void apagar(FILA *fi){
  fi->ini = fi->fim = 0;
  free(fi->arr);
}

void enqueue(FILA *fi, int elemento){
  if ((fi->fim + 1) != fi->ini && !(fi->fim + 1 == fi->MAX && !fi->ini) ){
	  fi->arr[fi->fim] = elemento;
	  //fim = (fim + 1) % MAX;
	  fi->fim++;
	  if (fi->fim == fi->MAX) fi->fim = 0;
  }
  else
	  printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(FILA *fi){
  if (fi->ini != fi->fim) {
	  int dado = fi->arr[fi->ini];
	  //ini = (ini + 1) % MAX;
	  fi->ini++;
	  if (fi->ini == fi->MAX) fi->ini = 0;
	  return dado;
  }
  else {
	  printf("Não há elementos. Fila vazia.\n");
	  exit(1);
  }
}

int tamanho(FILA *fi){
  if (fi->ini <= fi->fim)
	  return fi->fim - fi->ini;
  else
	  return fi->MAX - (fi->ini - fi->fim);
}

void imprimir(FILA *fi){
  printf("F[ ");
  for (int i = fi->ini ;  ; i++) {
	  if (i == fi->MAX) 
      i = 0;
	  
    if (i == fi->fim) 
      break;
	  printf("%d ",fi->arr[i]);
  }
  printf("]\n");
}