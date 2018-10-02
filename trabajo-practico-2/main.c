#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "arrayEmployee.h"
#define AMOUNT_EMPLOYEES 5

int main()
{
    sEmployee employees[AMOUNT_EMPLOYEES];
    int options;
    int id;
    int emptyIndex;
    int flag=0;
    int exit=0;
    chargeEmptyData(employees, AMOUNT_EMPLOYEES);
    do
    {
        system("cls");
        fflush(stdin);
        if(checkIndex(employees,AMOUNT_EMPLOYEES) == -1)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        getInt(&options,3,"1)Charge an employee: \n2)Modify an employee data: \n3)Remove an employee:\n4)Calculate total, average and how many employees exceed the average salary\n5)Exit\n","\nError\n",5,0);
        switch(options)
        {
                case 1:
                    if(emptyIndex(employees,AMOUNT_EMPLOYEES,&emptyIndex)==0)
                    {
                        chargeIndex(employees,emptyIndex,AMOUNT_EMPLOYEES);
                        break;
                    }
                    else
                    {
                        printf("\nNo index found.\n");
                    }
                    break;
                case 2:
                    if(flag == 1)
                    {
                        if(getInt(&id,2,"\nWrite the id you'll like to modify: ", "Error", AMOUNT_EMPLOYEES, -1) == 0)
                        {
                            if(id >=0)
                            {
                                modifyId(employees, id,AMOUNT_EMPLOYEES);
                            }
                            else
                            {
                                printf("\nError, invalid index.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo data charged.\n");
                    }
                    system("pause");
                    break;
                case 3:
                    if(flag == 1)
                    {
                        if(getInt(&id,2,"\n Write the id of the employee you'll like to remove: ", "Error", AMOUNT_EMPLOYEES, -1) == 0)
                        {
                            if(id >=0)
                            {
                               removeEmployee(employees, id,AMOUNT_EMPLOYEES);
                            }
                            else
                            {
                                printf("\nError, invalid index.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\n No data charged. \n");
                    }
                    system("pause");
                    break;
                case 4:
                    if(flag == 1)
                    {
                        calculateTotalAverageSalaries(employees, AMOUNT_EMPLOYEES);
                    }
                    else
                    {
                        printf("\nNo data charged.\n");
                    }
                    system("pause");
                    break;
                case 5:
                exit = 1;
        }
    }while(exit==0);

    return 0;
}

