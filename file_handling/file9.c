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

    FILE *fptr = fopen("employee_info.txt", "rb");
    // We can directly store a structure
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {

        printf("~~~ Employee Info ~~~\n");
        printf("Emp Id = %d\n", e1.empId);
        printf("Emp Name = %s", e1.name);
        printf("Salary = %.2lf\n", e1.salary);
        printf("Department = %s", e1.department);
    }
}