#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  char nome[31];
  char ocup[31];
  float salario;
  int peso;
  struct sNODE *ant;
  struct sNODE *prox;
};

typedef struct sLISTA{
  struct sNODE *ini, *fim;
}LISTA;

LISTA head_Gerente, head_Supervisor, head_Peao;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, char nome[], char ocup[], float salario);
void inserir(LISTA *lst, char nome[], char ocup[], float salario);
void inserir_ordFunc(LISTA *lst, char nome[], char ocup[], float salario);
void remover(LISTA *lst, char nome[]);
struct sNODE *buscar(LISTA *lst, char nome[]);

float obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

int main(){
  LISTA lst;
  //Implementação da função inicializar
  inicializar(&lst);
  inicializar(&head_Gerente);inicializar(&head_Supervisor);inicializar(&head_Peao);

  //OBS: as funçoes inserir_ord e inserir são implementadas dentro da função inserir_ordFunc
  printf("\nPRIMEIRA DEMONSTRAÇÃO :\n\n");
  inserir_ordFunc(&lst,"Luiz","Gerente",18700.00);
  inserir_ordFunc(&lst,"Lucas","Peao",3100.00);
  inserir_ordFunc(&lst,"Mara","Peao",3250.00);
  imprimir(&lst);
  printf("\n\n");

  printf("APÓS A INSERÇÃO DE OUTROS FUNCIOÁRIOS :\n\n");
  inserir_ordFunc(&lst,"Bob","Supervisor",5000.00);
  inserir_ordFunc(&lst,"Ana","Supervisor",8200.00);
  inserir_ordFunc(&lst,"Vanessa","Gerente",16500.00);
  inserir_ordFunc(&lst,"Neto","Supervisor",7400.00);
  imprimir(&lst);
  printf("\n\n");

  printf("APÓS A EXCLUSÃO DE ALGUNS FUNCIOÁRIOS :\n\n");
  remover(&lst,"Luiz");
  remover(&lst,"Ana");
  imprimir(&lst);
  printf("\n\n");

  printf("IMPLEMENTANDO AS FUNÇÕES BUSCAR E OBTER :\n\n");
  printf("Neto está no endereço de memória %p da LISTA.\n",buscar(&lst,"Neto"));
  printf("O Salário de Neto é %.2f.\n",obter(buscar(&lst,"Neto")));
  printf("\n\n");
  
  printf("IMPLEMENTAÇÃO DAS FUNÇÕES TAMANHO E APAGAR :\n\n");
  printf("O tamanho atual da LISTA tem valor %d.\n", tamanho(&lst));
  apagar(&lst);
  printf("Após apagá-lá seu tamanho tem valor %d.\n", tamanho(&lst));
  
  apagar(&head_Gerente);apagar(&head_Supervisor);apagar(&head_Peao);
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


void inserir_ord(LISTA *lst, char nome[], char ocup[], float salario){
  struct sNODE *aux = lst->ini;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  strcpy(novo->nome,nome);
  strcpy(novo->ocup,ocup);
  novo->salario = salario;
  novo->ant = NULL;
  novo->prox = NULL;

  while(aux && salario < aux->salario)
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

void inserir(LISTA *lst, char nome[], char ocup[], float salario){
  struct sNODE *aux = lst->ini;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  strcpy(novo->nome,nome);
  strcpy(novo->ocup,ocup);
  novo->salario = salario;
  novo->ant = NULL;
  novo->prox = NULL;
  
  if (!lst->ini){
    lst->ini = novo;
    lst->fim = novo;
  }
	  
  else{
	  lst->fim->prox = novo;
	  novo->ant = lst->fim;
	  lst->fim = novo;
  }
}

void inserir_ordFunc(LISTA *lst ,char nome[], char ocup[], float salario){
  if(!strcmp("Gerente",ocup))
    inserir_ord(&head_Gerente, nome, ocup, salario);
  if(!strcmp("Supervisor",ocup))
    inserir_ord(&head_Supervisor, nome, ocup, salario);
  if(!strcmp("Peao",ocup))
    inserir_ord(&head_Peao, nome, ocup, salario);

  apagar(lst);

  
  struct sNODE *aux = head_Gerente.ini;
  while(aux){
    inserir(lst, aux->nome, aux->ocup, aux->salario);
    aux = aux->prox;
  }
  
  aux = head_Supervisor.ini;
  while(aux){
    inserir(lst, aux->nome, aux->ocup, aux->salario);
    aux = aux->prox;
  }

  aux = head_Peao.ini;
  while(aux){
    inserir(lst, aux->nome, aux->ocup, aux->salario);
    aux = aux->prox;
  }
  
}

struct sNODE *buscar(LISTA *lst, char nome[]){
  struct sNODE *aux = lst->ini;

  while (aux){
	if (!strcmp(nome,aux->nome))
    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(LISTA *lst, char nome[]){
  struct sNODE *aux = buscar(lst,nome);

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

float obter(struct sNODE *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->salario;
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
  while (aux){
	  printf("( Ocupação: %s, Salario: %.2f, Nome: %s )\n",aux->ocup,aux->salario,aux->nome);
	  aux = aux->prox;
  }
}