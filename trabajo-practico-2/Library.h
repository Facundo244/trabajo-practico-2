#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

int getInt(int* pNum,int reint,char* msg,char* msgError,int maximum,int minimum);
int getDecimalNumber(float *pNum, int reint, char* msg, char* msgError,float maximum,float minimum);
int getString(char* pBufferString,int limit);

#endif //LIBRARY_H_INCLUDED
