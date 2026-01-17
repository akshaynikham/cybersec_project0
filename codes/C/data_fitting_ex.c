#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("sensor_data.csv", "w");
    fprintf(fp, "Time,Temperature\n");

    for(int x = 1; x <=20; x++){
        float noise = (float)rand() / (float)(RAND_MAX/2);
        float y = 2 * x + noise;
        fprintf(fp, "%d, %.2f\n", x,y);
    }

    fclose(fp);
    printf("csv file generated!\n");
    return 0;

}