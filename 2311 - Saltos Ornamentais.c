#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{
  double vet[7];
  double min, max;
  double total,per;
  int cont, cont2;
  cont2 = 0;
  char nome[20];
  
   scanf("%d",&cont2);
   
   while(cont2 > 0)
   {
	   
	   scanf("%s", nome);
	   scanf("%lf",&per);
	   
	   scanf("%lf",&vet[0]);
		total = vet[0];
		min = vet[0];
		max = vet[0];
		
	   for(cont = 1; cont < 7; cont ++)
	   {	
		 
		 scanf("%lf",&vet[cont]);
		 total = total + vet[cont];
		if(min > vet[cont])
			min = vet[cont];
		if(max < vet[cont])
			max = vet[cont];
		 
	   }
	   printf("%s ", nome);
	   total = per * (total - (min + max));
	   printf("%.2lf\n",total);
	   total = 0;
	   
	   cont2 = cont2 -1;
		
   }
   
   return 0;

}