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

// Factory for dynamically creating a room struct.
struct Room *createRoom(
    char *name,
    char *code,
    char *description)
{
    struct Room *x = malloc(sizeof(struct Room));
    // Copy strings into the struct fields and null-terminate them.
    snprintf(x->name, sizeof(x->name), "%s", name);
    snprintf(x->code, sizeof(x->code), "%s", code);
    snprintf(x->description, sizeof(x->description), "%s", description);
    return x;
}

// LinkedList implementation
typedef struct NODE
{
    struct Room *data;
    struct NODE *next;
} NODE;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments.");
        return 0;
    }

    // Open file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File could not be opened.");
        return 0;
    }

    char line[500];

    int roomCount = 0;
    int roomProperty = 0;

    char name[50], code[3], description[500];

    NODE *head = NULL;
    NODE *p = NULL;

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
            // Copy room name into temp name buffer.
            sscanf(line + 11, "%[^\n]", name);
            roomProperty++;
            continue;
        }

        // Room code
        if (roomProperty == 1)
        {
            // Copy room code into temp code buffer.
            sscanf(line + 11, "%s", code);
            roomProperty++;
            continue;
        }

        // Room desc
        if (roomProperty == 2)
        {
            // Copy room desc into temp desc buffer.
            sscanf(line + 18, "%[^\n]", description);

            // Create a new room
            struct Room *newRoom = createRoom(name, code, description);

            // Create a new node
            NODE *newNode = malloc(sizeof(NODE));

            // Set node data to new node and set next to NULL.
            newNode->data = newRoom;
            newNode->next = NULL;

            // Set current head to this node.
            if (head == NULL)
            {
                head = newNode;
            }
            else // Set latest node's next to this node.
            {
                p->next = newNode;
            }

            // Set node pointer to the latest node.
            p = newNode;

            roomCount++;
            roomProperty = 0;

            // Reset string allocations.
            memset(name, 0, sizeof(name));
            memset(code, 0, sizeof(code));
            memset(description, 0, sizeof(description));
        }
    }

    NODE *current = head;

    // Traverse linked list and print out room data.
    while (current != NULL)
    {
        if (current->data != NULL)
        {
            printf("Room %s: %s\n", current->data->code, current->data->name);
        }
        current = current->next;
    }

    fclose(fp);
}