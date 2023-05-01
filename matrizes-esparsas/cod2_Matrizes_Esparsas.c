#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  unsigned col;
  char *dado;
  struct sNODE *prox;
};

struct sMATRIZ{
  int lin, col;
  struct sNODE **m;
};

struct sMATRIZ m;

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, char dado[]);
char acessar(unsigned lin, unsigned col);

int tamanho();
void imprimir();
void apagar();

int main(void) {
  inicializar(4, 4);
  atribuir(0, 0, "Luiz");
  atribuir(0, 1, "Medeiros");
  atribuir(0, 2, "Neto");
  atribuir(1, 0, "Jonh");
  atribuir(3, 2, "Ana");

  imprimir();
  apagar();
  return 0;
}

void inicializar(unsigned t_lin, unsigned t_col){
  m.lin = t_lin;
  m.col = t_col;
  m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);

  for (int i = 0 ; i < m.lin ; i++)
	m.m[i] = NULL;
}

void atribuir(unsigned lin, unsigned col, char dado[]) {
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

char acessar(unsigned lin, unsigned col) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin];

	while (aux && col > aux->col)
  	   aux = aux->prox;
    
	if (aux && col == aux->col)
  	return *aux->dado;
    
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
    	      printf("%10s ",aux->dado);
    	      aux = aux->prox;
  	   } else printf("%10s "," ''");
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