#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  char nome[41];
  float n1,n2,media;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ord(char aluno[], float n1, float n2);
void remover(char dado[]);
struct sNODE *buscar(char dado[]);

float obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){
  inserir_ord("Lucas",10.0,10.0); inserir_ord("Alex",5.0,5.0);
  inserir_ord("Vanessa",7.0,7.0); inserir_ord("Ana",10.0,10.0);
  imprimir();

  printf("\n");
  remover("Vanessa"); remover("Alex");
  imprimir();

  printf("\nLucas está no endereço %p\n",buscar("Lucas"));
  printf("A média de lucas é : %.1f\n",obter(buscar("Lucas")));

  return 0;
}

void inserir_ord(char nome[], float n1, float n2){
  
  float media = (n1 + n2) / 2;
  struct sNODE *aux = ini, *ant = NULL;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  
  strcpy(novo->nome,nome);
  novo->n1 = n1;
  novo->n2 = n2;
  novo->media = media;
  novo->prox = NULL;

  while(aux && media < aux->media){
	  ant = aux;
	  aux = aux->prox;
  }

  if (!ini)
  	ini = fim = novo;
  
  else if (aux == ini){
	  novo->prox = ini;
	  ini = novo;
  } 
  
  else if (!aux){
	  fim->prox = novo;
	  fim = novo;
  } 
  
  else {
    ant->prox = novo;
	  novo->prox = aux;
  }
}

struct sNODE *buscar(char nome[]){
  struct sNODE *aux = ini;

  while (aux){
	if (!strcmp(nome,aux->nome))
  	return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(char nome[]){
  struct sNODE *aux = ini, *ant = NULL;

  while (aux){
	if (!strcmp(nome,aux->nome)){
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

float obter(struct sNODE *node){
  if (!node){
	  printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->media;
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
	  printf("(Nome : %s , Media : %.1f), ",aux->nome,aux->media);
  	aux = aux->prox;
  }
  printf("]\n");
}