#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int n;
    double x, y, err, expected_err;
    double pi;
    int count = 0;
    int k = 1, l = 1;

    FILE* f = fopen("kosatu.tsv","w");

    //printf("n\t\tpi\t\t|pi - M_PI|\n");
    for(n = 1; n <= 1e9; n += 1) {
        x = ((double) rand()) / RAND_MAX;
        y = ((double) rand()) / RAND_MAX;
        if((x * x + y * y) <= 1) count += 1;
        pi = 4 * ((double) count) / n;
        if(n % k == 0){
            if(l * k == n){
                err = fabs(pi - M_PI);
                expected_err = 3 * sqrt(M_PI * (4 - M_PI) / n);
                fprintf(f,"%d\t\t%.10f\t\t%.10f\t\t%.10f\t\t%d\n", n, pi, fabs(pi - M_PI), expected_err, err < expected_err);
                l += 1;
            }
            if(l == 10){
                l = 1;
                k *= 10;
            }
        }
    }
    
    fclose(f);

    return 0;
}