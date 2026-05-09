//1.4

#include <stdio.h>
#include <math.h>

long int fact(long int x){
    if(x == 0) return 1;
    else  return x * fact(x - 1);
}


int main(int argc, char** argv){
    double e = 0;
    long int i = 0;
    const double max_err = 0.0000000001;
    double err = 1;
    while(1) {
        e = e + (1 / (double) fact(i));
        err = M_E - e;
        printf("%ld %e\n",i,err);
        i++;
        if(fabs(err) <= max_err) break;
    }
}