#include <stdio.h>
#include <math.h>

#define epsilon 1e-12

double f(double x){
    return x - cos(x);
}

double dif_f(double x){
    return 1 + sin(x);
}

int bisection(double a, double b, double* r){
    
    int n = 0;
    double c;

    while(fabs(a-b) > epsilon){
        c = (a + b) / 2;
        if(f(c) < 0) a = c;
        else b = c;
        r[n] = c;
        n++;
    }

    return n;
}

int newtonian(double x0, double* r){
    double d;
    double xk = x0;
    int n = 0;

    do {
        d  = - f(xk) / dif_f(xk);
        xk = xk + d;
        r[n] = xk;
        n++;
    } while(fabs(d) > epsilon);
    return n;
}

int main(int argc, char **argv){
    double bisection_r[50];
    double newtonian_r[50];

    int bisection_n = bisection(-1,10,bisection_r);
    int newtonian_n = newtonian(-1, newtonian_r);
    int i = 0;

    printf("n\tNibun (a=-1.0,b=10.0)\tNewton (x0 = -1.0)\n");
    while(i < bisection_n || i < newtonian_n){
        printf("%d\t",i+1);
        if(i < bisection_n) printf("%.8f",bisection_r[i]);
        else printf("\t");
        if(i < newtonian_n) printf("\t\t\t%.8f\n",newtonian_r[i]);
        else printf("\n");
        i++;
    }

    return 0;
}