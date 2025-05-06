// How to read from file -> LOOP
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
        do
        {
            character = fgetc(fptr);
            if (character != EOF)
            {
                printf("%c", character);
            }

        } while (character != EOF);
    }
}