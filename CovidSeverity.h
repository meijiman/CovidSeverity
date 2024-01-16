#ifndef COVIDSEVERITY_COVIDSEVERITY_H
#define COVIDSEVERITY_COVIDSEVERITY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>

#define MAX 5000
#define INVALID -1

typedef struct arr_int {
    int* arr;
    int size;
} arr_int;

typedef struct matrix_int {
    arr_int* arr;
    int size;
} matrix_int;

typedef struct object {
    int id;
    int f;
} object;

typedef struct arr_object {
    object* arr;
    int size;
} arr_object;

void init(int n);
void printObjects();
void printResult(arr_int);
void markF(int b[], int numOfPositiveCases);
object* searchById(int id);
void DFSUtil(int i, int visited[], arr_int* r);
matrix_int getGroup();
arr_int covidSeverity(int n, int** a, int* b, int numOfContacts, int numOfPositiveCases);
void sort(arr_int arr);

#ifdef __cplusplus
} // extern "C"
#endif

#endif //COVIDSEVERITY_COVIDSEVERITY_H
