#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int num, den; } TRac;

int mdc(int, int);
TRac SomaRac(TRac, TRac);
TRac SubtraiRac(TRac, TRac);
TRac MultiplicaRac(TRac, TRac);
TRac DivideRac(TRac, TRac);
TRac SimplificaRac(TRac);

int main()
{	TRac v1, v2, res;
	int cont;
	char ope[2];
	
	scanf("%d", &cont);
	while (cont > 0)
	{
		scanf("%d / %d %s %d / %d", &v1.num, &v1.den, &ope, &v2.num, &v2.den);
	
		
		if(strcmp(ope,"+")==0)
		{res = SomaRac(v1, v2);
		printf("%d/%d = ", res.num, res.den);
		}
		if(strcmp(ope,"-")==0)
		{res = SubtraiRac(v1, v2);
		printf("%d/%d = ", res.num, res.den);
		}
		if(strcmp(ope,"*")==0)
		{res = MultiplicaRac(v1, v2);
		printf("%d/%d = ", res.num, res.den);
		}
		if(strcmp(ope,"/")==0)
		{res = DivideRac(v1, v2);
		printf("%d/%d = ", res.num, res.den);
		}
		
		res = SimplificaRac(res);
		printf("%d/%d\n", res.num, res.den);
		
		cont = cont-1;
	}
	
	return 0;
}

int mdc(int m, int n)
{	if (m < 0) m = -m;
	if (n < 0) n = -n;

	if (m % n == 0)
		return n;
	else
		return mdc(n, m % n);
}

TRac SomaRac(TRac p1, TRac p2)
{	TRac result;

	result.num = p1.num * p2.den + p2.num * p1.den;
	result.den = p1.den * p2.den;
	
	return result;
}

TRac SubtraiRac(TRac p1, TRac p2)
{	TRac result;

	result.num = p1.num * p2.den - p2.num * p1.den;
	result.den = p1.den * p2.den;
	
	return result;
}

TRac MultiplicaRac(TRac p1, TRac p2)
{	TRac result;

	result.num = p1.num * p2.num;
	result.den = p1.den * p2.den;
	
	return result;
}

TRac DivideRac(TRac p1, TRac p2)
{	TRac result;

	result.num = p1.num * p2.den;
	result.den = p1.den * p2.num;
	
	return result;
}

TRac SimplificaRac(TRac p)
{	TRac result;
	int vm = mdc(p.num, p.den);

	result.num = p.num / vm;
	result.den = p.den / vm;
	
	return result;
}
