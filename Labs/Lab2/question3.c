#include <stdio.h>

int main()
{
    // Fibonacci series
    int n, i;
    int sum;

    printf("\n Please enter number of terms: ");
    scanf("%d", &n);

    int arr[n];
    arr[0] = 0;
    arr[1] = 1;

    for (i = 0; i < n - 2; i++)
    {
        // Assign last elemnt of the array to the sum of the two preceding terms.
        sum = arr[i] + arr[i + 1];
        arr[i + 2] = sum;
    }
    for (i = 0; i < n; i++)
    {
        //print each element of the array
        printf("\n %d", arr[i]);
    }

    return 0;
}