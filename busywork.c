/**
 * Date: 9/24/2024
 *
 * Author: Jacob Bryant
 * Class: COS 135
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Outputs ASCII art of a square the specified size, using the characters of the string passed.
void squareCreate(char charString[], int shapeSize, size_t stringSize)
{

    int charPosition = 0;

    // If no string was provided, use default * character.
    // Prevents vulnerability.
    if (stringSize == 0)
    {
        charString = "*";
        stringSize = 1;
    }

    // Create the column for this square
    for (int j = 0; j < shapeSize; j++)
    {
        // Create the row for this square
        for (int k = 0; k < shapeSize; k++)
        {
            // Calculate if the square should use spacing on this line.
            int doSpacing = ((j > 0 && j < shapeSize - 1) && (k > 0 && k < shapeSize - 1));

            if (doSpacing == 1)
            {
                printf(" ");
            }
            else
            {
                printf("%c", charString[charPosition % stringSize]);
                charPosition++;
            }
        }

        printf("\n");
    }
}

// Output ASCII art of a diamond with a top and bottom halves equal to size, using the characters of the string passed.
void emptyDiamond(char charString[], int shapeSize, size_t stringSize)
{

    int charPosition = 0;

    // If no string was provided, use default * character.
    // Prevents vulnerability.
    if (stringSize == 0)
    {
        charString = "*";
        stringSize = 1;
    }

    // Create the top half of the diamond
    for (int j = 0; j < shapeSize; j++)
    {
        for (int k = 0; k < shapeSize * 2; k++)
        {

            int doSpacing = ((shapeSize * 2) - j * 2) / 2;

            if (k > doSpacing - 1 && k < doSpacing + (j * 2))
            {
                printf(" ");
            }
            else
            {
                printf("%c", charString[charPosition % stringSize]);
                charPosition++;
            }
        }

        printf("\n");
    }

    // Create the bottom half of the diamond using same logic as above
    for (int j = shapeSize - 1; j >= 0; j--)
    {
        for (int k = 0; k < shapeSize * 2; k++)
        {
            int doSpacing = ((shapeSize * 2) - j * 2) / 2;

            if (k > doSpacing - 1 && k < doSpacing + (j * 2))
            {
                printf(" ");
            }
            else
            {
                printf("%c", charString[charPosition % stringSize]);
                charPosition++;
            }
        }

        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Must supply at least 3 arguments\n");
        return 0;
    }

    if (strcmp(argv[1], "square") == 0)
    {
        squareCreate(argv[2], atoi(argv[3]), strlen(argv[2]));
        return 0;
    }

    if (strcmp(argv[1], "diamond") == 0)
    {
        emptyDiamond(argv[2], atoi(argv[3]), strlen(argv[2]));
        return 0;
    }

    if (strcmp(argv[1], "both") == 0)
    {
        squareCreate(argv[2], atoi(argv[3]), strlen(argv[2]));
        printf("\n");
        emptyDiamond(argv[2], atoi(argv[3]), strlen(argv[2]));
        return 0;
    }

    printf("Invalid choice for method\n\t-> choices: (\"square\", \"diamond\", \"both\")\n");

    return 0;
}