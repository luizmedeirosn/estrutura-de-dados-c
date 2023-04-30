#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

typedef struct sLISTA{
  struct sNODE *ini, *fim;
}LISTA;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);


int main(){
  LISTA lst1, lst2; //criação de variaveis tipo LISTA
  inicializar(&lst1);inicializar(&lst2); //implementando a função inicializar
  
  //Lista1
  //Impletação da função inserir_ord e imprimir
  printf("\nLISTA_1 :\n\n");
  for(int i = 3; i >= 0; i--)
    inserir_ord(&lst1,i);
  imprimir(&lst1);
  
  for(int i = 3; i > 0; i--)
    inserir_ord(&lst1,i*-1);
  imprimir(&lst1);
  
  //Implementação da função remover
  remover(&lst1,2);remover(&lst1,-2);
  imprimir(&lst1);

  //Implementação da função buscar e obter
  printf("O elemento 3 está no endereço de memória %p\n",buscar(&lst1,3));
  printf("No endereço de memória %p está o elemento %d\n",buscar(&lst1,3),obter(buscar(&lst1,3)));
  imprimir(&lst1);
  
  //Implementaçao da função tamanho e apagar
  printf("O tamanho atual da LISTA_1 é de %d NÓS\n",tamanho(&lst1));
  apagar(&lst1);
  printf("Depois de apagá-la o tamanho é de %d NÓS\n\n",tamanho(&lst1));


  //Lista2
  //Impletação da função inserir_ord e imprimir
  printf("\nLISTA_2 :\n\n");
  for(int i = 5; i >= 0; i--)
    inserir_ord(&lst2,i*10);
  imprimir(&lst2);
  
  for(int i = 3; i > 0; i--)
    inserir_ord(&lst2,i*-10);
  imprimir(&lst2);
  
  //Implementação da função remover
  remover(&lst2,20);remover(&lst2,-20);
  imprimir(&lst2);

  //Implementação da função buscar e obter
  printf("O elemento 30 está no endereço de memória %p\n",buscar(&lst2,30));
  printf("No endereço de memória %p está o elemento %d\n",buscar(&lst2,30),obter(buscar(&lst2,30)));
  imprimir(&lst2);
  
  //Implementaçao da função tamanho e apagar
  printf("O tamanho atual da LISTA_2 é de %d NÓS\n",tamanho(&lst2));
  apagar(&lst2);
  printf("Depois de apagá-la o tamanho é de %d NÓS\n\n",tamanho(&lst2));


  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini, *ant;
 
  while (aux){
    ant = aux;
	  aux = aux->prox;
	  free(ant);
  }
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir_ord(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini, *ant = NULL;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  novo->dado = dado;
  novo->prox = NULL;

  while(aux && dado > aux->dado){
	ant = aux;
	aux = aux->prox;
  }

  if (!lst->ini)
	lst->ini = lst->fim = novo;
  
  else if (aux == lst->ini){
	  novo->prox = lst->ini;
	  lst->ini = novo;
  } 
  
  else if (!aux){
	  lst->fim->prox = novo;
	  lst->fim = novo;
  } 
  
  else {
    ant->prox = novo;
	  novo->prox = aux;
  }
}

struct sNODE *buscar(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini;

  while (aux){
	if (dado == aux->dado)
  	return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	
    if (aux == lst->ini)
    	lst->ini = lst->ini->prox;
  	
    else if(aux == lst->fim){
    	ant->prox = NULL;
    	lst->fim = ant;
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

int obter(struct sNODE *node){
  if (!node){
	  printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(LISTA * lst){
  struct sNODE *aux = lst->ini;
  int tam = 0;
 
  while (aux){
	  tam++;
	  aux = aux->prox;
  }
 
  return tam;
}

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
 
  printf("Lista atual [ ");
  while (aux){
	  printf("%d ", aux->dado);
  	aux = aux->prox;
  }
  printf("]\n");
}