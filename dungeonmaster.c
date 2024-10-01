#include <stdio.h>
#include <stdlib.h>

struct Room
{
    char name;
    char code;
    char description;
};

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments.");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");

    char line[2048];

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("Line: %s", line);
    }

    fclose(fp);
}