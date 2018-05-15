#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{
  
  double a,d,b,gu,da;
  int l, cont2;
  
   scanf("%d",&cont2);
   
   while(cont2 > 0)
   {
	   scanf("%lf", &b);
	   scanf("%lf %lf %d",&a, &d, &l);
	   gu = ((a + d)/2);
	   if((l%2) == 0)
		   gu = gu +b;
	   scanf("%lf %lf %d",&a, &d, &l);
	   da = ((a + d)/2);
	   if((l%2) == 0)
		   da = da +b;
		if(gu < da)
			printf("Guarte\n");
		else if(gu > da)
			printf("Dabriel\n");
		else printf("Empate\n");
		
	   cont2 = cont2 -1;
		
   }
   
   return 0;

}