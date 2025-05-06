// Store employee information
// name, id, salary, department
// structure
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

typedef struct employeeInfo
{
    int empId;
    char name[MAX_SIZE];
    double salary;
    char department[MAX_SIZE];
} employee;

int main()
{

    FILE *fptr = fopen("employee_info.txt", "ab+");

    employee e1;
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {

        printf("~~~ Employee Info ~~~\n");
        printf("Emp Id = %d\n", e1.empId);
        printf("Emp Name = %s", e1.name);
        printf("Salary = %.2lf\n", e1.salary);
        printf("Department = %s", e1.department);
    }

    printf("Enter name of employee to be deleted: ");
    char name[100];
    fgets(name, 100, stdin);
    rewind(fptr);
    FILE *tempFile = fopen("tempEmp.txt", "ab");
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {

        if (strcmp(e1.name, name) != 0)
        {
            fwrite(&e1, sizeof(employee), 1, tempFile);
        }
    }
    fclose(fptr);
    fclose(tempFile);
    remove("employee_info.txt");
    rename("tempEmp.txt", "employee_info.txt");

    printf("\n\nEmployee Deleted Successfully\n\n");
    fptr = fopen("employee_info.txt", "rb+");
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {

        printf("~~~ Employee Info ~~~\n");
        printf("Emp Id = %d\n", e1.empId);
        printf("Emp Name = %s", e1.name);
        printf("Salary = %.2lf\n", e1.salary);
        printf("Department = %s", e1.department);
    }
    fclose(fptr);
}