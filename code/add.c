#include <stdio.h>
#include "plot.c"

void add(char *f1, char *f2, char *op){
	FILE *in1 = fopen(f1, "r");
	FILE *in2 = fopen(f2, "r");
	FILE *out = fopen(op, "w");

	int i;
	double u,v; 
	for(i=0; i<size; i++){
		fscanf(in1,"%lf", &u);
		fscanf(in2,"%lf", &v);
		fprintf(out, "%lf\n", u+v);
	}
}

int main(int argc, char* argv[]){

	add(argv[1], argv[2], argv[3]);
	return 0;
}