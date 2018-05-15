#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()

{
	
   int n, x,y;
   n=0;
   
while( scanf("%d %d",&x, &y) != EOF )
{	
	if(x==1)
		n= 360 - y;
	if(x==2)
		n= 360 - y - 31;
	if(x==3)
		n= 360 - y - 60 ;
	if(x==4)
		n= 360 - y - 91;
	if(x==5)
		n= 360 - y - 121;
	if(x==6)
		n= 360 - y - 152;
	if(x==7)
		n= 360 - y - 182;
	if(x==8)
		n= 360 - y - 213;
	if(x==9)
		n= 360 - y - 244;
	if(x==10)
		n= 360 - y - 274;
	if(x==11)
		n= 360 - y - 305;
	if(x==12)
		n= 360 - y - 335 ;
	
	if(n==0)
	printf("E natal!\n");
   
   if(n==1)
	printf("E vespera de natal!\n");
	
	if(n > 1)
	printf("Faltam %d dias para o natal!\n", n);
	
	if(n < 0)
	printf("Ja passou!\n");
		
}
    return 0;

}