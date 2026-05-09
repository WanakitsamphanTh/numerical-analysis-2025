#include <stdio.h>
#include <math.h>

#define epsilon 1e-12

double f(double x){
    return x - cos(x);
}

double dif_f(double x){
    return 1 + sin(x);
}

int newtonian(double x0){
    double d;
    double xk = x0;
    int n = 0;

    do {
        d  = - f(xk) / dif_f(xk);
        xk = xk + d;
        n++;
    } while(fabs(d) > epsilon);
    return n;
}

int main(int argc, char **argv){
    double x0;

    printf("x0\tn\n");
    for(x0 = -10; x0 <= 10; x0+=2){
        printf("%f\t%d\n",x0,newtonian(x0));
    }

    return 0;
}