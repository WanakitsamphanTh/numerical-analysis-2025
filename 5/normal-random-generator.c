#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 20000

double box_muller(double mu, double sigma);
double clt(double mu, double sigma);

int main(int argc, char** argv){
    double mu = 0.5, sigma = 0.1;
    srand((unsigned int)time(NULL));
    box_muller(mu, sigma);
    clt(mu, sigma)
    return 0;
}

double box_muller(double mu, double sigma){
    double z1, z2, u1, u2, x, y;
    FILE *f = fopen("box-muller.tsv");

    fclose(f);
    return 0;
}
double clt(double mu, double sigma){
    double x, y;
    double r[12];
    int i;

    FILE *f = fopen("clt.tsv");

    for(i = 0; i < 12; i++) r[i] = (double)rand() / RAND_MAX;

    fclose(f);
    return 0;
}