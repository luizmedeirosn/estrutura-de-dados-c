#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 10; 
int pos = 0; 
char l[MAX][21];

void inserir_ord(char elemento[]);
void remover(char elemento[]);
int buscar(char elemento[]);

char *obter(int indice);
int tamanho();
void imprimir();
void apagar();

int main(void) {
  //função "inserir_ord"
  inserir_ord("ab"); inserir_ord("af"); inserir_ord("ac");
  printf("Lista Atual: ");
  imprimir();
  
  inserir_ord("z");
  printf("Lista Atual: ");
  imprimir();
  
  inserir_ord("bg");inserir_ord("be");
  printf("Lista Atual: ");
  imprimir();
  
  // função remover
  remover("af");remover("ab");
  printf("Lista Atual: ");
  imprimir();
  
  //funções buscar, imprimir, tamanho
  printf("O indice de bl é %d ",buscar("bl"));
  printf("e o tamanho atual da lista é %d.\n",tamanho());
  printf("O indice de bg é %d\n",buscar("bg"));

  printf("Lista Atual: ");
  imprimir();

  //função obter
  char* x = obter(0);
  printf("No indice 0 temos "); 
  for(int i = 0; i < strlen(x); i++){
    printf("%c",x[i]);
  }
  printf("\n");

  x = obter(1);
  printf("No indice 1 temos "); 
  for(int i = 0; i < strlen(x); i++){
    printf("%c",x[i]);
  }
  printf("\n");
  
  //função apagar
  apagar();
  printf("Lista Atual: ");
  imprimir();
  printf("O tamanho atual da lista é %d\n",pos);

  
  
  return 0;
}

void inserir_ord(char elemento[]){
  int i, p;
  if (pos < MAX) {
	for (i = 0 ; i < pos ; i++)
  	if (strcmp(l[i],elemento) >= 0)
    	  break;
    
	for (p = pos ; p > i ; p--)
  	strcpy(l[p],l[p-1]);
    
  strcpy(l[i],elemento);
  
  pos ++;
  }
  
  else {
	  printf("Não foi possível inserir %s. Lista cheia.\n",elemento);
  }
}

int buscar(char elemento[]){
  for (int i = 0 ; i < pos ; i++){
	if(!strcmp(l[i],elemento))
  	return i;
  }
  return -1;
}

void remover(char elemento[]){

  int p = buscar(elemento);
 
  if (p == -1)
	return;
 
  for (int i = p ; i < pos -1; i++)
	  strcpy(l[i],l[i+1]);
  
  pos--;
  
}


char *obter(int indice){
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
	printf("%s ",l[i]);
  printf("\n");
}

void apagar(){
  pos = 0;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 10; 
int pos = 0; 
char l[MAX][21];

void inserir_ord(char elemento[]);
void remover(char elemento[]);
int buscar(char elemento[]);

char *obter(int indice);
int tamanho();
void imprimir();
void apagar();

int main(void) {
  // implementando a função "inserir_ord"
  inserir_ord("ab"); inserir_ord("af"); inserir_ord("ac");
  printf("Lista Atual: ");
  imprimir();
  
  inserir_ord("z");
  printf("Lista Atual: ");
  imprimir();
  
  inserir_ord("bg");inserir_ord("be");
  printf("Lista Atual: ");
  imprimir();
  
  //implementando a função remover
  remover("af");remover("ab");
  printf("Lista Atual: ");
  imprimir();
  
  //implementando as funções buscar, imprimir, tamanho
  printf("O indice de bl é %d ",buscar("bl"));
  printf("e o tamanho atual da lista é %d.\n",tamanho());
  printf("O indice de bg é %d\n",buscar("bg"));

  printf("Lista Atual: ");
  imprimir();

  // implementando as função obter
  char* x = obter(0);
  printf("No indice 0 temos "); 
  for(int i = 0; i < strlen(x); i++){
    printf("%c",x[i]);
  }
  printf("\n");

  x = obter(1);
  printf("No indice 1 temos "); 
  for(int i = 0; i < strlen(x); i++){
    printf("%c",x[i]);
  }
  printf("\n");
  
  //implementando a função apagar
  apagar();
  printf("Lista Atual: ");
  imprimir();
  printf("O tamanho atual da lista é %d\n",pos);

  
  
  return 0;
}

void inserir_ord(char elemento[]){
  int i, p;
  if (pos < MAX) {
	for (i = 0 ; i < pos ; i++)
  	if (strcmp(l[i],elemento) >= 0)
    	  break;
    
	for (p = pos ; p > i ; p--)
  	strcpy(l[p],l[p-1]);
    
  strcpy(l[i],elemento);
  
  pos ++;
  }
  
  else {
	  printf("Não foi possível inserir %s. Lista cheia.\n",elemento);
  }
}

int buscar(char elemento[]){
  for (int i = 0 ; i < pos ; i++){
	if(!strcmp(l[i],elemento))
  	return i;
  }
  return -1;
}

void remover(char elemento[]){

  int p = buscar(elemento);
 
  if (p == -1)
	return;
 
  for (int i = p ; i < pos -1; i++)
	  strcpy(l[i],l[i+1]);
  
  pos--;
  
}


char *obter(int indice){
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
	printf("%s ",l[i]);
  printf("\n");
}

void apagar(){
  pos = 0;
}