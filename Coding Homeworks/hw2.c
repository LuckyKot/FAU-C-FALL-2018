#define _CRT_SECURE_NO_WARNINGS

/*******************
Name: hw2.c
Date: 2018/09/07
*******************/
#include <stdio.h>

//This program works on this claim: you'll burn one calorie for every 20 steps
int main() {
	double pace;
	double distance;
	int calories;

		printf("Welcome to the Step Per Calorie Calculator!\n");
		printf("===========================================\n");
		
		printf("Please, enter approximate distance (in m) you have walked today here:\n");
		scanf("%lf", &distance);
		printf("Distance:%.1lf m\n",distance);

		printf("Please, enter the length (in cm) of your one step here:\n");
		scanf("%lf", &pace);
		printf("Length:%.1lf cm\n", pace);

		pace = pace*.01;
		//multiplication to translate cm into m
		
		calories = (distance / pace) / 20;
		printf("You have burned:%d calories today. Well done!",calories);
		
		return 0;
}