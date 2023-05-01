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

void inserir_ini(FILA *fi, int dado);
void inserir_fim(FILA *fi, int dado);
int remover_ini(FILA *fi);
int remover_fim(FILA *fi);

int getFront(FILA *fi);
int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
  //Declaração de uma nova FILA e implementando a função criar
  printf("\nFILA_1 : \n\n");
  FILA fila1;
  criar(&fila1);

  //Implementação das funções inserir_INI e inserir_FIM
  inserir_fim(&fila1, 100);
  inserir_fim(&fila1, 50);
  inserir_fim(&fila1, 200);

  inserir_ini(&fila1, 2);
  inserir_ini(&fila1, 1);
  
  //Implementação das funcões Imprimir || remover_INI || remover_FIM || Tamanho || getFront
  imprimir(&fila1);
  printf("Remover_INI em FILA_1 -> %d\n\n",remover_ini(&fila1));
  
  imprimir(&fila1);
  printf("Remover_FIM em FILA_1 -> %d\n\n",remover_fim(&fila1));

  imprimir(&fila1);
  printf("Tamanho da FILA_1: %d\n",tamanho(&fila1));
  printf("Remover_FIM em FILA_1 -> %d\n\n",remover_fim(&fila1));

  printf("FILA_1 Atual : ");
  imprimir(&fila1);
  printf("getFront em FILA_1 -> %d\n",getFront(&fila1));
  printf("Tamanho da FILA_1: %d\n",tamanho(&fila1));
  
  //Desalocando a Memória
  apagar(&fila1);
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

void inserir_ini(FILA *fi, int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!fi->ini)
	  fi->ini = fi->fim = novo;
  else{
	  novo->prox = fi->ini;
	  fi->ini = novo;
  }
}

void inserir_fim(FILA *fi, int dado){
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

int remover_ini(FILA *fi){
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

int remover_fim(FILA *fi){
  if (fi->fim) {
	  
    int dado = fi->fim->dado;
    struct sNODE *tmp = fi->ini, *ant = NULL;
    
    while(tmp){
      
      if(tmp == fi->fim){
        ant->prox = NULL;
        fi->fim = ant;
      }
    
    ant = tmp;
    tmp = tmp->prox;
    }

    free(tmp);
    return dado;
  } 
  
  else {
	  printf("Não há elementos. Fila vazia.\n");
	  exit(1);
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