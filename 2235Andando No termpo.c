#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{
  
  int a,b,c;

	   scanf("%d %d %d", &a, &b, &c);
	   
	   if((a==b)||(b==c)||(a==c)||((a+b)==(c))||((c+a)==(b))||(b+c)==a)
		   printf("S\n");
	   else
		printf("N\n");
	
   return 0;

}