#include <stdio.h>
#include <stdlib.h>
#include "CovidSeverity.h"

#define MAX 5000
#define INVALID -1

int main(void) {
	int n, numOfContacts, numOfPositiveCases;
	printf("Enter n: ");
	scanf("%d", &n);

	printf("Enter number of contacts: ");
	scanf("%d", &numOfContacts);

	int** a = (int**)malloc(numOfContacts * sizeof(int*));
	printf("Enter contacts:\n");
	for (int i = 0; i < numOfContacts; i++) {
		a[i] = (int*)malloc(2 * sizeof(int));
		scanf("%d %d", &a[i][0], &a[i][1]);
	}

	printf("Enter number of positive cases: ");
	scanf("%d", &numOfPositiveCases);
	int* b = (int*)malloc(numOfPositiveCases * sizeof(int));
	printf("Enter positive case:\n");
	for (int i = 0; i < numOfPositiveCases; i++) {
		scanf("%d", &b[i]);
	}

	arr_int result = covidSeverity(n, a, b, numOfContacts, numOfPositiveCases);
	printResult(result);

	return 0;
}
