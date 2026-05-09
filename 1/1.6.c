//1.6.c
#include <stdio.h>
long double lfabs(long double x){
    if(x < 0) return -x;
    else return x;
}
int main(int argc, char** argv){
    float x32; double x64; long double x128;
    long double err32, err64; 
    for(int n = 1; n <= 10000; n++){
        x128 = 1/ (long double)n;
        x64 = 1/ (double)n;
        x32 = 1/ (float)n;
        err32 = x128 - (long double) x32;
        err64 = x128 - (long double) x64;
        if(n % 10 == 0) 
            printf("%d\t%.30Le\t%.30Le\n",n,lfabs(err32),lfabs(err64));
    }
    return 0;
}
