#include <stdio.h>


int main(int argc, char **argv){

    const double x[10] = {0,1,2,3,4,5,6,7,8,9};
    const double y[10] = {1.01,3.97,5.77,7.90,9.47,11.7,14.0,15.5,17.0,19.2};
    const int n = 10;
    int i;
    double sxx = 0, sx = 0, sy = 0, sxy = 0;
    double a,b;

    for(i = 0; i < n; i++) sxx += x[i] * x[i];
    for(i = 0; i < n; i++) sx += x[i];
    for(i = 0; i < n; i++) sy += y[i];
    for(i = 0; i < n; i++) sxy += x[i] * y[i];

    a = (n * sxy - sx * sy) / (n * sxx - sx * sx);
    b = (sxx * sy - sx * sxy) / (n * sxx - sx * sx);

    for(i = 0; i < n; i++) printf("%f %f %f\n",x[i], y[i], a * x[i] + b);



    return 0;
}