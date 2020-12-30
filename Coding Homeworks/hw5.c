#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

#define MAX_NUMBER_OF_INPUTS 10

double calculateAverage(double data[], int sizeOfData);
void printAll(double data[], int sizeOfData);
double findMinimum(double data[], int sizeOfData);
void getDataElements(double *data, int sizeOfData);



void getDataElements(double *data, int sizeOfData) {
	double number = 0;
	for (int i = 5; i < MAX_NUMBER_OF_INPUTS; i++)
	{
		scanf("%lf", &number);
		data[i] = number;
	}
}

double calculateAverage(double data[], int sizeOfData) {
	double summ = 0;
	double average = 0;
	for (int i = 0; i < sizeOfData; i++) {
		summ = summ + data[i];
	}
	average = summ / sizeOfData;
	return average;
}

void printAll(double data[], int sizeOfData) {
	int i = 0;
	for (i; i < sizeOfData; i++) {
		printf("The %dth number of current dataset is %.1lf\n", i, data[i]);
	}
	
}

double findMinimum(double data[], int sizeOfData) {
	int i = 0;
	double minimum = data[0];
	for (i; i < sizeOfData; i++) {

		if (data[i]<minimum) {
			minimum = data[i];
		}
	}
	return minimum;
}


void test() {
	double data[MAX_NUMBER_OF_INPUTS] = { 4.5, 5.6, 4.5, 19.5, 10.4 };
	int sizeOfData = sizeof(data) / sizeof(double);
	double average;
	double minimum;
	getDataElements(data, sizeOfData);
	sizeOfData = MAX_NUMBER_OF_INPUTS;
	average = calculateAverage(data, sizeOfData);
	printAll(data, sizeOfData);
	minimum = findMinimum(data, sizeOfData);

	printf("The average of current dataset is %.1lf\n", average);
	printf("The minimal value of current dataset is %.1lf", minimum);
}

int main() {
	test();
	return 0;
}