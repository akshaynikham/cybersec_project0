#include <stdio.h>
#include <math.h>

int main() {
    FILE *fp = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/raw_sensor_data.csv", "r");
    if (!fp) return 1;

    char line[100];
    double x, y;
    double sumX=0, sumY=0, sumXY=0, sumX2=0;
    int n = 0;

    fgets(line, sizeof(line), fp); 

    while (fscanf(fp, "%lf,%lf", &x, &y) == 2) {

        if (y <= 0) continue;

        double Y = log(y);

        sumX  += x;
        sumY  += Y;
        sumXY += x * Y;
        sumX2 += x * x;
        n++;
    }
    fclose(fp);

    double B = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double C = (sumY - B * sumX) / n;

    double A = exp(C);

    printf("Exponential fit:\n");
    printf("A = %f\nB = %f\n", A, B);

    return 0;
}
