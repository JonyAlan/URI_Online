#include<stdio.h>

int main()

{
int i=1 ,j=7;

while(i <= 9)
{	printf("I=%i J=%i\n", i,j);
	printf("I=%i J=%i\n", i,j-1);
	printf("I=%i J=%i\n", i,j-2);
	
	i = i + 2;
	j = j + 2;
}




return 0;
}