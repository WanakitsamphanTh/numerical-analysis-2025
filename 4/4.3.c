#include <stdio.h>
#include <math.h>

double f(double x, double y);
double Y(double x);                 // solution for dy/dx = f(x,y)
double euler(int N, double x, double y, double X);
double runge(int N, double x, double y, double X);

int main(int argc, char** argv){
    double x0 = 0, y0 = 1;
    double x = 1, y;
    int i, j, n;
    FILE* output_euler, *output_runge;

    output_euler = fopen("./4.3.euler.dat","w+");
    output_runge = fopen("./4.3.runge.dat","w+");
    for(i = 0; i <= 4; i++){
        for(j = 2; j <= 10; j++){
            n = j * pow(10,i);
            y = euler(n,x0,y0,x);
            fprintf(output_euler,"%.18f\t%.18f\t%.18f\t%.18f\n",1.0 / n, y,Y(x),fabs(Y(x) - y));
            y = runge(n,x0,y0,x);
            fprintf(output_runge,"%.18f\t%.18f\t%.18f\t%.18f\n",1.0 / n, y,Y(x),fabs(Y(x) - y));
        }
    }
    fclose(output_euler);
    fclose(output_runge);
}

double f(double x, double y){ return x + y; }
double Y(double x){ return 2 * exp(x) - x - 1; }
double euler(int N, double x, double y, double X){
    int i;
    double h = 1.0 / N;
    for(i = 0; i < N; i++){
        y = y + h * f(x,y);
        x = x + h;
    }
    return y;
}
double runge(int N, double x, double y, double X){
    int i;
    double h = 1.0 / N;
    double k1, k2, k3, k4;

    for(i = 0; i < N; i++){
        k1 = h * f(x,y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
    }

    return y;
}