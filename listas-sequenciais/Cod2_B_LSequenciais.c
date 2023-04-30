#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10; 
int l[MAX], pos = 0; 

void inserir_ord(int elemento);
void inserir(int elemento);
void remover(int elemento);
int buscar(int elemento);

int obter(int indice);
int tamanho();
void imprimir();
void apagar();

int main(void) {
  int op,elemento;
  for(int i = 0; i < 5 ; i++)
    inserir(2 * i);
  inserir(2);
  inserir(2);
  
  while(1){
    printf("\nLista Atual: ");
    imprimir();
    printf("\n1- Inserir um elemento na lista\n2- Remover um elemento \n3- Buscar o indice de um elemento\n4- Informe um indice válido para obter o elemento correspondente\n5- Tamanho da lista\n6- Imprimir lista\n7- Apagar lista \n8- Sair\n");
    scanf("%d",&op);
    printf("\n");

      if(op == 1){
        printf("valor para uso:\n");
        scanf("%d",&elemento);
        inserir(elemento);
      }

      if(op == 2){
        printf("valor para uso:\n");
        scanf("%d",&elemento);
        remover(elemento);
      }

      if(op == 3){
        printf("valor para uso:\n");
        scanf("%d",&elemento);
        printf("O indice do valor informado é %d\n",buscar(elemento));
      }

      if(op == 4){
        printf("valor para uso:\n");
        scanf("%d",&elemento);
        elemento = obter(elemento);
        printf("O elemento do indice informado é %d\n",elemento);
      }
      
      if(op == 5)
        printf("O tamanho da lista é %d\n",tamanho());
        

      if(op == 6)
        imprimir();
        

      if(op == 7)
        apagar();
      

      if(op < 1 || op > 7)
        break;

  }

  return 0;
}

void inserir_ord(int elemento){
  int i, p;
  if (pos < MAX) {
	for (i = 0 ; i < pos ; i++)
  	    if (l[i] >= elemento)
    	        break;
    
	for (p = pos ; p > i ; p--)
  	    l[p] = l[p-1];
    
	l[i] = elemento;
  
  pos ++;
  }
  
  else {
	  printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

void inserir(int elemento){
  if (pos < MAX)
	  l[pos++] = elemento;
  
  else {
	  printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

int buscar(int elemento){
  for (int i = 0 ; i < pos ; i++){
	if (l[i] == elemento)
  	return i;
  }
  return -1;
}

void remover(int elemento){

  while(1){
  int p = buscar(elemento);
 
  if (p == -1)
	return;
 
  for (int i = p ; i < pos -1; i++)
	  l[i] = l[i+1];
  pos--;
  }
}

int obter(int indice){
  if (indice < 0 || indice >= pos) {
	printf("Indice %d fora dos limites da Lista.\n", indice);
	exit(1);
  }
  return l[indice];
}

int tamanho(){
  return pos;
}

void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}

void apagar(){
  pos = 0;
}