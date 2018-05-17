#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, r1, r2, x;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    x = (b*b) - 4*a*c;
	
    if(x > 0 && a != 0){
        x = sqrt(x);
        r1 = (-b+x)/(2*a);
        r2 = (-b-x)/(2*a);

        printf("R1 = %.5f\n", r1);
		printf("R2 = %.5f\n", r2);
       
    }
    else{
        printf("Impossivel calcular\n");
       
    }



    return 0;
}