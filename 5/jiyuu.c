#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(int argc, char **argv){
    int i;
    double x, y, theta, pi;
    srand((unsigned int)time(NULL));
    x = y = 0;

    FILE *f = fopen("jiyuu.tsv","w");

    for(i = 0; i < N; i++){
        theta = 2 * M_PI * rand() / RAND_MAX;

        x += cos(theta);
        y += sin(theta);
        fprintf(f,"%.10f\t%.10f\n",x,y);
    }

    fclose(f);

    return 0;
}