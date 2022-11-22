#include <stdio.h>
#include <math.h>


// declaring function to calculate hyperbolic arc tangent
// using Maclaurin series
double arc_tanh1(const double x, const double delta);
// using natural logarithms
double arc_tanh2(const double x);

int main()
{
    double delta, x;
    double diff;
    
    // delta value
    printf("Enter the precision for Maclaurin series: \n");
    scanf("%lf", &delta);
    
    int len = 1000;
    double tan1[len];  // Store the results of arc_tanh1 for each x
    double tan2[len];  // Store the results of arc_tanh2 for each x
    
    // step increase of 0.1 (-1 ≤ x ≥ 1)
    printf("For x increasing at the rate of 0.1\n");
    int j=0;  // array index
    x = -0.9;
    while(x <= 0.9 && j<len) {
        tan1[j] = arc_tanh1(x, delta);
        tan2[j] = arc_tanh2(x);
        diff = fabs(tan1[j] - tan2[j]);
        printf("The difference between them at x=%lf is: %.10lf\n", x, diff);
        j++;
        x += 0.1;
    }
    
    printf("\n\n");
    
    // step increase of 0.01 (-1 ≤ x ≥ 1)
    printf("For x increasing at the rate of 0.01\n");
    j = 0;
    x = -0.9;
    while(x <= 0.9 && j<len) {
        tan1[j] = arc_tanh1(x, delta);
        tan2[j] = arc_tanh2(x);
        diff = fabs(tan1[j] - tan2[j]);
        printf("The difference between them at x=%lf is: %.10lf\n", x, diff);
        j++;
        x += 0.01;
    }
    
    return 0;
}

// function to calculate the hyperbolic arc tangent using Maclaurin series
double arc_tanh1(const double x, const double delta) {
    double arcTan = 0;  // to store value of the sum
    double elem, val;
    int n = 0; // sum parameter
    do {
        val = 2*n+1;  // 2n+1
        elem = pow(x,val)/val;
        arcTan += elem;
        n++;
    } while(fabs(elem) >= delta);
    
    return arcTan;
}

// function to calculate the hyperbolic arc tangent using natural logarithms
double arc_tanh2(const double x) {
    return (log(1+x)-log(1-x))/2;
}
