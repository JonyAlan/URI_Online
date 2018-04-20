#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct arvore {struct arvore *esq;
					   struct arvore *dir;
					   char valor;}
					   TArvore; 
					   
int sai;

void ImprimeArvorein(TArvore*r){
	if(r != NULL){
		ImprimeArvorein(r->esq);
		if(sai)
			printf(" %c",r->valor);
		else{
			printf("%c",r->valor);
			sai++;
		}
		ImprimeArvorein(r->dir);
	}
}

void ImprimeArvorepre(TArvore*r){
	if(r != NULL){
		if(sai)
			printf(" %c",r->valor);
		else{
			printf("%c",r->valor);
			sai++;
		}
		ImprimeArvorepre(r->esq);
		ImprimeArvorepre(r->dir);
	}
}

void ImprimeArvorepos(TArvore*r){
	if(r != NULL){
		ImprimeArvorepos(r->esq);
		ImprimeArvorepos(r->dir);
		if(sai)
			printf(" %c",r->valor);
		else{
			printf("%c",r->valor);
			sai++;
		}
	}
}
TArvore * AchaPai(TArvore *r, int v)
{	if(r == NULL)
		return NULL;
	else
		if(v <= r->valor)
		  if(r->esq == NULL)
				return r;
		else
				return AchaPai(r->esq, v);
		else
			if(r->dir == NULL)
				return r;
		else
				return AchaPai(r->dir, v);
}
int busca(TArvore *r, char vBusca)
{	if(r){
    if(r ->valor == vBusca)
			return 1;
    else{
		if(r ->valor < vBusca)
			return busca(r->dir, vBusca);
		else
			return busca(r->esq, vBusca);
    }
		return 0;
  }
}			    
int main(){
	TArvore *raiz = NULL, *pai, *aux;
	char VArv,VBusca,opcao[8];

	
	while(scanf("%s",opcao)!=EOF){
		if(strcmp(opcao,"I")==0){
			scanf(" %c",&VArv);
			
			aux=(TArvore*)malloc(sizeof(TArvore));
			aux->valor=VArv;
			aux->dir=NULL;
			aux->esq=NULL;
			
			pai=AchaPai(raiz,VArv);
			if(pai==NULL)
				raiz = aux;
			else
				if(VArv <= pai->valor)
					pai->esq = aux;
				else
					pai->dir = aux;
		}
	else if(strcmp(opcao,"P")==0){
			scanf(" %c", &VBusca);
			if(busca(raiz,VBusca)==1)
				printf("%c existe\n", VBusca);
			else
				printf("%c nao existe\n", VBusca);
		}
	else{
			if(strcmp(opcao,"INFIXA")==0)
				ImprimeArvorein(raiz);
			
			if(strcmp(opcao,"PREFIXA")==0)
				ImprimeArvorepre(raiz);
			
			if(strcmp(opcao,"POSFIXA")==0)
				ImprimeArvorepos(raiz);

			printf("\n");
			sai = 0;
		}
	}
	return 0;
}