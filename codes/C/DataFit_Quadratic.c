#include <stdio.h>

int main() {
    int n = 5;
    float x[] = { -2, -1, 0, 1, 2 };
    float y[] = { 1, 0, 1, 4, 9 };

    float Sx = 0, Sx2 = 0, Sx3 = 0, Sx4 = 0;
    float Sy = 0, Sxy = 0, Sx2y = 0;


    for (int i = 0; i < n; i++) {
        float xi = x[i];
        float yi = y[i];

        Sx   += xi;
        Sx2  += xi * xi;
        Sx3  += xi * xi * xi;
        Sx4  += xi * xi * xi * xi;

        Sy   += yi;
        Sxy  += xi * yi;
        Sx2y += xi * xi * yi;
    }


    float D  = n*(Sx2*Sx4 - Sx3*Sx3)
             - Sx*(Sx*Sx4 - Sx2*Sx3)
             + Sx2*(Sx*Sx3 - Sx2*Sx2);

    float Da = Sy*(Sx2*Sx4 - Sx3*Sx3)
             - Sx*(Sxy*Sx4 - Sx3*Sx2y)
             + Sx2*(Sxy*Sx3 - Sx2*Sx2y);

    float Db = n*(Sxy*Sx4 - Sx3*Sx2y)
             - Sy*(Sx*Sx4 - Sx2*Sx3)
             + Sx2*(Sx*Sx2y - Sx2*Sxy);

    float Dc = n*(Sx2*Sx2y - Sx3*Sxy)
             - Sx*(Sx*Sx2y - Sx2*Sxy)
             + Sy*(Sx*Sx3 - Sx2*Sx2);

    float a = Da / D;
    float b = Db / D;
    float c = Dc / D;

    printf("Quadratic fit:\n");
    printf("y = %.2fx^2 + %.2fx + %.2f\n", a, b, c);

    return 0;
}
