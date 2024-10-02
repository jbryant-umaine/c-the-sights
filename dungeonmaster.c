/**
 * Date: 10/1/2024
 *
 * Author: Jacob Bryant
 * Class: COS 135
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Room struct that defines required data.
struct Room
{
    char name[50];
    char code[3];
    char description[500];
};

int main(int argc, char *argv[])
{
    // Check if file name was passed as argument.
    if (argc < 2)
    {
        printf("Not enough arguments.");
        return 0;
    }

    // Attempt to open file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File could not be opened.");
        return 0;
    }

    // Keep track of how many rooms along with which property.
    int roomCount = 0;
    int roomProperty = 0;

    // Allocate memory for one room.
    struct Room *rooms = malloc(sizeof(struct Room));

    char line[500];

    // Read file line by line
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // Ignore empty lines
        if (line[0] == '\n')
        {
            roomProperty = 0;
            continue;
        }

        // Room name
        if (roomProperty == 0)
        {
            // Copy room name
            sscanf(line + 11, "%[^\n]", rooms[roomCount].name);
            roomProperty++;
            continue;
        }

        // Room code
        if (roomProperty == 1)
        {
            char code[3];
            // Copy room code
            sscanf(line + 11, "%s", rooms[roomCount].code);
            roomProperty++;
            continue;
        }

        // Room desc
        if (roomProperty == 2)
        {
            char description[500];

            // Copy room desc
            sscanf(line + 18, "%[^\n]", rooms[roomCount].description);

            roomCount++;

            struct Room *temp = realloc(rooms, (roomCount + 1) * sizeof(struct Room));

            roomProperty = 0;

            rooms = temp;
        }
    }

    for (int i = 0; i < roomCount; i++)
    {
        printf("Room %s: %s\n", rooms[i].code, rooms[i].name);
    }

    fclose(fp);
}