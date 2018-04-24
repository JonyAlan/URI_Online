#include<stdio.h>

int main()


{
int n, a, b, cont = 1;

scanf("%i", &n);

a = 0;
b = 1;

printf("%i", a);
printf(" %i", b);
n = n-2;

while (cont <= n) 
{
a = a + b;
b = a + b;

printf(" %i ", a);
cont  = cont + 1;

if (cont <= n) 
printf("%i", b);

cont = cont +1 ;


}

printf("\n");


return 0;
}