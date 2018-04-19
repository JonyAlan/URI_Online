#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{
	
  long int x, y, z, f1;
  
  scanf("%ld %ld %ld", &x, &y, &z);
  

	if(x > y)
	{f1 = y;
	y = x;
	x = f1;}
	if(y > z)
	{f1 = z;
	z = y;
	y = f1;}
	if(x > y)
	{f1 = y;
	y = x;
	x = f1;}
	
	if ((x > (y-z)) && (x < (y+z)))
	{if ((y > (x-z)) && (y < (x+z)))
		{if ((z > (x-y)) && (z < (x+y)))
	
		{	
			
	 if((x==y)&&(y==z))
	{printf("Valido-Equilatero\n");
		if((x*x)+(y*y)==(z*z))
		printf("Retangulo: S\n");
		else 
		printf("Retangulo: N\n");
	}
    else if((x==y)||(x==z)||(y==z))
	{printf("Valido-Isoceles\n");
		if((x*x)+(y*y)==(z*z))
		printf("Retangulo: S\n");
		else 
		printf("Retangulo: N\n");
	}
	else if((x!=y)&&(x!=z)&&(y!=z))
	{printf("Valido-Escaleno\n");
		if((x*x)+(y*y)==(z*z))
		printf("Retangulo: S\n");
		else 
		printf("Retangulo: N\n");
		}}else
			printf("Invalido\n");
		}}

    return 0;

}