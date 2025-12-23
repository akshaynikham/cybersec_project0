// f(x)=x**3+x−1

#include <stdio.h>

double f(double x);

int main(){

    double x;
    printf("Enter Value of x: ");
    scanf("%lf", &x);

    printf("f(x) = %lf" , f(x));
    return 0;


}

double f(double x){
    return x*x*x+x-1;
}