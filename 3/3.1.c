#include <stdio.h>
#include <math.h>

double sin_lagrange(double x,int n, const double *xs, const double *ys){             // n = 1,2,3
    double y = 0;
    double n_i;
    int i,j;

    for(i = 0; i < n + 1; i++){
        n_i = 1;
        for(j = 0; j < n + 1; j++){
            if(j == i) continue;
            n_i *= (x - xs[j]) / (xs[i] - xs[j]);
        }
        y += ys[i] * n_i;
    }
    return y;
}

int main(int argc, char **argv){

    const double ref_xs[4] = {60,65,70,75};
    const double ref_ys[4] = {0.866025,0.906308,0.939693,0.965926};

    int x = 63;
    double ys[4];
    double err[3];
    int i;
    
    ys[0] = sin(63 * M_PI / 180);

    for(i = 1; i < 4; i++){
        ys[i] = sin_lagrange(x,i,ref_xs,ref_ys);
        err[i - 1] = ys[0] - ys[i];
    }
    
    printf("*** sin 63 ***\n");
    printf("true\t\t1st\t\t2nd\t\t3rd\n");
    printf("%.6f\t%.6f\t%.6f\t%.6f\n",ys[0],ys[1],ys[2],ys[3]);
    printf("*** error ***\n");
    printf("1st\t\t2nd\t\t3rd\n");
    printf("%.6f\t%.6f\t%.6f\n",err[0],err[1],err[2]);

    return 0;
}