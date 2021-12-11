#include <stdio.h>
#define INT_BITS 8

int leftRotate(int x, int shift)
{
    return (x << shift) | (x >> (INT_BITS - shift));
}

int rightRotate(int x, int shift)
{
    return (x >> shift) | (x << (INT_BITS - shift));
}

int main()
{
    int x, n, o;

    printf("\n Enter an 8bit number: ");
    scanf("%d", &x);

    printf("\n Enter number of rotate cycles: ");
    scanf("%d", &n);

    printf("\n Enter rotate option (1: Left, 2: Right): ");
    scanf("%d", &o);
    if (o == 1) // Left direction
    {
        printf("Left Rotation of %d by %d is ", x, n);
        printf("%d", leftRotate(x, n));
    }
    else // Right direction
    {

        printf("\nRight Rotation of %d by %d is ", x, n);
        printf("%d", rightRotate(x, n));
    }
}
