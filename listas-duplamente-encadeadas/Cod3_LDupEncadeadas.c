#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
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
void imprimir_reverso(LISTA *lst);

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
  printf("No endereço de memória %p está o elemento %d\n\n",buscar(&lst2,30),obter(buscar(&lst2,30)));
  imprimir(&lst2);
  printf("IMPRIMIR_REVERSO : ");
  imprimir_reverso(&lst2);// emprego da função imprimir reverso para testar se o programa está fazendo as devidas atribuições aos ponteiros ant dos NÓS
  
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
  struct sNODE *aux = lst->ini;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  novo->dado = dado;
  novo->ant = NULL;
  novo->prox = NULL;

  while(aux && dado > aux->dado)
	  aux = aux->prox;

  if (!lst->ini)
	  lst->ini = lst->fim = novo;
  
  else if (aux == lst->ini){
	  novo->prox = lst->ini;
	  lst->ini->ant = novo;
	  lst->ini = novo;
  } 
  
  else if (!aux){
	  lst->fim->prox = novo;
	  novo->ant = lst->fim;
	  lst->fim = novo;
  } 
  
  else {
	  aux->ant->prox = novo;
	  novo->ant = aux->ant;
	  novo->prox = aux;
	  aux->ant = novo;
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
  struct sNODE *aux = buscar(lst,dado);

  if (!aux)
	return;

  if (!aux->ant && !aux->prox)
	  lst->ini = lst->fim = NULL;
  
  else if (aux == lst->ini) {
	  lst->ini = lst->ini->prox;
	  lst->ini->ant = NULL;
  } 
  
  else if (aux == lst->fim) {
	  lst->fim = lst->fim->ant;
	  lst->fim->prox = NULL;
  } 
  
  else {
	  aux->ant->prox = aux->prox;
	  aux->prox->ant = aux->ant;
  }
  free(aux);
}

int obter(struct sNODE *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(LISTA *lst){
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
 
  printf("[ ");
  while (aux){
	  printf("%d ", aux->dado);
	  aux = aux->prox;
  }
  printf("]\n");
}

void imprimir_reverso(LISTA *lst){
  struct sNODE *aux = lst->fim;
 
  printf("[ ");
  while (aux){
	  printf("%d ", aux->dado);
	  aux = aux->ant;
  }
  printf("]\n");
}