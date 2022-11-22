#include <stdio.h>
#include <stdlib.h>

// declaring the function
void fibonacci(long *a, long *b);

int main()
{
    long n, i;
    // 0th and 1st number of the series are 0 and 1
    long f1=1, f0=0;
    
    // get number of terms from user
    printf("Enter a positive integer n\n");
    scanf("%ld", &n);
    
    // check if the entered number is positive or not
    if(n<1) {
        printf("The number is not positive\n");
        exit(1);
    }
    
    printf("The fibonacci series is : \n");
    // print the first two terms f0 and f1
    printf("%ld, %ld, ", f0, f1);
    
    // print 3rd to nth terms
    for(i=2; i<=n; i++) {
      fibonacci(&f1, &f0);
      printf("%ld, ", f1);
      
      // add linespace after every 10th number 
      if((i+1)%10 == 0) printf("\n");
    }

    return 0;
}

// defining the function to add the previous 
// two numbers in the series and store it
void fibonacci(long *a, long *b) {
    
    // *a=f(n-1), *b=f(n-2), n=f(n)
    long n = *a + *b;
    
    // *a=f(n), *b=f(n-1)
    *b = *a;
    *a = n;
}
