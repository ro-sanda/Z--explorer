#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "program.h"

void read(double *matriz,int numero,int filas,int columnas,int opcion);

void save(double *matriz,int num,int opcion,int filas,int columnas);
void savex(double *matriz, char headers[11][22], int num,int opcion,int filas,int columnas);
void saveo(double *matriz, char headers[11][22], int num,int opcion,int filas,int columnas);


int indexofSmallestElement(double array[], int size);


#endif
