#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()

{
int f1, f2,cont2,f, x;

scanf("%d", &cont2);
while(cont2 > 0)
{
	scanf("%d %d", &f1,&f2);
	
	if(f1 > f2)
	{while(f2!=0){
		x = f1 % f2;
		f1 = f2;
		f2 = x;
		f = f1;
	}}
		
	if(f1 < f2)
	{while(f1!=0){
		x = f2 % f1;
		f2 = f1;
		f1 = x;
		f =f2;
	}}
	
	if(f1 == f2)
	{printf("%d\n", f2);
	}
	else printf("%d\n", f);
	 cont2 = cont2 -1;		
		
}	
 return 0;
   
  
}