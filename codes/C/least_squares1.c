#include <stdio.h>

int main() {


    int n = 5;

    float x[5] = {1, 2, 3, 4, 5};
    float y[5] = {3, 5, 7, 8, 11};

  
    float sum_x = 0;
    float sum_y = 0;
    float sum_x2 = 0;
    float sum_xy = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }


    float m = (n * sum_xy - sum_x * sum_y) /
              (n * sum_x2 - sum_x * sum_x);


    float x_mean = sum_x / n;
    float y_mean = sum_y / n;
    float c = y_mean - m * x_mean;


    printf("Slope (m) = %f\n", m);
    printf("Intercept (c) = %f\n", c);

 
    FILE *fp = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/least_squares1.txt", "w");
    fprintf(fp, "x y y_fit\n");

    for (int i = 0; i < n; i++) {
        float y_fit = m * x[i] + c;
        fprintf(fp, "%f %f %f\n", x[i], y[i], y_fit);
    }

    fclose(fp);

    return 0;
}
