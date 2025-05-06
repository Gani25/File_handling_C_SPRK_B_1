// Store employee information
// name, id, salary, department
// structure
#include <stdio.h>
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
    employee e1;

    printf("Enter employee id: ");
    scanf("%d", &e1.empId);
    fflush(stdin);
    printf("Enter name: ");
    fgets(e1.name, MAX_SIZE, stdin);
    fflush(stdin);
    printf("Enter employee salary: ");
    scanf("%lf", &e1.salary);
    fflush(stdin);

    printf("Enter department: ");
    fgets(e1.department, MAX_SIZE, stdin);
    fflush(stdin);

    FILE *fptr = fopen("employee_info.txt", "ab");
    // We can directly store a structure
    fwrite(&e1, sizeof(employee), 1, fptr);

    printf("Employee Saved Successfully");
}