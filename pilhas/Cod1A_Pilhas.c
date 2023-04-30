#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void push(int elemento);
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

int getTopo(){
  if(pos)
    return l[pos-1];

  else {
    printf("Não há elementos. Pilha vazia.\n");
    exit(1);
  }	  
}

void push(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else
	printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

int pop(){
  if (pos)
	  return l[--pos];
  else {
	  printf("Não há elementos. Pilha vazia.\n");
	  exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("P[ ");
  for (int i = pos -1 ; i >= 0 ; i--)
	printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}