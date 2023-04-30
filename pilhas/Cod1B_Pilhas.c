#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *topo = NULL;

void push(int dado);
int getTopo();
int pop();

int tamanho();
void imprimir();
void apagar();

int main(void) {
  for(int i = 0; i < 5; i++)
    push(i);
  imprimir();

  //Implementação da função 'getTopo'
  printf("O TOPO da PILHA é %d\n\n",getTopo());
  
  for(int i = 5; i < 10; i++)
    push(i);
  imprimir();
  
  //Nova chamada da função 'getTopo' para observar que o antigo topo foi retornado na chamada anterior, porém não foi removido
  printf("Depois de empilhar novos números, o novo TOPO da PILHA é %d\n",getTopo());

  return 0;
}

void push(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!topo)
	topo = novo;
  else{
	novo->prox = topo;
	topo = novo;
  }
}

int getTopo(){
  if (topo) {
	  int dado = topo->dado;
	  return dado;
  }
  else {
	  printf("Não há elementos. Pilha vazia.\n");
	  exit(1);
  }
}

int pop(){
  if (topo) {
	int dado = topo->dado;
	struct sNODE *tmp = topo;
    
	topo = topo->prox;

	free(tmp);

	return dado;
  }
  else {
	printf("Não há elementos. Pilha vazia.\n");
	exit(1);
  }
}

int tamanho(){
  struct sNODE *aux = topo;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  struct sNODE *aux = topo;
 
  printf("P[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}

void apagar(){
  struct sNODE *aux = topo, *ant;

  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  topo = NULL;
}