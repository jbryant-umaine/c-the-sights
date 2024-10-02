/**
 * Date: 9/10/2024
 *
 * Author: Jacob Bryant
 * Class: COS 135
 */
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

void createPyramidReverse(int number)
{
    int rows;
    int stars = (2 * number) - 1; // Start with largest row
    int spaces = 0;               // Start with no leading spaces

    // Iterate many of times defined in "number"
    for (rows = 0; rows < number; rows++)
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

        // Decrement star count to an odd number for each row
        stars -= 2;

        // Increase the number of spaces required for padding
        spaces++;

        printf("\n");
    }
}

int main()
{
    createPyramidReverse(7);
    createPyramid(7);
}