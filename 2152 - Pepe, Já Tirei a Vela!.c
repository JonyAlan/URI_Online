#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{
   int a,b,c, cont;
   
  scanf("%d", &cont);
  while(cont > 0)
  {
   scanf("%d %d %d", &a,&b,&c);
   
   if(c==1)
	printf("%02d:%02d - A porta abriu!\n", a, b);

	else 
	printf("%02d:%02d - A porta fechou!\n", a, b);
		cont = cont -1;
  
  }
   return 0;

}