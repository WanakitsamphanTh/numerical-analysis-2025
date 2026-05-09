#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gaussian(double a[3][3], double b[3]);
void jacobian(double a[3][3], double b[3]);

int main(int argc, char** argv){
    double a1[3][3] = {{4,1,1},{2,6,1},{1,2,5}}, b1[3] = {4, -8, 7};
    double a2[3][3] = {{4,2,-1},{1,-3,1},{3,4,2}}, b2[3] = {3, 8, 8};
    double a3[3][3] = {{0,1,2},{1,0,3},{3,1,0}}, b3[3] = {2, 2, -3};

    printf("1)\n");
    gaussian(a1,b1);
    jacobian(a1,b1);
    printf("2)\n");
    gaussian(a2,b2);
    jacobian(a2,b2);
    printf("3)\n");
    gaussian(a3,b3);
    jacobian(a3,b3);

    return 0
}

void gaussian(double a[3][3], double b[3]){
    double A[3][3];
    double x[3], c;
    int i, j, k;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
            A[i][j] = a[i][j];
        x[i] = b[i];
    }
    
    //forward
    for(i = 0; i < 3; i++){
        if(A[i][i] == 0){
            printf("A diagonal element is 0; Cannot calculate\n");
            return;
        }
        for(j = i + 1; j < 3; j++){
            c = A[j][i] / A[i][i];
            for(k = i; k < 3; k++){
                A[j][k] = A[j][k] - c * A[i][k];
            }
            x[j] = x[j] - c * x[i];
        }
    }

    //backward
    for(i = 2; i >= 0; i--){
        for(j = i - 1; j >= 0; j--){
            c = A[j][i] / A[i][i];
            A[j][i] = A[j][i] - c * A[i][i];
            x[j] = x[j] - c * x[i];
        }
        x[i] = x[i] / A[i][i];
    }

    printf("Gaussian:\tx1 = %.0f\tx2 = %.0f\tx3 = %.0f\n", x[0], x[1], x[2]);
}


void jacobian(double a[3][3], double b[3]){
    double x_n[3], x[3];
    double err = 1e-8;
    int i, j;

    for(i = 0; i < 3; i++) 
        // A(i,i) != 0
        if(a[i][i] == 0) {
            printf("A diagonal element is 0; Cannot calculate\n");
            return;
        }

    for(j = 0; j < 3; j++)      // initialize x0 with random values
        x_n[j] = ((double) rand()) / RAND_MAX;
    
    while(!(fabs(x_n[0] - x[0]) < err && fabs(x_n[1] - x[1]) < err && fabs(x_n[2] - x[2]) < err)){
        x[0] = x_n[0];
        x[1] = x_n[1];
        x[2] = x_n[2];

        x_n[0] = (b[0] - (a[0][1] * x[1] + a[0][2] * x[2])) / a[0][0]; 
        x_n[1] = (b[1] - (a[1][0] * x[0] + a[1][2] * x[2])) / a[1][1]; 
        x_n[2] = (b[2] - (a[2][0] * x[0] + a[0][1] * x[1])) / a[2][2]; 
    }

    printf("Jacobian:\tx1 = %.0f\tx2 = %.0f\tx3 = %.0f\n", x_n[0], x_n[1], x_n[2]);

}