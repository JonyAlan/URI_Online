#include<stdio.h>
#include<stdlib.h>


int comp ( const void *, const void * ) ;
int comp2 ( const void *, const void * ) ;

int main()

{
int cont, n, cont2,cont3;
int vet[1000000];

scanf("%d", &cont2);

	for(cont = 0; cont < cont2; cont ++)
		scanf("%d", &vet[cont]);
	
	qsort(vet,cont, sizeof(int), comp);	
		for(cont = 0; cont < cont2; cont ++)
		{	n = vet[cont];
			if(n % 2 == 0)
			printf("%d\n", vet[cont]);
		}
	qsort(vet,cont, sizeof(int), comp2);		
		for(cont = 0; cont < cont2; cont ++)
		{	n = vet[cont];
			if(n % 2 == 1)
			printf("%d\n", vet[cont]);
		}
		
		
return 0;
}
		
int comp ( const void *p1, const void *p2 )
{ int *i = (int *)p1, *j = (int *)p2;
if( *i < *j )
return -1;
else
if( *i == *j )
return 0;
else
return 1;
}

int comp2 ( const void *p1, const void *p2 )
{ int *i = (int *)p1, *j = (int *)p2;
if( *i < *j )
return 1;
else
if( *i == *j )
return 0;
else
return -1;
}