#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct RegJogador{
	char n[31];
	short valor;
	struct RegJogador *ant;
	struct RegJogador *prox;	
};

typedef struct RegJogador TJogador;

typedef enum{
	false, true
}bool;

TJogador *recebeLista(int numRegs);
TJogador *excluiReg(TJogador *, TJogador *);

int main(){
	TJogador *l, *regAtual, *aux;
	short numJogadores, valor;
	int i;
	bool par;

	while(scanf("%hd" , &numJogadores) && numJogadores){
		l = recebeLista(numJogadores);
	
		aux = l;
		valor = aux->valor;
		(valor % 2 == 0) ? (par = true) : (par = false);
		while(aux != aux->prox && aux != aux->ant){
			regAtual = aux;

			if(par)
				while(valor--)
					regAtual = regAtual->ant;
			else
				while(valor--)
					regAtual = regAtual->prox;			
				
						valor = regAtual->valor;
			
			if(valor % 2 == 0){
			 	par = true;
			 	aux = regAtual->ant;
			}else{
			 	par = false;
			 	aux = regAtual->prox;
			}
			valor--;
			
			l = excluiReg(l, regAtual);
		}
		printf("Vencedor(a): %s\n", l->n);	
	}	
	
	return 0;}

TJogador *recebeLista(int numRegs){
	TJogador *inicio = NULL, *regAtual, *regAnt;
	int i;

	for(i = 0; i < numRegs; i++){
		regAtual = (TJogador *)malloc(sizeof(TJogador));

		scanf(" %s %hd", regAtual->n, &regAtual->valor);

		if(inicio == NULL)
			inicio = regAtual;
			else {
				regAnt->prox = regAtual;
				regAtual->ant = regAnt;
		}
		regAnt = regAtual;
	}
	inicio->ant = regAtual;
	regAtual->prox = inicio;

	return inicio;
}

TJogador *excluiReg(TJogador *l, TJogador *regExcluir){
	TJogador *regAnt = regExcluir->ant; 
	TJogador *regProx = regExcluir->prox;
	
	if(regExcluir == l){
		l = l->prox;
		regAnt->prox = l; 	
		l->ant = regExcluir->ant;
	}
		else{
		regAnt->prox = regProx;
		regProx->ant = regAnt;
	}
	free(regExcluir);

	return l;
}