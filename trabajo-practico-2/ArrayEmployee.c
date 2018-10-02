#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "library.h"

int generateId(void);

int emptyIndex(sEmployee* employees,int limit,int* emptyIndex)
{
    int i=0;
    int result = -1;
    while(i<limit)
    {
        if(employees[i].isEmpty==-1)
        {
            *emptyIndex=i;
            result = 0;
            break;
        }
        i++;
    }
    return result;

int addEmployee(sEmployee* employees, int limit,char* name,int sector, char* lastName, float salary)
{
    int result = -1;
    int emptyIndex;
    emptyIndex(employees,limit, &emptyIndex);
    if(employees != NULL && limit >0)
    {
          if(emptyIndex >= 0)
          {
            strncpy(employees[emptyIndex].name,name,51);
            employees[emptyIndex].sector=sector;
            strncpy(employees[emptyIndex].lastName,lastName,51);
            employees[emptyIndex].salary=salary;
            employees[emptyindex].id=generateId();
            employees[emptyIndex].isEmpty=0;
            result =0;
          }
    }
    return result;
}
int chargeEmptyData(sEmployee* employees, int limit)
{
    int i;
    for(i=0;i<limit;i++)
    {
        employees[i].isEmpty=-1;
    }
    return 0;
}
int chargeIndex(sEmployee* employees,int index,int limit)
{
    char auxName[51];
    char auxLastName[51];
    int auxSector;
    float auxSalary;
    printf("Name: \n");
    if(getString(auxName,51)==0)
    {

                printf("Last Name: \n");
                if(getString(auxLastName,51)==0)
                {
                    if(getInt(&auxSector,2,"Sector: \n", "\nError\n",6,0) == 0)
                    {
                        if(getDecimalNumber(&auxSalary, 2, "Salary: \n", "\nError\n",99999,0)== 0)
                        {
                                strncpy(employees[index].name,auxName,51);
                                strncpy(employees[index].lastName,auxLastName,51);
                                employees[index].sector = auxSector;
                                employees[index].salary = auxSalary;
                                employees[index].isEmpty = 0;
                                employees[index].id = generateId();
                        }
                    }
                }

    }
    return 0;
}

int generateId(void)
{
    int cont = -1;
    return ++cont;
}
int searchWithId(sEmployee* employees, int limit, int id)
{
    int i;
    int result = -1;
    for(i = 0; i < limit; i++)
    {
        if(employees[i].isEmpty == 0 && employees[i].id == id)
        {
            result = i;
            break;
        }
    }
    return result;
}
int modifyId(sEmployee* employees, int index, int limit)
{
    char auxName[51];
    char auxLastName[51];
    int auxSector;
    float auxSalary;
    int id;
    int options;
    int exit=0;
    id = searchWithId(employees,limit,index);
    if(id >= 0)
    {
        if(employees != NULL && limit >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                getInt(&options,4,"1)Modify an employee name: \n2)Modiffy and employee last name: \n3)Modify an employee sector: \n4)Modify an employee salary: \n5)Exit\n","\nError\n",6,0);
                switch(options)
                {
                        case 1:
                            printf("Write the new employee name:\n");
                            if(getString(auxName,51)==0)
                            {
                                 strncpy(employees[index].name,auxName,51);
                            }
                            break;
                        case 2:
                             printf("Write the new employee last name: \n");
                            if(getString(auxLastName,51)==0)
                            {
                                strncpy(employees[index].lastName,auxLastName,51);
                            }
                            break;
                        case 3:
                            if(getInt(&auxSector,2,"Write the new employee sector \n", "\nError\n",4,0) == 0)
                            {
                                employees[index].sector = auxSector;
                            }
                            break;
                        case 4:
                            if(getDecimalNumber(&auxSalary,2,"Write the new employee salary: \n","\nError\n",99999,0) == 0)
                            {
                                employees[index].salary = auxSalary;
                            }
                            system("pause");
                            break;
                        case 5:
                        exit = 1;
                }
            }while(exit==0);
        }
    }
    return 0;
}
int removeEmployee(sEmployee* employees, int id, int limit)
{
    int result = -1;
    int i;
    for(i = 0; i < limit; i++)
    {
        if(employees[i].isEmpty == 0 && employees[i].id == id)
        {
            employees[i].isEmpty = -1;
            result = 0;
            break;
        }
    }
    return result;
}
int checkIndex(sEmployee* employees,int limit)
{
    int i=0;
    int result = 0;
    if(employees != NULL && limit > 0)
    {
         while(i<limit)
        {
            if(employees[i].isEmpty==0)
            {
                result = -1;
                break;
            }
            i++;
        }
    }

    return result;
}
int calculateTotalAverageSalaries(sEmployee* employees, int limit)
{
    int result = -1;
    int i;
    int flag = 0;
    float accumulatorOfEmployees = 0;
    float quantityOfSalaries = 0;
    float average;
    int quantityOfMaximumSalary =0;
    if(employees != NULL && limit > 0)
    {
        for(i = 0; i < limit; i++)
        {
            if(employees[i].isEmpty == 0)
            {
                accumulatorOfEmployees += employees[i].salary;
                quantityOfSalaries++;
            }
        }

        average = accumulatorOfEmployees / quantityOfSalaries;

        for(i = 0; i < limit; i++)
        {
            if(employees[i].isEmpty == 0 && employees[i].salary > average)
            {
                quantityOfMaximumSalary++;
                flag = 1;
            }
        }
        result = 0;
    }
    if(quantityOfSalaries > 0)
    {
        printf("The salaries total is: %.2f", accumulatorOfEmployees);
        printf(" and the salaries average is: %.2f\n", average);
    }else
    {
        printf("No salaries charged.\n");
    }
    if(flag == 1)
    {
        printf("The amount of salaries that exceed the average is: %d\n", quantityOfMaximumSalary);
    }else
    {
        printf("No salaries exceeds the average.\n");
    }
    return result;

}
