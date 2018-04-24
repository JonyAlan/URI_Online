#include<stdio.h>


int main()

{
int cont = 0, cont2 = 0, i = 0;

int matriz[10] = {0};

for(cont = 0 ; cont < 10; cont++)
{	scanf("%i", &matriz[i]);
	i ++;
}
i = 0 ;
while(cont2 < 10 )
{

if(matriz[i] > 0)
	printf("X[%i] = %i\n", cont2, matriz[i]);
else
	printf("X[%i] = 1\n", cont2);
i ++;
cont2 ++;
}


return 0;


}