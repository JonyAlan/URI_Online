#include <stdio.h>
#include <string.h>

int main(){
   char s[666];
   char o[1];
   int i, cont, tam;
   double soma, aux;
   fgets(s, 666, stdin);
   while ((s[0])!='*')
   {
      cont=0;
      tam=strlen(s);
      soma=0;
      aux=0;
      for(i=0;i<tam;i++){
         aux=0;
         soma=0;
         while(s[i]!='/' && i<(tam-1))
			 {
				if(s[i] == 'W')
				aux=1;
				
				if(s[i] == 'H')
				aux=0.5;
				
				if(s[i] == 'Q')
				aux=0.25;
		   
				if(s[i] == 'E')
				aux=0.125;
			     
				if(s[i]  =='S')
				aux=0.0625;
				  
				if(s[i] == 'T')
				aux=0.03125;
			  
				if(s[i] == 'X')
				aux=0.015625;
			   
			  
            
            soma=soma+aux;
            i++;
         }
         if (soma==1){
            cont++;   
         }
      }
      printf("%d\n", cont);
      cont=0;
      fgets(s, 666, stdin);
   }
   return 0;
}
