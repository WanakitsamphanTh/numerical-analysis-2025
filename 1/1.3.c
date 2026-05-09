//1.3.c
#include <stdio.h>

int main(int argc, char** argv){
    int x = 1;
    long int xl = 1;
    int n = 0;
    do {
        x *= 2;
        xl *= 2;
        n++;
        printf("%d\t%12d\t%12ld\n",n,x,xl);
    } while(x != 0);
    return 0;
}