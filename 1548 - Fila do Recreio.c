#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
int num, alunos, cont, cont2,cont3, x, aux, n, antes[1001], depois[1001];
char troca;

	scanf("%d", &num);

	for(cont = 0; cont < num; cont++)
	{	n=0;
		scanf("%d", &alunos);

		for(cont2 =0; cont2 < alunos; cont2++)
		{	scanf("%d", &antes[cont2]);
			depois[cont2] = antes[cont2];
		}

		do
		{ 	troca = 0;
			x = 0;
			while (x < alunos - 1)
			{	if (depois[x] < depois[x + 1])
				{aux = depois[x];
				depois[x] = depois[x + 1];
				depois[x + 1] = aux;
				troca = 1;
				}
				x++;
			}
		} while(troca == 1);

			for(cont3 =0; cont3 < alunos; cont3++)
			if (antes[cont3] == depois[cont3])
				n++;

			printf("%d\n", n);
	}

	return 0;
}