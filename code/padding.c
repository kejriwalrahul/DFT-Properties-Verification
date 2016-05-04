#include "stdio.h"

const int size = 1024;

void pad(const char* sig1, const char* sig2)
{
	FILE *f1 = fopen(sig1, "r");
	FILE *f2 = fopen(sig2, "r");
	FILE *fs1 = fopen("data/sig1_2048.dat", "w");
	FILE *fs2 = fopen("data/sig1_4096.dat", "w");
	FILE *fs3 = fopen("data/sig2_2048.dat", "w");
	FILE *fs4 = fopen("data/sig2_4096.dat", "w");

	int i;
	double t1, t2;

	for (i=0; i<size; i++)
	{
		fscanf(f1,"%lf",&t1);
		fscanf(f2,"%lf",&t2);
		fprintf(fs1, "%lf\n", t1);
		fprintf(fs2, "%lf\n", t1);
		fprintf(fs3, "%lf\n", t2);
		fprintf(fs4, "%lf\n", t2);
	}

	for(i=0; i<size; i++)
	{
		fprintf(fs1, "%lf\n", 0.0);
		fprintf(fs2, "%lf\n", 0.0);
		fprintf(fs3, "%lf\n", 0.0);
		fprintf(fs4, "%lf\n", 0.0);
	}

	for(i=0; i<2*size; i++)
	{
		fprintf(fs2, "%lf\n", 0.0);
		fprintf(fs4, "%lf\n", 0.0);
	}
	return;
}

int main(int argc, char const *argv[])
{
	pad(argv[1], argv[2]);
	return 0;
}