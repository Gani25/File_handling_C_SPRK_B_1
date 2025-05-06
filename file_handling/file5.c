// WRITE FILE
#include <stdio.h>
#define MAX_SIZE 80
int main()
{
    FILE *fptr = fopen("student.txt", "w");

    char name[MAX_SIZE];
    int age;

    printf("Enter your name: ");
    fgets(name, MAX_SIZE, stdin);

    fflush(stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    fprintf(fptr, "Student Info\n");
    fprintf(fptr, "Name = %s", name);
    fprintf(fptr, "Age = %d\n", age);
}