#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{

   char fruta[101];
   int x;

   
   scanf("%d", &x);
   
   while(x >= 0)
   {
	gets(fruta);
	x = x-1;
   }
	printf("Ciencia da Computacao\n");
	
        return 0;

}