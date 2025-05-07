#define MAX_SIZE 50

typedef struct employeeInfo
{
    int empId;
    char name[MAX_SIZE];
    double salary;
    char department[MAX_SIZE];
} employee;

#define FILE_NAME "employees.txt"

void findById(int id, employee *emp)
{
    FILE *fptr = fopen(FILE_NAME, "rb");
    employee e1;
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {
        if (e1.empId == id)
        {
            emp->empId = e1.empId;
            strcpy(emp->name, e1.name);
            strcpy(emp->department, e1.department);
            emp->salary = e1.salary;
            fclose(fptr);
            return; // exit
        }
    }

    fclose(fptr);
    emp->empId = -1;
}

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

        // check if empId is already exists
        employee existingEmployee;
        findById(e1.empId, &existingEmployee);
        // printf("Name = %s", existingEmployee.name);
        // printf("ID = %d\n", existingEmployee.empId);
        if (existingEmployee.empId == -1)
        {
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
            printf("\nEmployee with id = %d saved successfully\n", e1.empId);
        }
        else
        {
            printf("\nEmployee with id = %d already exists\n", e1.empId);
        }
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

void deleteEmployeeByEmpId()
{
    int empId;
    printf("Enter employee id to be deleted: ");
    scanf("%d", &empId);
    fflush(stdin);
    // check if emp with id exists or not?
    employee existingEmp;
    findById(empId, &existingEmp);
    if (existingEmp.empId == -1)
    {
        printf("Employee with id = %d not exists\n", empId);
        return;
    }

    // Delete Logic
    FILE *fptr = fopen(FILE_NAME, "ab+");
    FILE *tempFile = fopen("tempEmployee.txt", "ab");

    employee e1;
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {
        if (e1.empId != empId)
        {
            // copy into temp
            fwrite(&e1, sizeof(employee), 1, tempFile);
        }
    }

    printf("Deleting employee with id = %d\n", empId);
    fclose(fptr);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("tempEmployee.txt", FILE_NAME);
}

void updateEmployee()
{
    int empId;
    printf("Enter employee id to be updated: ");
    scanf("%d", &empId);
    fflush(stdin);
    // check if emp with id exists or not?
    employee existingEmp;
    findById(empId, &existingEmp);
    if (existingEmp.empId == -1)
    {
        printf("Employee with id = %d not exists\n", empId);
        return;
    }

    // Update Logic
    FILE *fptr = fopen(FILE_NAME, "rb+");

    employee e1;
    int choice;
    printf("Select Choice For Update:\n");
    printf("1. Update Name\n");
    printf("2. Update Department\n");
    printf("3. Update Salary\n");
    printf("4. Update All\n");
    scanf("%d", &choice);
    fflush(stdin);
    while (fread(&e1, sizeof(employee), 1, fptr) > 0)
    {
        if (e1.empId == empId)
        {
            switch (choice)
            {
            case 1:
                printf("Enter updated employee name: ");
                fgets(e1.name, MAX_SIZE, stdin);

                fflush(stdin);
                fseek(fptr, -sizeof(employee), SEEK_CUR);
                fwrite(&e1, sizeof(employee), 1, fptr);

                break;
            case 2:
                printf("Enter updated department: ");
                fgets(e1.department, MAX_SIZE, stdin);
                fflush(stdin);
                fseek(fptr, -sizeof(employee), SEEK_CUR);
                fwrite(&e1, sizeof(employee), 1, fptr);
                break;
            case 3:
                printf("Enter updated salary: ");
                scanf("%lf", &e1.salary);
                fflush(stdin);

                fseek(fptr, -sizeof(employee), SEEK_CUR);
                fwrite(&e1, sizeof(employee), 1, fptr);
                break;
            case 4:

                // update all 3 fields name, salary, department
                printf("Enter updated employee name: ");
                fgets(e1.name, MAX_SIZE, stdin);

                fflush(stdin);
                printf("Enter updated department: ");
                fgets(e1.department, MAX_SIZE, stdin);
                fflush(stdin);

                printf("Enter updated salary: ");
                scanf("%lf", &e1.salary);
                fflush(stdin);

                fseek(fptr, -sizeof(employee), SEEK_CUR);
                fwrite(&e1, sizeof(employee), 1, fptr);
                break;
            default:
                printf("Please select correct choice\n");
                break;
            }
            break;
        }
    }

    printf("Updating employee with id = %d\n", empId);
    fclose(fptr);
}

// Find Employees By Department -- Multiple
// Before saving check if id is same then give msg id is already exists

// Func Return Employee Structure (id)