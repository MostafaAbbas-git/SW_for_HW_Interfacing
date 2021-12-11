#include <stdio.h>

int main()
{
    int x, n, i;
    float sum = 1.0;
    float power = 1.0;
    int factorial = 1;
    
    printf("\n Enter the exponent: ");
    scanf("%d", &x);

    printf("\n Enter the number of iteration: ");
    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        power = power * x;
        factorial = factorial * i;
        sum += (power / factorial);
    }

    printf("\n Exponential result = %.2f", sum);
}
