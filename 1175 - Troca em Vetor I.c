#include<stdio.h>

int main()

{
	int tro[20], i=0, x;


	while( i < 20)
	{scanf("%i", & tro[i]);
	i ++;
	}
	i = 19;
	x = 0;
	
	while(i >= 0)
	{printf("N[%i] = %i\n", x, tro[i]);
	i = i - 1;
	x ++;
	}



return 0;
}