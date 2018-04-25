#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Arv {struct Arv *esq; int valor; struct Arv *dir;};
typedef struct Arv arv;

arv * AchaPai(arv *, int);
void ArvoreInf(arv *, int);
void ArvorePre(arv *, int);
void ArvorePos(arv *, int);
arv * MaiorDireita(arv **);
void remover(arv **, int);
int busca (arv *, int);

int flag;


arv * AchaPai(arv *r, int n){
	if (r == NULL)
		return NULL;
	else
		if (n <= r->valor)
			if (r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, n);
		else
			if (r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, n);
}

void ArvoreInf(arv *r, int n){ 	
	if (r != NULL){ 		
		ArvoreInf(r->esq, n+1);
		if (flag)
			printf(" %d", r->valor);
		else{
			printf("%d", r->valor);
			flag = 1;
		}
		ArvoreInf(r->dir, n+1);
	}
}

void ArvorePre(arv *r, int n){ 	
	if (r != NULL){ 		
		if (flag)
			printf(" %d", r->valor);
		else{
			printf("%d", r->valor);
			flag = 1;
		}			
		ArvorePre(r->esq, n+1);
		ArvorePre(r->dir, n+1);
	}
}

void ArvorePos(arv *r, int n){ 	
	if (r != NULL){ 		
		ArvorePos(r->esq, n+1);
		ArvorePos(r->dir, n+1);
		if (flag)
			printf(" %d", r->valor);
		else{
			printf("%d", r->valor);
			flag = 1;
		}
	}	
}

arv *MaiorDireita(arv **no){
    if((*no)->dir != NULL) 
       return MaiorDireita(&(*no)->dir);
    else{
		arv *aux = *no;
		if((*no)->esq != NULL)
			*no = (*no)->esq;
		else
			*no = NULL;
		return aux;
    }
}

void remover (arv **pRaiz, int valor){
    if(*pRaiz == NULL)
		return;
    if(valor < (*pRaiz)->valor)
       remover(&(*pRaiz)->esq, valor);
    else{ 
		if (valor > (*pRaiz)->valor)
          remover(&(*pRaiz)->dir, valor);
		else{
			arv *pAux = *pRaiz;
			if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)){
                free(pAux);
                (*pRaiz) = NULL; 
            }
			else{
				if ((*pRaiz)->esq == NULL){
					(*pRaiz) = (*pRaiz)->dir;
					pAux->dir = NULL;
					free(pAux); pAux = NULL;
                }
				else{  
					if ((*pRaiz)->dir == NULL){
						(*pRaiz) = (*pRaiz)->esq;
						pAux->esq = NULL;
						free(pAux); pAux = NULL;
                    }
					else{
						pAux = MaiorDireita(&(*pRaiz)->esq); 
						pAux->esq = (*pRaiz)->esq;
						pAux->dir = (*pRaiz)->dir;
						(*pRaiz)->esq = (*pRaiz)->dir = NULL;
						free((*pRaiz));  
						*pRaiz = pAux;  pAux = NULL;   
					}
				}
            }
        }
    }
}
int busca (arv *a, int c){
   if (a == NULL)
      return 0;
   else
      return a->valor == c || busca(a->esq, c) || busca(a->dir, c);
}  
  
int main(){
	arv *raiz, *aux, *pai;
	char opcao[15];
	int num;
	
	raiz = NULL;
	while (scanf("%s", opcao) != EOF){
		if(strcmp(opcao, "I") == 0){
			scanf(" %d", &num);
			
			aux = (arv *) malloc(sizeof(arv));
			aux->valor = num;
			aux->dir = NULL;
			aux->esq = NULL;
			
			pai = AchaPai(raiz, num);
			if (pai == NULL)
				raiz = aux;
			else
				if (num <= pai->valor)
					pai->esq = aux;
				else
					pai->dir = aux;
		}
		if (strcmp(opcao, "P") == 0){
			scanf(" %d", &num);
			
			if (!busca(raiz, num))
				printf("%d nao existe\n", num);
			else
				printf("%d existe\n", num);
		}
		if (strcmp(opcao, "R") == 0){
			scanf(" %d", &num);
			
			if (busca(raiz, num) == 1)
				remover(&raiz, num);
		}
		else{
			if (strcmp(opcao, "INFIXA") == 0){
				ArvoreInf(raiz, 0);
				printf("\n");
			}
			if (strcmp(opcao, "PREFIXA") == 0){
				ArvorePre(raiz, 0);
				printf("\n");
			}
			if (strcmp(opcao, "POSFIXA") == 0){
				ArvorePos(raiz, 0);
				printf("\n");
			}
			flag = 0;
		}		
	}
	
	return 0;
}