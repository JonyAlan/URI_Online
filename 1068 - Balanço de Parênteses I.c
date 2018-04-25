#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define num long long int 

 
int main(void){
    num x, cont; 
    char entr[1001],*p;
 
    while(scanf("%s",entr)!=EOF){
        
        x = 0;
		cont = 0;
        
        p = &entr[0];
        while(*p != '\0'){
 
            if(*p == '(' ){
                cont = cont + 1;
            }
            if(*p == ')' && cont){
                cont = cont - 1;
            }else if(*p == ')' && !cont){
				x = x+1;
			}
            p++;
        }
        if(!cont && !x){
            printf("correct\n");       
        }
        else{
            printf("incorrect\n");
        }
             
    }
return 0;
}