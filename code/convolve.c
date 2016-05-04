#include "stdio.h"

const int size = 1024;

void convolve(const char* f1,const char* f2,const char* op)
{
	FILE *in1 = fopen(f1, "r");
	FILE *in2 = fopen(f2, "r");
	FILE *out = fopen(op, "w");

	int i,j;
	double s1[size], s2[size], conv[2*size]; 
	
	for(i=0; i<size; i++)
	{
		fscanf(in1,"%lf", s1 + i);
		fscanf(in2,"%lf", s2 + i);
	}

	for(i=0; i<2*size; i++)
	{
		conv[i] = 0;
	}

	for(i=0; i<size; i++)
	{
		for(j=0; j<=i; j++)
		{
			conv[i] = conv[i] + s1[j]*s2[i-j];
		}
	}

	for(i=size; i<2*size-1; i++)
	{
		for(j=i-size+1; j<size; j++)
		{
			conv[i] = conv[i] + s1[j]*s2[i-j];
		}
	}

	for(i=0; i<2*size; i++)
	{
		fprintf(out, "%lf\n", conv[i]);
	}
	return;
}

int main(int argc, char const *argv[])
{
	convolve(argv[1],argv[2],argv[3]);
	return 0;
}