#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    FILE *fp = fopen("C:/Users/aksha/Desktop/CyberSecurityProjects/Data/raw_sensor_data.csv", "w");

    if(fp == NULL){
        printf("Error: Could not open data folder. Make sure it exists!\n");
        return 1;
    }

    fprintf(fp, "Time,Voltage\n");
    srand(time(NULL));

    for(int x=1; x<=100; x++){
        float noise = ((float)rand() / (float)(RAND_MAX) *10 ) -5;
        float y = (1.5 * x) + 10 + noise;

        fprintf(fp, "%d,%.2f\n",x,y);
    }

    fclose(fp);
    printf("Successfully generated 100 noisy data points\n");
    return 0;
}