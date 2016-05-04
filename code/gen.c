#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "plot.c"

// Mathematcal Constants
const double pi = 3.14159265359;

// Limiets for generating random A and w
const int lim = 1000;
const int lim2 = 50;

double max(double a,double b){
	return (a>b)?a:b;
}

double freq(char* f, double R){
	int count = 0;

	FILE *fp = fopen(f,"r");

	double prev, y;
	int i;
	
	fscanf(fp,"%lf",&prev);
	for (i=1 ; i < size; i++){
		fscanf(fp,"%lf",&y);
		if (prev*y < 0 || y == 0)
			count++;
		prev = y;
	}

	// printf("count:%d\n",count);
	double x = (size-1)*(2*pi/R);
	return (count/2.0)/x;
}

void writeSample(char *f, int A, int w, int R){
	FILE *fp = fopen(f,"w");

	double T = 2*pi/R;

	int i;
	for(i=0; i<size; i++){
		double y = A*sin(w*T*i);
		fprintf(fp, "%lf\n",y);
		// double x = i*T;
	}

	fclose(fp);
}

double error(int A, int w, int R){
	writeSample("temp", A,w,R);
	double f = freq("temp", R);
	remove("temp");

	return (w/6.283)-f;
}

void rFile(int A,int w, int s, int len){
	FILE *fp = fopen("./data/variation.dat","w");
	double curr;

	int i;	
	for(i=s;i<s+len;i+=20){
		curr = error(A,w,i);
		fprintf(fp, "%d %lf\n",i,curr);
	}
	
	fclose(fp);
	plot("./data/variation.dat", 2, "Variation of Error with Sampling Rate(2pi*R)");
}

int main(){
	int A1, A2, w0, w1;
	int R;

	time_t t;
	srand((unsigned) time(&t));

	// A1 = rand() % lim + 1;
	// A2 = rand() % lim + 1;
	// w0 = rand() % lim2 + 1;
	// w1 = rand() % lim2 + 1;
	A1 = 150;
	A2 = 250;
	w0 = 25;
	w1 = 50;
	R = 250;

	writeSample("./data/sig1.dat", A1, w0, R);
	plot("./data/sig1.dat",1,"Signal 1");

	writeSample("./data/sig2.dat", A2, w1, R);
	plot("./data/sig2.dat",1, "Signal 2");

	printf("Actual f for Signal 1: %lf\n",w0/6.283);
	printf("Observed f for Signal 1: %lf\n", freq("./data/sig1.dat",R));

	printf("\nActual f for Signal 2: %lf\n",w1/6.283);
	printf("Observed f for Signal 2: %lf\n", freq("./data/sig2.dat",R));
	
	rFile(A1,w0,1000,3000);
	return 0;
}