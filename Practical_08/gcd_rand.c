// Iterative and Recursive versions of Euclid's algorithm 

#include <stdio.h>
#include <stdlib.h>

// declarating functions for Iterative and Recursive gcd's
int iterativeGCD(int a, int b);              
int recursiveGCD(int a, int b);

int main()
{
    int a, b;
    
    // generate two random numbers between 1 and 12
    srand(time(NULL));
    a = (rand()%12) + 1;
    b = (rand()%12) + 1;
    
    // calling the functions
    printf("Iterative GCD of (%d, %d) is %d\n", a, b, iterativeGCD(a,b));
    printf("Recursive GCD of (%d, %d) is %d\n", a, b, recursiveGCD(a,b));
    
    return 0;
}

// defining function for iterative GCD
int iterativeGCD(int a, int b){
    int temp;
    while(b!=0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// defining function for recursive GCD
int recursiveGCD(int a, int b) {
    if (b == 0) return a;
    else return recursiveGCD(b, a%b);
}
