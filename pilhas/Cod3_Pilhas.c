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

int verifica(char string[], char c1, char c2);

int main(void) {
  int resp;
  char string[101];
  printf("Informe a String:\n");
  scanf("%[^\n]s",string);

  resp += verifica(string, '(', ')');
  resp += verifica(string, '[', ']');
  resp += verifica(string, '{', '}');

  if(resp == 3)
    printf("Balanceado\n");
  else
    printf("Não Balanceado\n");

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

int verifica(char string[], char c1, char c2){
  for(int i = 0; i < strlen(string); i ++){
    if( string[i] == c1 || string[i] == c2 ){
      
      if( (string[i] == c1 && getTopo() == c2) || (string[i] == c2 && getTopo() == c1 ))
        pop();
      else
        push(string[i]);
    }
  }
  if(tamanho() == 0)
    return 1;
  else
    return 0;
}