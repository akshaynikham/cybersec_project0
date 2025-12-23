#include <stdio.h>

int main(){
    int n ;
    double a[50], sum = 0 ;
    double *p;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for( int i=0; i<n; i++) {
        scanf("%lf", &a[i]);
    }

    p = a;

    for (int i=0; i<n; i++ ){
        sum += *(p + i);
    }

    printf("Sum = %lf\n", sum);
    return 0;
}



// #include <stdio.h>

// int main() {
//     float a = 1.0/3.0;
//     double b = 1.0/3.0;

//     printf("Float  = %.10f\n", a);
//     printf("Double = %.20lf\n", b);

//     return 0;
// }
