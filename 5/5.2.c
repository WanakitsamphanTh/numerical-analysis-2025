#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 100

int main(int argc, char **argv){
    double error = 1e-8;
    int iter = 100000;
    double V[N][N] = {0};
    int i, j, k;

    FILE *output;

    for(i = 0; i < N - 1; i++)
        V[i][0] = V[0][i] = V[N - 1][i] = 0;

    for(i = 0; i < N - 1; i++){
        V[i][N - 1] = 100 * sin(M_PI * i / N);
    }

    output = fopen("./5.2.shusoku.tsv","w+");
    for(k = 0; k < iter; k++){
        for(i = 1; i < N - 1; i++)
            for(j = 1; j < N - 1; j++){
                V[i][j] = (V[i + 1][j] + V[i][j + 1] + V[i-1][j] + V[i][j-1]) / 4;
            }
        fprintf(output,"%d\t%.10f\n",k,V[N/2][N/2]);
    }

    fclose(output);

    output = fopen("./5.2.result.tsv","w+");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            fprintf(output, "%2d\t%2d\t%.10f\n",i,j,V[i][j]);
        }
    fclose(output);

    return 0;
}