#include <stdio.h>

void createPyramid(int number)
{
    int rows;
    int stars = 1;
    int spaces = number - 1;

    // Iterate many of times defined in "number"
    for (rows = number; rows > 0; rows--)
    {

        // Padding in front of the stars
        int i;
        for (i = spaces; i > 0; i--)
        {
            printf(" ");
        }

        // Add stars to pyramid
        for (i = 0; i < stars; i++)
        {
            printf("x");
        }

        // Update star count to an odd number for each row
        stars += 2;

        // Decrease the number of spaces required for padding
        spaces--;

        printf("\n");
    }
}

int main()
{
    createPyramid(3);
    printf("\n");
    createPyramid(5);
    return 0;
}