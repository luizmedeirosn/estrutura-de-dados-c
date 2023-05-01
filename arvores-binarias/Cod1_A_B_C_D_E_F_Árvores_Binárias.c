#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL; 

struct sNODE *inserir(struct sNODE *no, int dado); 
struct sNODE *remover(struct sNODE *no, int dado);

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);

struct sNODE *apagar(struct sNODE *no);

int verifica(struct sNODE *no, int nmr);
int getMax(struct sNODE *no, int maior);
int getMin(struct sNODE *no, int maior);
void mostrarFolhas(struct sNODE *no);
int distanciaDaRaiz(struct sNODE *no, int nmr);
int alturaDaArvore(struct sNODE *no);
int distanciaEntre(struct sNODE *no,int nmr1, int nmr2);

int main(){
  raiz = inserir(raiz, 7);
  raiz = inserir(raiz, 3);
  raiz = inserir(raiz, 9);
  raiz = inserir(raiz, 1);
  raiz = inserir(raiz, 5);
  raiz = inserir(raiz, 4);
  
  //emOrdem(raiz);
  //printf("\n");
  //preOrdem(raiz);
  //printf("\n");
  posOrdem(raiz);
  printf("\n");

  printf("\ngetMax -> %d\n",getMax(raiz,raiz->dado));
  printf("getMin -> %d\n\n",getMin(raiz,raiz->dado));
  mostrarFolhas(raiz);
  printf("\n");
  printf("\ndistanciaDaRaiz, NMR %d: %d saltos\n",5,distanciaDaRaiz(raiz, 5));
  printf("AlturaDaArvore -> %d\n",alturaDaArvore(raiz));
  printf("Distancia entre %d e %d: %d saltos\n",4,9, distanciaEntre(raiz, 4,9));
  printf("Distancia entre %d e %d: %d saltos\n",1,7, distanciaEntre(raiz, 1,7));

  return 0;
}

//Função Incompleta, está gerando erro quando os números são herdeiros do mesmo filho do Nó RAIZ
int distanciaEntre(struct sNODE *no,int nmr1,int nmr2){
  int saltosEsq, saltosDir;
  
  if(!no) return -1;
  if( (no->dado >= nmr1 && no->dado <= nmr2) || (no->dado >= nmr2 && no->dado <= nmr1) )
    return  distanciaDaRaiz(no,nmr1) + distanciaDaRaiz(no,nmr2);

  saltosEsq = distanciaEntre(no->esq, nmr1, nmr2);
  saltosDir = distanciaEntre(no->dir, nmr1, nmr2);

  return (saltosEsq + saltosDir);
}

int alturaDaArvore(struct sNODE *no){
    int altura_FilhoEsquerdo,altura_FilhoDireito;
    if (!no) return -1;
    altura_FilhoEsquerdo = alturaDaArvore(no->esq);
    altura_FilhoDireito = alturaDaArvore(no->dir);
    
    if (altura_FilhoEsquerdo > altura_FilhoDireito) return altura_FilhoEsquerdo + 1;
    else return altura_FilhoDireito + 1;
}

int distanciaDaRaiz(struct sNODE *no, int nmr){
  if(buscar(raiz, nmr)){
    int saltos;
    if(no->dado == nmr) return 0;
    
    else if(nmr < no->dado){
      saltos = distanciaDaRaiz(no->esq, nmr);
      return saltos + 1;
    }
    else{
      saltos = distanciaDaRaiz(no->dir, nmr);
      return saltos + 1;
    }
  }

  else{
    printf("\nNúmero passado como argumento NÃO EXISTE!\n");
    exit(1);
  }
} 

void mostrarFolhas(struct sNODE *no){
  if(no){
    mostrarFolhas(no->esq);
    if(!no->esq && !no->dir) printf("(nóFolha -> %d) ",no->dado);
    mostrarFolhas(no->dir);
  }
}

int getMin(struct sNODE *no, int menor){

  return (!no) ? menor : getMin(no->esq,no->dado);
}

int getMax(struct sNODE *no, int maior){

  return (!no) ? maior : getMax(no->dir,no->dado);
}

struct sNODE *inserir(struct sNODE *no, int dado){
  if (!no) {
	  no = (struct sNODE*) malloc(sizeof(struct sNODE));
	  no->dado = dado;
	  no->esq = no->dir = NULL;
  } 
  else if (dado < no->dado)
	  no->esq = inserir(no->esq,dado);
  else
	  no->dir = inserir(no->dir,dado);

  return no;  
}

struct sNODE *remover(struct sNODE *no, int dado){
  struct sNODE *aux = NULL, *aux2 = NULL;

  if (no) {
	  if (no->dado == dado) {
  	  if (no->esq == no->dir) {
    	  free(no);
    	  return NULL;
  	  }
  	  
      else if (!no->esq) {
    	  aux = no->dir;
    	  free(no);
    	  return aux;
  	  }
  	  
      else if (!no->dir) {
    	  aux = no->esq;
    	  free(no);
        return aux;
  	  } 
      
      else {
    	  aux = aux2 = no->dir;
    	  while (aux->esq)
      	  aux = aux->esq;
    	  aux->esq = no->esq;
    	  free(no);
    	  return aux2;
  	  }
	  }
	
    else {
  	  if (dado < no->dado)
    	  no->esq = remover(no->esq, dado);
  	  else
    	  no->dir = remover(no->dir, dado);
	  }
  }
  return no;
}

void emOrdem(struct sNODE *no){
  if (no) {
	  emOrdem(no->esq);
	  printf("%d ",no->dado);
	  emOrdem(no->dir);
  }
}

void preOrdem(struct sNODE *no){
  if (no) {
	  printf("%d ",no->dado);
	  preOrdem(no->esq);
	  preOrdem(no->dir);
  }
}

void posOrdem(struct sNODE *no){
  if (no) {
	  posOrdem(no->esq);
	  posOrdem(no->dir);
	  printf("%d ",no->dado);
  }
}

struct sNODE *buscar( struct sNODE *no, int dado){
  if (no) {
	if (no->dado == dado)
  	return no;
	else if (dado < no->dado)
  	return buscar(no->esq, dado);
	else
  	return buscar(no->dir, dado);
  }
 
  return NULL;
}

int obter(struct sNODE *no) {
  if (no)
	  return no->dado;
  else {
	  printf("Nenhum dado para retornar.");
	  exit(0);
  }
}

struct sNODE *apagar(struct sNODE *no){
  if (no) {
	  no->esq = apagar(no->esq);
	  no->dir = apagar(no->dir);
	  free(no);
  }
  return NULL;
}