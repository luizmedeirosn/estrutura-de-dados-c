#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int pos, *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);

void push(PILHA *pi, int dado);
int getTopo(PILHA *pi);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

int main(){
  PILHA pilha1, pilha2;
  //Implementação da função 'criar'
  criar(&pilha1,10); criar(&pilha2,10);

  //Implementação da função 'push'
  push(&pilha1, 100);
  push(&pilha1, 50);
  push(&pilha1, 200);
  
  printf("PILHA_1: \nANTES: \n");
  //Implementação da função 'imprimir'
  imprimir(&pilha1);
  
  //Implementação da função 'pop'
  printf("\nPop em Pilha 1 -> %d\n",pop(&pilha1));

  printf("\nDEPOIS:\n");
  imprimir(&pilha1);
  //Implementação da função 'tamanho'
  printf("Tamanho atual: %d\n",tamanho(&pilha1));

  //Implementação da função 'apagar'
  apagar(&pilha1);

  push(&pilha2, 10);
  push(&pilha2, 5);
  push(&pilha2, 20);
  
  printf("\n\nPILHA_2:\nANTES: \n");
  imprimir(&pilha2);
  printf("O topo da pilha 2 é %d\n", getTopo(&pilha2));
  
  printf("\nPop em Pilha 1 -> %d\n",pop(&pilha2));

  printf("\nDEPOIS:\n");
  imprimir(&pilha2);

  apagar(&pilha2);

  return 0;
}

void criar(PILHA *pi, int tam_MAX){
  pi-> MAX = tam_MAX;
  pi->arr = (int*) malloc(sizeof(int) * tam_MAX);
  pi-> pos = 0;
}

void apagar(PILHA *pi){
  free(pi->arr);
  pi ->pos = 0;
}

void push(PILHA *pi ,int elemento){
  if (pi->pos < pi->MAX)
	pi->arr[pi->pos++] = elemento;
  else
	printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

int getTopo(PILHA *pi){
	return pi->arr[pi->pos-1];
}

int pop(PILHA *pi){
  if (pi->pos)
	  return pi->arr[--pi->pos];
  else {
	  printf("Não há elementos. Pilha vazia.\n");
	  exit(1);
  }
}

int tamanho(PILHA *pi){
  return pi->pos;
}

void imprimir(PILHA *pi){
  printf("P[ ");
  for (int i = pi->pos -1 ; i >= 0 ; i--)
	printf("%d ",pi->arr[i]);
  printf("]\n");
}