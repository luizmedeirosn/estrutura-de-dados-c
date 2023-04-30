#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 101;
int l[MAX], pos = 0;

void push(int elemento);
int getTopo();
int pop();

int tamanho();
void imprimir();
void apagar();

void print_reverso(char string[]);

int main(void) {
  //Implementando a nova 'função'
  print_reverso("ESTRUTURA DE DADOS EH BOM DEMAIS");
  print_reverso("LUIZ MEDEIROS NETO");
  print_reverso("VICTOR ANDRE");
  return 0;
}

int getTopo(){
  if(pos)
    return l[pos-1];

  else {
    printf("Não há elementos. Pilha vazia.\n");
    exit(1);
  }	  
}

void push(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else
	printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

int pop(){
  if (pos)
	  return l[--pos];
  else {
	  printf("Não há elementos. Pilha vazia.\n");
	  exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("P[ ");
  for (int i = pos -1 ; i >= 0 ; i--)
	printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}

void print_reverso(char string[]){
  for(int i = 0; i < strlen(string); i++){
    push(string[i]);
    if(string[i] == ' '){
      while( tamanho() != 0)
        printf("%c",pop());
    }
  }
  printf(" ");
  while( tamanho() != 0)
    printf("%c",pop());
  printf("\n");
}
