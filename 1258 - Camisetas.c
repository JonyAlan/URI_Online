#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct Aluno
{
char nome[200];
char cam[100];
char tam;
};

int compara( const void *, const void *);

int main()
{
	int n, i;
	int c;
	
	scanf("%d\n", &n);	
	
	while(n)
	{
		
	struct Aluno aluno[n];
		
		for(i = 0; i < n; i++){
			scanf("%[^\r\n]", aluno[i].nome);
			
			scanf("%s %c", &aluno[i].cam, &aluno[i].tam);
			while(getchar()!='\n');
			
		}
		
		qsort(aluno, n, sizeof(struct Aluno), compara);
		
		for(i = 0; i < n; i++)
			printf("%s %c %s\n", aluno[i].cam, aluno[i].tam, aluno[i].nome);
		
        scanf("%d\n", &n);
        if(n == 0) break;
        printf("\n");		
		
	}
	
	return 0;
}

int compara(const void *p1, const void *p2){
	struct Aluno *i = (struct Aluno *)p1, *j = (struct Aluno *)p2;
	if(strcmp(i->cam, j->cam) == 0)
		if(i->tam > j->tam)
			return -1;
		else if (i->tam < j->tam)
			return 1;
		else
			return strcmp(i->nome, j->nome);
   else 
	   return strcmp(i->cam, j->cam);
}