#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 101;
char l[MAX];
int pos = 0;

void push(char elemento);
char getTopo();
int pop();

int tamanho();
void imprimir();
void apagar();

void verifica(char string[]);

int main(void) {
  int resp;
  char string[101];
  printf("Informe a String:\n");
  scanf("%[^\n]s",string);
  verifica(string);

  return 0;
}

void push(char elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else
	printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

char getTopo(){
	return l[pos-1];
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
  for (int i = pos -1 ; i >= 0 ; i--)
	printf("%c",l[i]);
}

void apagar(){
  pos = 0;
}

void verifica(char string[]){
  int cont = 0;
  while(cont < strlen(string)){
    if( string[cont] == '(' || string[cont] == ')' ){
      
      if( string[cont] == '(')
        push(string[cont]);
      if(getTopo() == '(' && string[cont] == ')')
        pop();
    }
    cont++;
  }
  if(tamanho() == 0)
    printf("OK!\n");
  else
    printf("Não OK!\n");
}