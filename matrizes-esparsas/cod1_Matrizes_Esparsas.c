#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  unsigned col;
  unsigned dado;
  struct sNODE *prox;
};

struct sMATRIZ{
  int lin, col;
  struct sNODE **m;
};

struct sMATRIZ m;

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, int dado);
int acessar(unsigned lin, unsigned col);

int tamanho();
void imprimir();
void apagar();

int getMaior();
int getMenor();
void dPrincipal();
void dSecundaria();
int count(int nmr);

int main(void) {
  inicializar(4,4);

  atribuir(0, 0, 1);
  atribuir(0, 1, 1);
  atribuir(1, 0, 1);
  atribuir(1, 1, 7);
  atribuir(2, 1, 2);
  imprimir();
  
  printf("getMaior: %d\n",getMaior());
  printf("getMenor: %d\n",getMenor());
  printf("DiagoPrinc: ");
  dPrincipal();
  printf("DiagoSecund: ");
  dSecundaria();
  printf("\n");
  printf("Count 1: %d\n",count(1));
  printf("Count 7: %d\n",count(7));
  printf("Count 0: %d\n",count(0));

  return 0;
}
int count(int nmr){
  int cont = 0;
  for (int i = 0 ; i < m.lin ; i++) {
    struct sNODE *aux = m.m[i];
	  for (int j = 0 ; j < m.col ; j++) {
  	  if (aux && j == aux->col) {
    	  if(nmr == aux->dado) cont++;
    	  aux = aux->prox;
  	   }
       else if(nmr == 0) cont++;
	  }
  }

  return cont;
}
void dSecundaria(){
  if(m.col==m.lin){
    for (int i = 0 ; i < m.lin ; i++) {
	    struct sNODE *aux = m.m[i];

	    for (int j = 0 ; j < m.col ; j++) {
  	    if (aux && j == aux->col) {
    	    if(m.col -1 == (i + j )){
            printf("%d ",aux->dado);
            break;
          }
    	    aux = aux->prox;
          
  	    }
        else if(!aux && (m.col -1 == (i + j))) printf("%d ",0);
      }
    }
  }
  else{
    printf("Matriz não Quadrada!\n");
    exit(0);
  } 

}

void dPrincipal(){
  if(m.col == m.lin){
    for (int i = 0 ; i < m.lin ; i++) {
	    struct sNODE *aux = m.m[i];

	    for (int j = 0 ; j < m.col ; j++){
  	    if (aux && j == aux->col) {
    	    if(j == i) printf("%d ",aux->dado); 
          aux = aux->prox;
        }
        else if(j == i) printf("%d ",0); 
        }
    }
    printf("\n");
  }
  
  else {
    printf("Matriz não Quadrada!\n");
    exit(0);
  }
  ;
}

int getMenor(){
  int menor = 1000000;
  for (int i = 0 ; i < m.lin ; i++) {
    struct sNODE *aux = m.m[i];

	  for (int j = 0 ; j < m.col ; j++) {
  	  if (aux && j == aux->col){
        if(menor > aux->dado) menor = aux->dado;
        aux = aux->prox;
      }
      else menor = 0;
	  }
  }
  return menor;
}

int getMaior(){
  int maior = 0;
  for (int i = 0 ; i < m.lin ; i++) {
    struct sNODE *aux = m.m[i];

	  for (int j = 0 ; j < m.col ; j++) {
  	  if (aux && j == aux->col){
        if(maior < aux->dado) maior = aux->dado;
        aux = aux->prox;
      }
	  }
  }
  return maior;
}

void inicializar(unsigned t_lin, unsigned t_col){
  m.lin = t_lin;
  m.col = t_col;
  m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);

  for (int i = 0 ; i < m.lin ; i++)
	m.m[i] = NULL;
}

void atribuir(unsigned lin, unsigned col, int dado) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin], *ant = NULL;

	while (aux && col > aux->col) {
  	ant = aux;
  	aux = aux->prox;
	}

	if (aux && aux->col == col){
  	   if (dado == 0) {
    	      if (ant == NULL) m.m[lin] = aux->prox;
    	      else ant->prox = aux->prox;

    	   free(aux);

  	} else aux->dado = dado;

	} else if (dado != 0) {
  	   struct sNODE *novo = (struct sNODE *) malloc(sizeof(struct sNODE));
  	   novo->col = col;
  	   novo->dado = dado;
  	   novo->prox = aux;
  	   if (ant == NULL) m.m[lin] = novo;
  	   else ant->prox = novo;
	}

  } else {
	printf("Não é possível inserir elementos fora da Matriz.\n");
	exit(0);
  }
}

int acessar(unsigned lin, unsigned col) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin];

	while (aux && col > aux->col)
  	   aux = aux->prox;
    
	if (aux && col == aux->col)
  	return aux->dado;
    
	return 0;
  } else {
	printf("Não é possível acessar elementos fora da Matriz.\n");
	exit(0);
  }
}

int tamanho() {
  return m.lin * m.col;
}

void imprimir(){
  printf("M[\n");
  for (int i = 0 ; i < m.lin ; i++) {
	struct sNODE *aux = m.m[i];

	for (int j = 0 ; j < m.col ; j++) {
  	   if (aux && j == aux->col) {
    	      printf("%4d ",aux->dado);
    	      aux = aux->prox;
  	   } else printf("%4d ",0);
	}
	printf("\n");
  }
  printf("]\n");
}

void apagar(){
  for (int i = 0 ; i < m.lin ; i++) {
	struct sNODE *aux = m.m[i], *ant = NULL;

	while (aux) {
  	   ant = aux;
  	   aux = aux->prox;
  	   free(ant);
	}
  }
  free(m.m);
}
