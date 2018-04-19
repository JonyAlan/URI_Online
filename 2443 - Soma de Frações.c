#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int num, den; } TRac;

int mdc(int, int);
TRac SomaRac(TRac, TRac);
TRac SimplificaRac(TRac);

int main()
{	TRac v1, v2, res;

		
		scanf("%d %d %d %d", &v1.num, &v1.den, &v2.num, &v2.den);
	
		res = SomaRac(v1, v2);
		
		res = SimplificaRac(res);
		printf("%d %d\n", res.num, res.den);
	
	
	return 0;
}

int mdc(int m, int n)
{	
if(m < 0) m = -m;
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


TRac SimplificaRac(TRac p)
{	TRac result;
	int vm = mdc(p.num, p.den);
	result.num = p.num / vm;
	result.den = p.den / vm;
	
	return result;
}
