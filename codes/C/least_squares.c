#include <stdio.h>

int main() {
    FILE *fp = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/raw_sensor_data.csv", "r");
    if (fp == NULL) { return 1; }

    char line[100];
    double x, y;
    double sumX=0, sumY=0, sumXY=0, sumX2=0;
    int n = 0;

    fgets(line, sizeof(line), fp);

    while (fscanf(fp, "%lf,%lf", &x, &y) == 2) {
        sumX += x;
        sumY += y;
        sumXY += x * y;
        sumX2 += x * x;
        n++;
    }
    fclose(fp);

    double m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double c = (sumY - m * sumX) / n;

    FILE *out = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/trend_results.csv", "w");
    fprintf(out, "m,c\n%f,%f", m, c);
    fclose(out);

    printf("Calculation Complete!\nSlope (m): %.2f\nIntercept (c): %.2f\n", m, c);
    return 0;
}