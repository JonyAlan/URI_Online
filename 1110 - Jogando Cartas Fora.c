#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Cartas 	{	char carta;
					struct Cartas *prox;};
typedef struct Cartas TCartas;

struct descrPilha 	{ 	TCartas *topo, *final;
						int qtd;};
typedef struct descrPilha DPilha;

int main()
{
	int Descar[56], Cqtd, c=0, k=0;
	DPilha	descritor;
	TCartas *aux;

	while (scanf("%d", &Cqtd) && Cqtd != 0)
	{
		for(c=0; c < 55; c++)
			Descar[c] = 0;
		k = 0;

		descritor.topo = NULL;
		descritor.qtd = 0;

		for(c=Cqtd; c > 0; c--)
		{
			aux = (TCartas *) malloc(sizeof(TCartas));

			if(aux == NULL)
				break;

			aux->carta = c;
			aux->prox = descritor.topo;

			descritor.topo = aux;
			descritor.qtd++;

			if(c == Cqtd)
				descritor.final = aux;
		}

		while (descritor.qtd >= 2)
		{
		aux = descritor.topo;
		descritor.topo = aux->prox;
		Descar[k] = aux->carta;
		free(aux);
		descritor.qtd--;
		k = k + 1;
		aux = descritor.topo->prox;
		descritor.final->prox = descritor.topo;
		descritor.final = descritor.topo;
		descritor.topo = aux;
		}
			printf("Discarded cards:");
		for(c=0; c < k; c++)
		{
			printf(" %d", Descar[c]);
			if(c != k-1)
				printf(",");
		}
		printf("\nRemaining card: %d\n", descritor.final->carta);
}

	return 0;
}