#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int n;
    double x, y;
    double pi;
    int count = 0;
    int k = 1;

    //printf("n\t\tpi\t\t|pi - M_PI|\n");
    for(n = 1; n <= 1e9; n++) {
        x = ((double) rand()) / RAND_MAX;
        y = ((double) rand()) / RAND_MAX;
        if((x * x + y * y) <= 1) count += 1;
        pi = 4 * ((double) count) / n;
        if(n % k == 0) {
            //printf("%*d\t%.10f\t%10f\n", 10,n, pi, fabs(pi - M_PI));
            printf("%f\t\t%.10f\t\t%10f\n", 1.0*n, pi, fabs(pi - M_PI));
            k *= 10;
        }
    }

    return 0;
}