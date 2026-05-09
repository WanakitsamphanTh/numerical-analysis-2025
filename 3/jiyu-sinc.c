#include <math.h>
#include <stdio.h>
#define N 11
#define L 5.0

double f(double);
void gauss(int n, double *_A, double* x, double* y);
double cubic_spline(double x, const double*,const double*);
double lagrange(double x, const double *xs, const double *ys);

int main(int argc, char** argv){
    double ref_xs[N];
    double ref_ys[N];
    double x, y, sp_y, lg_y;
    int i;

    FILE* ref_data = fopen("ref-data.dat","w+");
    FILE* saved_data = fopen("saveed-data.dat","w+");

    //initialize ref_xs, ref_ys in [-1,1]
    for(i = 0; i < N; i++){
        ref_xs[i] = -L + i * (2 * L / (N-1));
        ref_ys[i] = f(ref_xs[i]);
        fprintf(ref_data,"%.8f\t%.8f\n",ref_xs[i],ref_ys[i]);
    }
    fclose(ref_data);
    
    //printf("x\tsinc\tspline\tlagrange\n");
    for(i = 0; i <= 100; i++){
        x = -L + i * (2 * L / 100);
        y = f(x);
        sp_y = cubic_spline(x, ref_xs, ref_ys);
        lg_y = lagrange(x,ref_xs,ref_ys);
        fprintf(saved_data,"%.8f\t%.8f\t%.8f\t%.8f\n",x,y,sp_y,lg_y); //x tsinc spline lagrange
    }

    fclose(saved_data);

    return 0;
}

double f(double x){
    //return 1 / (1 + 25 * pow(x,2));
    return  1 / sqrt(2 * M_PI) * exp(- pow(x,2) / 2);
}

void gauss(int n, double *_A, double* x, double* y){
    double A[N][N];
    int i, j, k;
    double c;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            A[i][j] = *(_A + (n * i) + j);
            //printf("%.2f\t",A[i][j]);
        }
        x[i] = y[i];
       // printf("|\t%.2f\n",x[i]);
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

double cubic_spline(double x, const double* xs,const double* ys){
    int i, j;
    double h[N-1], v[N-2], _u[N-2],u[N],ah[N-2][N-2];
    double a[N-1], b[N-1], c[N-1], d[N-1], s;
    //find hi
    for(i = 0; i < N - 1; i++) h[i] = xs[i + 1] - xs[i];
    //find vi
    for(i = 0; i < N - 2; i++) v[i] = 6 * ((ys[i+2] - ys[i+1]) / h[i+1] - (ys[i+1] - ys[i]) / h[i]);

    //find ah
    for(i = 0; i < N - 2; i++) 
        for(j = 0; j < N - 2; j++) 
            ah[i][j] = 0;
    for(i = 0; i < N - 2; i++) ah[i][i] = 2 * (h[i] + h[i + 1]);
    for(i = 0; i < N - 2; i++) {
        if(i + 1 < N-2) ah[i][i+1] = h[i + 1];
        if(i + 1 < N-2) ah[i+1][i] = h[i + 1];
    }

    gauss(N-2,ah,_u,v);

    u[0] = 0;
    for(i = 0; i < N - 2; i++)
        u[i + 1] = _u[i];

    //for(i = 0; i < N; i++) printf("%.2f ",u[i]);
    //printf("\n");

    for(i = 0; i < N - 1; i++) {
        a[i] = (u[i+1] - u[i]) / (6 * (xs[i+1] - xs[i]));
        b[i] = u[i] / 2;
        c[i] = (ys[i + 1] - ys[i]) / (xs[i + 1] - xs[i]) - (xs[i + 1] - xs[i]) * (2 * u[i] + u[i + 1]) / 6;
        d[i] = ys[i];
    }

    for(i = 1; i < N; i++) 
        if(x < xs[i]) {
            j = i - 1;
            break;
        }
        

    //for(i = 0; i < N - 1; i++) printf("%f\t%f\t%f\t%f\n",a[i],b[i],c[i],d[i]);


    s = a[j] * pow((x - xs[j]),3) + b[j] * pow((x - xs[j]),2) + c[j] * (x - xs[j]) + d[j];

    return s;
}

double lagrange(double x, const double *xs, const double *ys){ 
    double y = 0;
    double n_i;
    int i,j;

    for(i = 0; i < N; i++){
        n_i = 1;
        for(j = 0; j < N; j++){
            if(j == i) continue;
            n_i *= (x - xs[j]) / (xs[i] - xs[j]);
        }
        y += ys[i] * n_i;
    }
    return y;
}
