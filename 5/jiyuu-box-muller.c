#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 2000

double box_muller_rand(double mu, double sigma, double* x, double *y);

int main(int argc, char **argv){
    int i;
    double x, y, dx, dy;
    srand((unsigned int)time(NULL));
    x = y = 0;

    FILE *f = fopen("jiyuu-box-muller.tsv","w");

    for(i = 0; i < N; i++){
        box_muller_rand(0, 0.01, &dx, &dy);
        x += dx;
        y += dy;
        fprintf(f,"%.10f\t%.10f\n",x,y);
    }

    fclose(f);

    return 0;
}

double box_muller_rand(double mu, double sigma, double* x, double *y){
    double u1, u2, z1, z2;
    u1 = (double)rand() / RAND_MAX;
    u2 = (double)rand() / RAND_MAX;
    z1 = sqrt(- 2 * log(u1)) * cos(2 * M_PI * u1);
    z2 = sqrt(- 2 * log(u2)) * sin(2 * M_PI * u2);
    *x = sigma * z1 + mu;
    *y = sigma * z2 + mu;
}