#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], ini = 0, fim = 0;

void inserir_ini(int elemento);
void inserir_fim(int elemento);
int remover_ini();
int remover_fim();

int tamanho();
void imprimir();
void apagar();

int main(){
  //Implementação de todas as funções do DEQUE
  inserir_fim(4);
  inserir_fim(5);
  inserir_fim(6);
  inserir_fim(7);
  inserir_fim(8);
  inserir_fim(9);
  
  inserir_ini(3);
  inserir_ini(2);
  inserir_ini(1);
  
  inserir_ini(0);
  inserir_fim(10);
  
  printf("\n");
  imprimir();
  printf("Remover_INI -> %d\n\n",remover_ini());
  imprimir();
  printf("Remover_FIM -> %d\n\n",remover_fim());
  imprimir();
  printf("Remover_FIM -> %d\n\n",remover_fim());
  imprimir();
  printf("Remover_FIM -> %d\n\n",remover_fim());
  imprimir();
  printf("Remover_INI -> %d\n\n",remover_ini());
  imprimir();
  
  printf("\nApós adicionar alguns elementos no INI e FIM:\n");
  inserir_ini(8);
  inserir_fim(7);
  inserir_ini(5);
  inserir_fim(10);
  imprimir();
  printf("TAM: %d\n",tamanho());

  apagar();

  return 0;
}

void inserir_ini(int elemento){
  if(!ini){
    if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
	    l[MAX-1] = elemento;
	    ini = (MAX - 1);
    }
    else
	    printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
  }
  else{
    if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
      l[--ini] = elemento;
    }
    else
	    printf("Não foi possível inserir %d. Fila cheia.\n",elemento);  
  }
}

void inserir_fim(int elemento){
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
	  l[fim] = elemento;
	  fim++;
	  if (fim == MAX) 
      fim = 0;
  }
  else
	  printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int remover_ini(){
  if (ini != fim) {
	  int dado = l[ini];
	  ini++;
	  if (ini == MAX) 
      ini = 0;
	  return dado;
  }
  else {
	  printf("Não há elementos. Fila vazia.\n");
	  exit(1);
  }
}

int remover_fim(){
  if (ini != fim) {
    int dado;
    
    if(fim == 0){
      dado = l[MAX -1];
      fim = (MAX - 1);
    }
    
    else{
      dado = l[fim-1];
	    fim--;
    }
	  
    return dado;
  }
  
  else {
	  printf("Não há elementos. Fila vazia.\n");
	  exit(1);
  }
}

int tamanho(){
  if (ini <= fim)
	  return fim - ini;
  else
	  return MAX - (ini - fim);
}

void imprimir(){
  printf("F[ ");
  for (int i = ini ;  ; i++) {
	  if (i == MAX) i = 0;
	  if (i == fim) break;
    //if(l[i])
	    printf("%d ",l[i]);
  }
  printf("]\n");
}

void apagar(){
  ini = fim = 0;
}