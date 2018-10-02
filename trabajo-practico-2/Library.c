#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
int getInt(int* pResult);
int getFloat(float* pResult);
int isFloat(char* pBuffer);
int isInt(char* pBuffer);

int getString(char* pBufferString,int limit)
{
    fflush(stdin);
    fgets(pBufferString,limit,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}
int getEntero(int* pNum,int reint,char* msg,char* msgError,int maximum,int minimum)
{
    int auxNum;
    int result = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getInt(&auxNum) == 0)
        {
            if(auxNum > minimum && auxNum < maximum)
            {
                *pNum = auxNum;
                result = 0;
                break;

            }else
            {
                printf(msgError);
            }


        }else
        {
            printf(msgError);
        }
    }


    return result;
}
int getDecimalNumber(float *pNum, int reint, char* msg, char* msgError,float maximum,float minimum)
{
    float buffer;
    int result = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimum<=maximum && reint >= 0)
    {

        do
        {
            reint--;
            printf("%s",msg);
            if(getFloat(&buffer) == 0 &&
                buffer <= maximum && buffer >= minimum)
            {
                    *pNum = buffer;
                    result = 0;
                    break;

            }else
            {
                printf("%s",msgError);
                fflush(stdin);
            }


        }while(reint >= 0);

    }

    return result;
}
int getInt(int* pResultado)
{
    int result=-1;
    char bufferString[4096];
    if(pResult != NULL)
    {
        if(getString(bufferString,4096) == 0 && isInt(bufferString)==0)
        {

            *pResult=atof(bufferString);
            result=0;

        }
    }
    return result;
}
int getFloat(float* pResult)
{
    int result=-1;
    char bufferString[4096];
    if(pResult != NULL)
    {
        if(getString(bufferString,4096) == 0 && isFloat(bufferString)==0)
        {

            *pResult=atof(bufferString);
            result=0;

        }
    }
    return result;
}
int isFloat(char* pBuffer)
{
    int i=0;
    int result=0;
    int amountOfPoints=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i]=='.' && amountOfPoints==0)
        {
            amountOfPoints++;
            i++;
        }
        if((pBuffer[i] < '0' || pBuffer[i] > '9'))
        {

            result=-1;
            break;
        }
        i++;
    }

    if(amountOfPoints > 2)
    {
        result=-1;
    }

    return result;
}
int isInt(char* pBuffer)
{
    int i=0;
    int result=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            result=-1;
            break;
        }
        i++;
    }
    return result;
}
