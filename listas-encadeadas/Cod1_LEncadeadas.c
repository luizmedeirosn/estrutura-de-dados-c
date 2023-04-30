#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void inserir_ini(int dado);
void remover(int dado);
struct sNODE *buscar(int dado);

int obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){
  for(int i = 0; i < 10; i++)
    inserir(i);
  imprimir();

  inserir_ini(30);inserir_ini(20);inserir_ini(10);
  imprimir();
  return 0;
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

void inserir_ini(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	  ini = fim = novo;
  else{
    novo->prox = ini;
	  ini = novo;	  
 }
}

struct sNODE *buscar(int dado){
  struct sNODE *aux = ini;

  while (aux){
	if (dado == aux->dado)
  	return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(int dado){
  struct sNODE *aux = ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	if (aux == ini)
    	ini = ini->prox;
  	else if(aux == fim){
    	ant->prox = NULL;
    	fim = ant;
  	  } 
    else
    	ant->prox = aux->prox;
 	  
     free(aux);
  	return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
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

int obter(struct sNODE *node){
  if (!node){
	  printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
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
 
  printf("Lista atual [ ");
  while (aux){
	  printf("%d ", aux->dado);
  	aux = aux->prox;
  }
  printf("]\n");
}