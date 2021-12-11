#include <stdio.h>

int main()
{
    int x, y, rows;
    rows = 9;

    for (y = 0; y < rows; y++)
    {
        for (x = 0; x < 9; x++)
        {
            if (y == (4 - x) || y == (x - 4) || y == (x + 4) || y == (-x + 12)) // outer lines.
            {
                printf("*");
            }
            else if (x > (4 - y) && x < (y + 4) && x > (y - 4) && x < (12 - y)) // fill the gaps.
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
