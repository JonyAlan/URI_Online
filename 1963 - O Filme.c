#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{
   double a,b;
   
   scanf("%lf %lf", &a,&b);
   
	printf("%.2f%%\n", ((b-a)/(a/100)));
   return 0;

}