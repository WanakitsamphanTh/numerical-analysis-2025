#include <stdio.h>
#include <math.h>

#define N 4

void gauss(size_t n, double _A[N][N], double x[N], double y[N]);
double spline(double x,int n, const double *xs, const double *ys);


int main(int argc, char** argv){
    const double ref_xs[4] = {60,65,70,75};
    const double ref_ys[4] = {0.866025,0.906308,0.939693,0.965926};

    double real = sin(63.0 / 180 * M_PI);
    double s = spline(63.0,4,ref_xs,ref_ys);

    printf("%f %f\n", real, s);

    return 0;
}

double spline(double x,int n, const double *xs, const double *ys){
    int i, j;
    double h[N-1], v[N-2], _u[N-2],u[N],ah[N-2][N-2];
    double a[N-1], b[N-1], c[N-1], d[N-1], s;

    //find hi
    for(i = 0; i < n - 1; i++) h[i] = xs[i + 1] - xs[i];
    //find vi
    for(i = 0; i < n - 2; i++) v[i] = 6 * ((ys[i] - ys[i+1]) / h[i] - (ys[i+1] - ys[i]) / h[i]);
    //find ah
    for(i = 0; i < n - 2; i++) 
        for(j = 0; j < n - 2; j++) 
            ah[i][j] = 0;
    for(i = 0; i < n - 2; i++)
        ah[i][i] = 2 * (h[i] + h[i + 1]);
    for(i = 0; i < n - 3; i++){
        ah[i][i + 1] = h[i];
        ah[i][i - 1] = h[i];
    }

    gauss(n-2,ah,_u,v);

    for(i = 0; i < n; i++) u[i] = 0.0;
    for(i = 0; i < n - 1; i++) u[i+1] = _u[i];
    for(i = 0; i < n - 1; i++) {
        a[i] = (u[i+1] - u[i]) / (6 * (xs[i+1] - xs[i]));
        b[i] = u[i] / 2;
        c[i] = (ys[i + 1] - ys[i]) / (xs[i + 1] - xs[i]) - (xs[i + 1] - xs[i]) / (2 * u[i] + u[i + 1]) / 6;
        d[i] = ys[i];
    }

    for(i = 0; i < n; i++) 
        if(x < xs[i]) {
            j = i;
            break;
        }
        

    for(i = 0; i < n - 1; i++) printf("%f\t%f\t%f\t%f\n",a[i],b[i],c[i],d[i]);


    s = a[j] * pow((x - xs[j]),3) + b[j] * pow((x - xs[j]),2) + c[j] * (x - xs[j]) + d[j];

    return s;
}

void gauss(size_t n, double _A[N][N], double x[N], double y[N]){
    double A[N][N];
    int i, j, k;
    double c;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            A[i][j] = _A[i][j];
            printf("%f\t",A[i][j]);
        }
        x[i] = y[i];
        printf("|\t%f\n",x[i]);
    }    

    //forward
    for(i = 0; i < n; i++){
        for(j = n-1; j > i; j--){
            c = A[j][i] / A[i][i];
            for(k = i; k < n; k++) A[j][k] = A[j][k] - c * A[i][k];
            x[j] = x[j] - c * x[i];
        }
    }

    //backward
    for(i = n - 1; i >= 0; i--){
        for(j = 0; j < i; j++){
            c = A[j][i] / A[i][i];
            A[j][i] = A[j][i] - c * A[i][i];
            x[j] = x[j] - c * x[i];
        }
        x[i] = x[i] / A[i][i];
        A[i][i] = 1;
    }
    
}
