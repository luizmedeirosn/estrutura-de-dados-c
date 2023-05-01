#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], ini = 0, fim = 0;

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int getFront(); 
int elementoNaFila();
int indiceNaFila(int indice);

int main(void) {
  for(int i = 1; i < 10; i++)
    enqueue(i);
  
  printf("\nImplementação getFront:\n");
  imprimir();
  printf("getFront -> %d\n",getFront());
  imprimir();


  printf("\nImplementação elementoNaFila:\n");
  imprimir();
  if(elementoNaFila(3))
    printf("O elemento 3 está na FILA\n");
  if(!elementoNaFila(20))
    printf("O elemento 20 NÃO está na FILA\n");
  

  printf("\nImplementação indiceNaFila:\n");
  imprimir();
  if(indiceNaFila(1))
    printf("O indice %d contém um elemento!\n",1);
  
  printf("Dequeue-> %d\n",dequeue());
  printf("Dequeue-> %d\n",dequeue());
  imprimir();
  if(!indiceNaFila(1))
    printf("O indice %d NÃO contém um elemento!\n",1);
  if(!indiceNaFila(20))
    printf("O indice %d NÃO contém um elemento!\n",20);
  
  return 0;
}

void enqueue(int elemento){
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
	l[fim] = elemento;
	//fim = (fim + 1) % MAX;
	fim++;
	if (fim == MAX) fim = 0;
  }
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
  if (ini != fim) {
	int dado = l[ini];
	//ini = (ini + 1) % MAX;
	ini++;
	if (ini == MAX) ini = 0;
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
	  if (i == MAX) 
      i = 0;
	  
    if (i == fim) 
      break;
	  printf("%d ",l[i]);
  }
  printf("]\n");
}

void apagar(){
  ini = fim = 0;
}

int getFront(){
  if(ini != fim){
    int dado = l[ini];
    return dado;
  }
  
  else{
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

int elementoNaFila(int elemento){
  int cont = ini;
  while(cont != fim){
    if(l[cont] == elemento)
      return 1;
    
    if(cont == MAX)
      cont = 0;
    
    cont++; 
  }
  return 0;
}

int indiceNaFila(int indice){
  for (int i = ini ;  ; i++) {
    if (i == indice)
      return 1;
	  
    if (i == MAX) 
      i = 0;
	  
    if (i == fim) 
      break;
  }
  return 0;
}