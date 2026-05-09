#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    float x32 = 0.1;
    double x64 = 0.1;

    printf("%.16e %.16e\n", x32, x64);

    return 0;
}