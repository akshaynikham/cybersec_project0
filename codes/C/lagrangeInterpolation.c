

#include <stdio.h>

int main(){

    double x_points[] = {1.0, 2.0, 5.0};
    double y_points[] = {10.0, 25.0, 5.0};
    int n = 3;

    double target_x = 3.0;
    double final_y = 0.0;

    for(int i = 0; i < n; i++){

        double L_i = 1.0;

        for (int j = 0; j < n ; j++){

            if(i != j){

                L_i = L_i * (target_x - x_points[j]) / (x_points[i] - x_points[j]);
            }    
        }

        final_y += y_points[i] * L_i;
    }

    printf("The interpolation value at x = %.2f is y = %.2f\n", target_x, final_y);

    return 0;

}