//1.5.c
#include <stdio.h>

long double lfabs(long double x){
    if(x < 0) return -x;
    else return x;
}

int main(int argc, char** argv){
    float x32;
    double x64;
    long double x128 = 0;
    long double err32;
    long double err64;
    int i;
    
    for(i = 1; i <= 10000; i++){
        x128 += 0.1;
        x64 += 0.1;
        x32 += 0.1;
        err32 = x128 - (long double) x32;
        err64 = x128 - (long double) x64;
        if(i % 10 == 0) 
            printf("%d\t%.30Le\t%.30Le\n",i,lfabs(err32),lfabs(err64));
    }

    return 0;
}