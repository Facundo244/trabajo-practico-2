#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} sEmployee;

int addEmployee(sEmployee* employees, int limit,char* name,int sector, char* lastName, float salary);
int chargeEmptyData(sEmployee* employees,int limit);
int chargeIndex(sEmployee* employees,int index,int limit);
int emptyIndex(sEmployee* employees,int limit,int* emptyIndex);
int searchWithId(sEmployee* employees, int limit, int id);
int modifyId(sEmployee* employees, int index, int limit);
int removeEmployee(sEmployee* employees, int id, int limit);
int checkIndex(sEmployee* employees,int limit);
int calculateTotalAverageSalaries(sEmployee* employee, int limit);

#endif //ARRAYEMPLOYEE_H_INCLUDED


