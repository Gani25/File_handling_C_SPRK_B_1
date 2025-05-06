// How to read from file
#include <stdio.h>
int main()
{

    FILE *fptr = fopen("demo.txt", "r");

    // printf("%d\n", fptr);
    if (fptr == NULL)
    {
        printf("File Not Found\n");
    }
    else
    {
        printf("File opened successfully\n");
        // READ
        char character;
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%c", character);
        character = fgetc(fptr);
        printf("%d", character);
    }
}