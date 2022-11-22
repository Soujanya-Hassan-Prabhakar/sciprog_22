// finding e using Taylor Series expansion

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// declaring factorial function
int factorial(int n);

int main(void)
{
    int i, order;
    double e, *terms;
    
    // enter polynomial order
    printf("Please enter the required polynomial order\n");
    if(scanf("%d", &order)!=1) {
        printf("Please enter a number\n");
        return 1;
    }
    
    // allocate space for terms array
    terms = malloc(order*sizeof(double));
    for(i=0; i<order; i++) {
        terms[i] = 1.0 / (double)factorial(i+1);
        printf("e term for order %d is %1.14lf\n", order, terms[i]);
    }
    
    // sum of the exponentials in formula
    e = 1.0;
    for(i=0; i<order; i++) {
        e = e + terms[i];
    }
    
    // freeing the allocated memory space
    free(terms); 
    
    printf("e is estimated as %.10lf with difference %.10lf\n",e ,fabs(e-exp(1.0)));

    return 0;
}

int factorial (int n) {
    if(n<0){
        printf("Error: N should be a positive number\n");
        return(-1);
    }
    else if(n==0) {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}
