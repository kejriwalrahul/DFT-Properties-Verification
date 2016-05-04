#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NUM_POINTS 5
#define NUM_COMMANDS 2

// Size for sampling
const int size = 1024;

void plot(char *f, int op, char *title)
{
    // Plot
    char s[100] = "plot '";
    strcat(s,f);
    if(op == 1)
    	strcat(s,"' with impulses lw 0.1");
    else if(op == 2)
    	strcat(s,"' with impulses lw 2");
    else
    	strcat(s,"'");

    // Title
    char temp[1000];
    strcpy(temp,"set title \"");
    strcat(temp,title);
    strcat(temp,"\"");
    char * commandsForGnuplot[] = {temp,s};
    
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    
    int i;
    for (i=0; i < NUM_COMMANDS; i++){
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
    pclose(gnuplotPipe);
}