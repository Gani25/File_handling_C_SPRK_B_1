// Understand how to open file in c using read mode
#include <stdio.h>
int main()
{

    FILE *fptr = fopen("demo.txt", "w");

    // printf("%d\n", fptr);
    if (fptr == NULL)
    {
        printf("File Not Found\n");
    }
    else
    {
        printf("File opened successfully\n");
        fclose(fptr);
    }
}