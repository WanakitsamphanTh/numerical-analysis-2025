#include <stdio.h>
#include <math.h>
#define N 10

double f(double x, double y);
double Y(double x);                 // solution for dy/dx = f(x,y)
double euler(double x, double y, double a, double b);
double runge(double x, double y, double a, double b);

int main(int argc, char** argv){
    double x0 = 0, y0 = 1;
    double a = 0, b = 1;
    euler(x0,y0,a,b);
    runge(x0,y0,a,b);
}

double f(double x, double y){ return x + y; }
double Y(double x){ return 2 * exp(x) - x - 1; }

double euler( double x, double y, double a, double b){
    int i;
    double h = (b - a) / N;
    FILE* output = fopen("./euler.dat","w+");
    for(i = 0; i < N; i++){
        y = y + h * f(x,y);
        x = x + h;
        fprintf(output,"%.10f\t%.10f\t%.10f\t%.10f\n",x,y,Y(x),fabs(Y(x) - y));
    }
    fclose(output);
}
double runge(double x, double y, double a, double b){
    int i;
    double h = (b - a) / N;
    double k1, k2, k3, k4;
    FILE* output = fopen("./runge.dat","w+");
    for(i = 0; i < N; i++){
        k1 = h * f(x,y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
        fprintf(output, "%.10f\t%.10f\t%.10f\t%.10f\n",x,y,Y(x),fabs(Y(x) - y));
    }
    fclose(output);
}