// Update File using fseek()
#include <stdio.h>
int main()
{
    FILE *fptr = fopen("demo.txt", "w+");

    fputs("Hello I am SPRK TECHNOLOGIES", fptr);
    rewind(fptr);
    char alp;
    do
    {
        alp = fgetc(fptr);
        printf("%c", alp);
    } while (alp != EOF);
    printf("\n");

    // UPDATE
    fseek(fptr, 11, SEEK_SET);
    fputs("SKY RANGE ACADEMY", fptr);

    rewind(fptr);
    do
    {
        alp = fgetc(fptr);
        printf("%c", alp);
    } while (alp != EOF);
    printf("\n");
}