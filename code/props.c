#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 1024;

// calculates a.mod(b)
int mod(int a, int b)
{
	int t = a % b;

	if (t>=0)
		return t;
	else
		return b+t;
}

double parseval(const char* sig, const char* ft)
{
	FILE *f1 = fopen(sig, "r");
	FILE *f2 = fopen(ft, "r");
	double lhs = 0, rhs = 0, g, G;
	int i;

	for(i=0; i<size; i++)
	{
		fscanf(f1,"%lf", &g);
		fscanf(f2,"%lf", &G);
		lhs = lhs + g*g;
		rhs = rhs + G*G;
	}

	rhs = rhs / size;
	return lhs - rhs;
}

//function to circularly right shift a signal(in time domain) and write it to a file 
void rshift(const char* sig1, const char* shift, int n)
{
	FILE *in = fopen(sig1, "r");
	FILE *out = fopen(shift, "w");
	int i;
	double sig[size], sig_shift[size];

	for(i=0; i<size; i++)
		fscanf(in,"%lf",sig + i);

	for(i=0; i<size; i++)
	{
		sig_shift[i] = sig[mod(i-n, size)];
		fprintf(out, "%lf\n", sig_shift[i]);
	}

	return;
}

int main(int argc, char const *argv[])
{
	time_t t;
	srand((unsigned) time(&t));
	int shift = rand() % 1000000;
	printf("In parseval's theorem, LHS - RHS = %lf\n", parseval(argv[1],argv[2]));
	rshift(argv[1],argv[3], shift);
	return 0;
}