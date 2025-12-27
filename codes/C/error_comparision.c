#include <stdio.h>
#include <math.h>

int main() {
    double x = 100000;
    double a = sqrt(x*x + 1) - x;
    double b = 1 / (sqrt(x*x + 1) + x);

    printf("Direct formula = %lf\n", a);
    printf("Stable formula = %lf\n", b);

    return 0;
}
