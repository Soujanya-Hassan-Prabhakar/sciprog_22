#include <stdio.h>
#include <stdlib.h>

// defining the hanoi function
void hanoi(int n, int rod1, int rod3, int rod2){
    
    // n = 1, then move the disc from rod 1 to rod 3
    if(n == 1) {
        printf("Move disc from %d to %d \n", rod1, rod3);
    }
    
    // for n > 1, using recursive function
    else {
        hanoi(n-1, rod1, rod2, rod3);
        printf("Move disc from %d to %d\n", rod1, rod3);
        hanoi(n-1, rod2, rod3, rod1);
    }
}

int main()
{
    int h;
    // input for number of discs
    printf("Enter the number of discs: \n");
    scanf("%d", &h);
    printf("\nSolution for %d discs: \n", h);
    //calling the function
    hanoi(h, 1, 3, 2);
    
    return 0;
}

