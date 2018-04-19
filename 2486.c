#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{

   char fruta[120];
   int x,x2, total, f;
   total = 0;
   
   while(scanf("%d", &x)>0)
   {
	if(x <=0)
		break;
	x2 = x;
	   while(x2 > 0)
   { 
		scanf("%d %[^\n]", &f,fruta);
		
		if(strcmp(fruta,"suco de laranja")==0)
			total = total + f * 120;
		if(strcmp(fruta,"morango fresco")==0)
			total = total + f * 85;
		if(strcmp(fruta,"mamao")==0)
			total =  total + (f * 85);
		if(strcmp(fruta,"goiaba vermelha")==0)
			total =  total + (f * 70);
		if(strcmp(fruta,"manga")==0)
			total =  total + (f * 56);
		if(strcmp(fruta,"laranja")==0)
			total =  total + (f * 50);
		if(strcmp(fruta,"brocolis")==0)
			total =  total + (f * 34);
		x2 = x2-1;
		}
		if(total > 130)
			printf("Menos %d mg\n", total - 130);
		
		else if(total < 110)
			printf("Mais %d mg\n",110 - total);
		
		else 
			printf("%d mg\n", total);
			
		total = 0;
		x = x-1;
		
   }

        return 0;

}