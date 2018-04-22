#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()

{
int ingre[20010];
int t;

int m=0, n=0, cont,p =0, cont2,r=0;

while(scanf("%d %d", &n, &m))
{
	if((m== 0)&&(n==0))
		break;

for(cont=0;cont < m;cont ++)		
{
	scanf("%d", &ingre[cont]);
}


for (cont=0;cont<m;cont++)
{	t = ingre[cont];
		cont2 = cont;
		p = 0;
	while(cont2 < m )
	{if(t == ingre[cont2+1] &&  t != 0)
		{ingre[cont] = 0;
		ingre[cont2 + 1] = 0;
		if(p==0)
		r ++;
		p = 1;
		}
			
		cont2 ++;
			}		}
		

	printf("%d\n", r);
	r = 0;
	
}	
 return 0;
   
  
}