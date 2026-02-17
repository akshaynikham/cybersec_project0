#include <stdio.h>

int main(){

    FILE *fp = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/raw_sensor_data.csv", "r");
    if( fp == NULL) {return 1;}

    char line[100];
    double x, y;
    double sumX=0, sumY=0, sumX2=0, sumX3=0, sumX4=0;
    double sumXY=0, sumX2Y=0;
    int n = 0;

    fgets(line, sizeof(line), fp);

    while (fscanf(fp, "%lf,%lf", &x, &y) == 2) {
        sumX  += x;
        sumY  += y;
        sumX2 += x*x;
        sumX3 += x*x*x;
        sumX4 += x*x*x*x;
        sumXY += x*y;
        sumX2Y+= x*x*y;
        n++;
    }

    fclose(fp);

    // double m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    // double c = (sumY - m * sumX) / n;

    double D =
        sumX2*(sumX2*sumX2 - sumX*sumX3)
      - sumX*(sumX3*sumX2 - sumX*sumX4)
      + n*(sumX3*sumX3 - sumX2*sumX4);

    double Da =
        sumY*(sumX2*sumX2 - sumX*sumX3)
      - sumX*(sumXY*sumX2 - sumX*sumX2Y)
      + n*(sumXY*sumX3 - sumX2*sumX2Y);

    double Db =
        sumX2*(sumXY*sumX2 - sumX*sumX2Y)
      - sumY*(sumX3*sumX2 - sumX*sumX4)
      + n*(sumX3*sumX2Y - sumXY*sumX4);

    double Dc =
        sumX2*(sumX2*sumX2Y - sumXY*sumX3)
      - sumX*(sumX3*sumX2Y - sumXY*sumX4)
      + sumY*(sumX3*sumX3 - sumX2*sumX4);

    double a = Da / D;
    double b = Db / D;
    double c = Dc / D;



    fp = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/raw_sensor_data.csv", "r");
    FILE *res = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/quad_residuals.csv", "w");

    fprintf(res, "x,y,y_hat,residual\n");
    fgets(line, sizeof(line), fp);

    while (fscanf(fp, "%lf,%lf", &x, &y) == 2) {
        double y_hat = a*x*x + b*x + c;
        double r = y - y_hat;
        fprintf(res, "%f,%f,%f,%f\n", x, y, y_hat, r);
    }

    return 0;
}