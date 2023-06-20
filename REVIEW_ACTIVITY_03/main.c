#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Employee.c"

int main()
{
    List empList;
    
    initList(&empList);
    // Not sure why it has warning but it works so ¯\_(ツ)_/¯
    
    addEmployee(&empList, newEmployee(1001, "Maria Dela Cruz", "female", 40.0f));
    addEmployee(&empList, newEmployee(1020, "Sabrina Yap", "female", 35.0f));
    addEmployee(&empList, newEmployee(1030, "Noel Tagpuno", "male", 45.0f));
    
    displayEmployeeList(empList);

    addEmployee(&empList, newEmployee(1004, "Juan Dela Cruz", "male", 35.0f));

    displayEmployeeList(empList);

    displayEmployeeList(getFemaleEmployees(empList));

    return 0;
}
