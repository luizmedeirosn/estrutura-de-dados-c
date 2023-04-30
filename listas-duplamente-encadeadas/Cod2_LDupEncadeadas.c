#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  char nome[31];
  char ocup[31];
  float salario;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ord(char nome[], char ocup[], float salario);
void remover(char nome[]);
struct sNODE *buscar(char nome[]);

float obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){

  //Aplicação das funções inserir_ord e imprimir
  inserir_ord("Neto","A",3000.00);inserir_ord("Medeiros","B",5000.00);inserir_ord("Luiz","C",7000.00);
  imprimir();

  inserir_ord("Victor","E",12000.00);inserir_ord("André","D",10000.00);

  printf("\nAPÓS A ADIÇÃO DE MAIS 2 FUNCIONÁRIOS:\n\n");
  imprimir();

  printf("\nAPÓS REMOVER ALGUNS NÓS:\n\n");
  remover("Medeiros"); remover("André");
  imprimir();

  printf("\nNeto está no endereço %p\n",buscar("Neto"));
  printf("O salário de Neto é : %.2f\n",obter(buscar("Neto")));
  
  apagar();
  return 0;
}

void inserir_ord(char nome[], char ocup[], float salario){
  struct sNODE *aux = ini;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  strcpy(novo->nome,nome);
  strcpy(novo->ocup,ocup);
  novo->salario = salario;
  novo->ant = NULL;
  novo->prox = NULL;

  while(aux && salario < aux->salario)
    aux = aux->prox;

  if (!ini)
	  ini = fim = novo;
  
  else if (aux == ini){
	  novo->prox = ini;
	  ini->ant = novo;
	  ini = novo;
  } 
  
  else if (!aux){
	  fim->prox = novo;
	  novo->ant = fim;
	  fim = novo;
  }
  
  else {
	  aux->ant->prox = novo;
	  novo->ant = aux->ant;
	  novo->prox = aux;
	  aux->ant = novo;
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
  struct sNODE *aux = buscar(nome);

  if (!aux)
	return;

  if (!aux->ant && !aux->prox)
	  ini = fim = NULL;
  else if (aux == ini) {
	  ini = ini->prox;
	  ini->ant = NULL;
  } 
  else if (aux == fim) {
	  fim = fim->ant;
	  fim->prox = NULL;
  } 
  else {
	  aux->ant->prox = aux->prox;
	  aux->prox->ant = aux->ant;
  }
  
  free(aux);
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
 
  return node->salario;
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
	  printf("( Nome: %s, Ocupação: %s, Salário: %.2f ) \n",aux->nome, aux->ocup, aux->salario);
	  aux = aux->prox;
  }
  printf("]\n");
}