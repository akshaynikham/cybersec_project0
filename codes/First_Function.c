#include <stdio.h>
#include <math.h>

int main() {
    double x,y ;
    printf("Enter x: ");
    scanf("%lf", &x);

    y = sqrt(x) + x*x;

    printf("Results = %lf\n", y);
    return 0;

}

