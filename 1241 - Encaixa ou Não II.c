#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()

{
 char a[1020], b[1020], comp[10020];
 int cont, ent =0, cont2, z;
 int tamaa, tamab,tamac;
   scanf("%d", &cont);
   
   while( cont > 0)
   {cont = cont -1;

	for(z = 0; z < 1020; z++)
		comp[z] = '\0';
	
	ent = 0;
	  scanf("%s %s", a, b);
		
		tamaa = strlen(a);
		tamab = strlen(b);
		tamac = tamaa - tamab;
	
	if(tamac == 0)
	{if(strcmp(a,b)== 0)
		printf("encaixa\n");
		else
		printf("nao encaixa\n");
	}
	
	else
	{for(cont2 = tamac; cont2 < tamaa; cont2 ++)
	{	
		comp[ent] = a[cont2];
		ent ++;
	}
		ent = 0;
	if(strcmp(comp,b)== 0)
		printf("encaixa\n");
	else
		printf("nao encaixa\n");
	
		
   }}
   
   return 0;

}