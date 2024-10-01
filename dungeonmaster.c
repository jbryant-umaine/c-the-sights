#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Room
{
    char name[50];
    char code[2];
    char description[200];
};

struct Room *createRoom(
    char *name,
    char *code,
    char *description)
{
    struct Room *x = malloc(sizeof(struct Room));
    strcpy(x->name, name);
    strcpy(x->code, code);
    strcpy(x->description, description);
    return x;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments.");
        return 0;
    }

    // struct Room rooms[1000];

    FILE *fp = fopen(argv[1], "r");

    char line[2048];

    int roomCount = 0;
    int roomProperty = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {

        if (strlen(line) != 0)
        {
            printf("Line: %s", line);
        }

        roomProperty++;
        roomCount++;
    }

    fclose(fp);
}