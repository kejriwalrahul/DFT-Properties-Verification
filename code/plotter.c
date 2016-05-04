#include <stdio.h>
#include "plot.c"

const int pi = 3.141593;

double peaks(char* f){
	FILE *fp = fopen(f,"r");
	double u, v, w;
	int max = 0;
	double maxVal = 0;

	fscanf(fp,"%lf %lf", &u, &v);
	int i = 2;
	
	if(u>v){
		printf("Peak at %d, amplitude is %lf\n", 0, u);
		// printf("Approx Freq: &lf\n", );
		max = 0;
		maxVal = u;
	}

	for(;i < size; i++){
		fscanf(fp,"%lf",&w);
		if(v>w && v>u){
			printf("Peak at %d, amplitude is %lf\n", i, v);
			// printf("Approx Freq: &lf\n", );
			if(v > maxVal && i < size/2)
				max = i;
		}
		u = v;
		v = w;
	}
	
	if(v>u){
		printf("Peak at %d, amplitude is %lf\n", size-1, v);
		// printf("Approx Freq: &lf\n", );
		// if(v > maxVal)
		// 	max = size-1;	
	}

	 return ((double)max)/(size*2)/2/pi;
}

int main(int argc, char* argv[]){

	if(argc < 4){
		printf("Error: Usage is ./plotter.o <filename> <plotOption> <plotTitle>\n");
	}
	else{
		plot(argv[1], atoi(argv[2]), argv[3]);
	}

	double freq = peaks(argv[1]);

	if(argc == 5){
		freq *= atoi(argv[4]);
		printf("Detected freq: %lf\n", freq);
	}

	return 0;
}