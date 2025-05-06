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

#define FILE_NAME "employees.txt"

void saveEmployee()
{
    FILE *fptr = fopen(FILE_NAME, "ab");
    int numOfEmp;
    printf("Enter number of employees to be saved: ");
    scanf("%d", &numOfEmp);

    employee e1;
    for (int i = 1; i <= numOfEmp; i++)
    {
        printf("\n----------------------------------------------------\n");
        printf("Enter employee id: ");
        scanf("%d", &e1.empId);

        fflush(stdin);
        printf("Enter employee name: ");
        fgets(e1.name, MAX_SIZE, stdin);

        fflush(stdin);
        printf("Enter department: ");
        fgets(e1.department, MAX_SIZE, stdin);
        fflush(stdin);

        printf("Enter salary: ");
        scanf("%lf", &e1.salary);
        fflush(stdin);
        printf("----------------------------------------------------\n");
        // search by id
        fwrite(&e1, sizeof(employee), 1, fptr);
        printf("\nEmployee with %d saved successfully\n", e1.empId);
    }

    fclose(fptr);
}

void getAllEmployees()
{
    FILE *fptr = fopen(FILE_NAME, "rb");

    employee e1;
    int flag = 0;
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {

        printf("\n----------------------------------------------------\n");
        printf("\n~~~ Employee Info ~~~\n");
        printf("Emp Id = %d\n", e1.empId);
        printf("Emp Name = %s", e1.name);
        printf("Salary = %.2lf\n", e1.salary);
        printf("Department = %s", e1.department);
        printf("\n----------------------------------------------------\n");
        flag++;
    }
    fclose(fptr);
    if (flag == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("\nEmployee Not Available\n");
        printf("\n----------------------------------------------------\n");
    }
}

// Find Employees By Department -- Multiple
// Before saving check if id is same then give msg id is already exists

// Func Return Employee Structure (id)