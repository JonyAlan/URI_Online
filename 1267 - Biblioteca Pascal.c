#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()

{	int visit[501][501];
	int cont1,x, y,s,o, cont2, r;
	
	while (1)
	{	
		o = 0;
		
		scanf("%d %d", &cont1, &cont2);
		if(cont1 == 0 && cont2 ==0)
			break;
		
		for(x = 0; x < cont2; x ++)
		{for(y= 0; y < cont1; y ++)
			{scanf("%d",&visit[x][y]);
			}}
			
		for(y= 0; y < cont1; y ++)
		{	s =1;
			for(x = 0; x < cont2; x ++)
			{s = s * visit[x][y];
			}
			if(s == 1)
			o = 1;
		}
		if(o == 1)
		printf("yes\n");
		else
		printf("no\n");
	
	}
	return 0;
}
