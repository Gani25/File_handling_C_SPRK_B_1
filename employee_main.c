#include <stdio.h>
#include "employee_header.h"

int main()
{
    int choice;
    do
    {
        printf("\n----------------------------------------------------\n");
        printf("Press\n");
        printf("1. Add Employee\n");
        printf("2. Get All Employee\n");
        printf("7. Exit\n");
        printf("----------------------------------------------------\n");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            saveEmployee();
            break;
        case 2:
            getAllEmployees();
            break;
        case 7:
            printf("\n----------------------------------------------------\n");
            printf("Thanks for using our employee management software\n");
            printf("----------------------------------------------------\n");
            break;
        default:
            printf("\n----------------------------------------------------\n");
            printf("Please select the correct choice\n");
            printf("----------------------------------------------------\n");
        }
    } while (choice != 7);
}