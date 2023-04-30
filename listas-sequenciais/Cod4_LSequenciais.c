#include <stdio.h>
#include <stdlib.h>

typedef struct {
 unsigned MAX;
 int *arr, pos;
} LISTA;

void criar(LISTA *lst, int tam_MAX);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int elemento);
void remover(LISTA *lst, int elemento);
int buscar(LISTA *lst, int elemento);

int obter(LISTA *lst, int indice);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);


int main(void) {
  //declarando as listas
  LISTA lista1, lista2;

  //implementação da função criar
  criar(&lista1,5); criar(&lista2,3);

  //implementação das funçoes com a lista1
  printf("Operando com a lista1 :\n");
  inserir_ord(&lista1,3); inserir_ord(&lista1,1); inserir_ord(&lista1,2);
  imprimir(&lista1);
  inserir_ord(&lista1,7); inserir_ord(&lista1,4);
  imprimir(&lista1);
  inserir_ord(&lista1,10);
  printf("O indice do elemento %d é %d\n",7,buscar(&lista1,7));
  printf("No indice %d temos o elemento %d\n",4,obter(&lista1,4));
  remover(&lista1,4);
  imprimir(&lista1);
  printf("O tamanho atual da lista1 é %d\n\n",tamanho(&lista1));
  apagar(&lista1);
  printf("---------------------------------------");


  //implementação das funçoes com a lista2
  printf("\nOperando com a lista2 :\n");
  inserir_ord(&lista2,30); inserir_ord(&lista2,10); inserir_ord(&lista2,20);
  imprimir(&lista2);
  inserir_ord(&lista2,70);
  printf("O indice do elemento %d é %d\n",30,buscar(&lista2,30));
  printf("No indice %d temos o elemento %d\n",1,obter(&lista2,1));
  remover(&lista2,20);
  imprimir(&lista2);
  printf("O tamanho atual da lista2 é %d\n",tamanho(&lista2));
  apagar(&lista2);

  return 0;
}

void criar(LISTA *lst, int tam_MAX){
  lst->MAX = tam_MAX;
  lst->arr = (int*) malloc(sizeof(int)* tam_MAX);
  lst->pos = 0;
}

void apagar(LISTA *lst){
  free(lst->arr);
  lst->pos = 0;
}

void inserir_ord(LISTA *lst,int elemento){
  int i, p;
  if (lst->pos < lst->MAX) {
	  for (i = 0 ; i < lst->pos ; i++)
  	    if (lst->arr[i] >= elemento)
    	        break;
    
	for (p = lst->pos ; p > i ; p--)
  	    lst->arr[p] = lst->arr[p-1];
    
	lst->arr[i] = elemento;
  
  lst->pos ++;
  }
  
  else {
	  printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

int buscar(LISTA *lst, int elemento){
  for (int i = 0 ; i < lst->pos ; i++){
	if (lst->arr[i] == elemento)
  	return i;
  }
  return -1;
}

void remover(LISTA *lst, int elemento){

  int p = buscar(lst,elemento);
 
  if (p == -1)
	return;
 
  for (int i = p ; i < lst->pos -1; i++)
	  lst->arr[i] = lst->arr[i+1];
  lst->pos--;
  
}


int obter(LISTA *lst, int indice){
  if (indice < 0 || indice >= lst->pos) {
	printf("Indice %d fora dos limites da Lista.\n", indice);
	exit(1);
  }
  return lst->arr[indice];
}

int tamanho(LISTA *lst){
  return lst->pos;
}

void imprimir(LISTA *lst){
  for (int i = 0 ; i < lst->pos ; i++)
	printf("%d ",lst->arr[i]);
  printf("\n");
}