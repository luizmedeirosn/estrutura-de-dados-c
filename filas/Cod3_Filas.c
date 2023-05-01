#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  int voo;
  char modelo[31];
  char piloto[31];
  int qtd_p;

  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi);
void apagar(FILA *fi);

void enqueue(FILA *fi, int voo, char modelo[31], char piloto[31], int qtd_p );
void getFront(FILA *fi);
struct sNODE dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
  FILA fila;
  criar(&fila);

  //Adicionando Aviões a lista de espera
  enqueue(&fila, 1, "ABC", "Luiz", 10);
  enqueue(&fila, 2, "DEF", "Medeiros", 20);
  enqueue(&fila, 3, "GHI", "Neto", 30);
  
  //Quantidade de Aviões na lista de espera
  imprimir(&fila);
  printf("\nQuantidade de Aviões na lista de espera : %d\n\n",tamanho(&fila));
  
  //Autorizando 1ª Avião da Fila e exibindo suas informaçôes
  struct sNODE x = dequeue(&fila);
  printf("DECOLAGEM DO 1ª AVIÂO DA LISTA DE ESPERA AUTORIZADA!, INFORMAÇÕES REFERENTES AO AVIÃO:\nNmr_Voo: %d\nModelo: %s\nPiloto : %s\nNmr_Passageiros: %d\n",x.voo, x.modelo, x.piloto, x.qtd_p);
  
  //Listar todos os Aviões
  imprimir(&fila);
  
  //Listar informações do 1ª Avião da fila
  getFront(&fila);
  
  apagar(&fila);
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

void enqueue(FILA *fi, int voo, char modelo[31], char piloto[31], int qtd_p ){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->voo = voo;
  strcpy(novo->modelo, modelo);
  strcpy(novo->piloto, piloto);
  novo->qtd_p = qtd_p;
  novo->prox = NULL;

  if (!fi->ini)
	fi->ini = fi->fim = novo;
  else{
	fi->fim->prox = novo;
	fi->fim = novo;
  }
}

void getFront(FILA *fi){
  if (fi->ini)
	  printf("\nINFORMAÇÕES 1ª AVIÂO DA LISTA DE ESPERA:\nNmr_Voo: %d\nModelo: %s\nPiloto : %s\nNmr_Passageiros: %d\n",fi->ini->voo, fi->ini->modelo, fi->ini->piloto, fi->ini->qtd_p);
  
  else {
	  printf("Não há elementos. Fila vazia.\n");
	  exit(1);
  }
}

struct sNODE dequeue(FILA *fi){
  if (fi->ini) {
	  struct sNODE *tmp = fi->ini, copia;
    copia.voo = tmp->voo;
    strcpy(copia.modelo, tmp->modelo);
    strcpy(copia.piloto, tmp->piloto);
    copia.qtd_p = tmp->qtd_p;
    copia.prox = NULL;
    
	  if (fi->ini == fi->fim)
  	  fi->ini = fi->fim = NULL;
	  else
  	  fi->ini = fi->ini->prox;

	free(tmp);
	return copia;
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
  printf("\nAVÕES EM ESPERA:\n");
  while (aux){
	  printf("( Nmr_Voo: %d, Piloto: %s )\n", aux->voo, aux->piloto);
	  aux = aux->prox;
  }
}