#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct max	{char sequen;
			struct max *prox;};
				
typedef struct max diant;

struct descrPilha {diant *topo;};
typedef struct descrPilha Dpilha;

int main()
{
char linha[1011] = "";
Dpilha	descritor;
diant *aux, *aux2;
int cont1, Dqtd =0, cont = 0, i=0;

	scanf("%d", &cont1);

	while(cont < cont1)
	{
		scanf("%s", linha);
		descritor.topo = NULL;
		i = 0;
		Dqtd = 0;

	  while(i < strlen(linha))
		{
			if(linha[i] == '<')
			{
				aux = (diant *) malloc(sizeof(diant));

				if(aux == NULL)
				break;
				aux->sequen = linha[i];
				aux->prox = descritor.topo;
				descritor.topo = aux;
			}

			else if(linha[i] == '>')
			{
				if(descritor.topo != NULL)
				{	aux2 = descritor.topo;
					descritor.topo = aux2->prox;
					free(aux2);
					Dqtd++;
				}
			}i++;
		}
		printf("%d\n", Dqtd);
		cont = cont	+ 1;
	}

	return 0;
}