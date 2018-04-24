#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
int x,n,m,soman,somam;

while(1)
{	scanf("%d", &x);
	somam  = 0;
	soman = 0;
if(x == 0)
break;
	while(x > 0)
	{
		scanf("%d %d", &n, &m);
			if(n > m)
				soman ++;
			if(m > n)
				somam ++;
     x = x-1;			
	}
	 			
	printf("%d %d\n", soman, somam);
	
}

return 0;
}