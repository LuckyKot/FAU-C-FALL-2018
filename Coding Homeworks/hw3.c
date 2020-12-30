/*******************
Name: hw3.c
Date: 2018/09/14
*******************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

#define MAX_DISTANCE 175000
#define MIN_DISTANCE 0
#define MAX_STRIDE 103
#define MIN_STRIDE 22
#define MAX_ITERATIONS 10
#define LOW_STEPS 3500
#define HIGH_STEPS 10500

//hw2.c REFERENCE
//This program works on this claim: you'll burn one calorie for every 20 steps
//https://www.livestrong.com/article/320124-how-many-calories-does-the-average-person-use-per-step/
//====================================================================================================
//hw3.c BONUS CREDIT REFERENCE:
//https://www.verywellfit.com/whats-typical-for-average-daily-steps-3435736
//Overall average amount of steps is considered to be 7000
//The categories will be Low, Average, Above average
//Since 7000 is average, that means it is 50th percentile and low will be 25th, while above average 75th
//7000 / 2 = 3500 = Low boundary
//7000 + 3500 = 10500 Upper boundary

int main() {
	double stride;
	double distance;
	double calories;
	int i = 0;
	char repeat;
	double calorieStats[MAX_ITERATIONS];
	int calorieNumber = 0;

	//Banner
	while (i < MAX_ITERATIONS) {


		printf("Welcome to the Step Per Calorie Calculator!\n");
		printf("===========================================\n");

		//input
		do {
			printf("Please, enter approximate distance (in m) you have walked today here:[%d] ... [%d]\n", MIN_DISTANCE, MAX_DISTANCE);
			scanf("%lf", &distance);
		} while (distance<MIN_DISTANCE || distance>MAX_DISTANCE);
		// ranges picked are based on this:
		//http://www.guinnessworldrecords.com/world-records/farthest-distance-nordic-walking-in-24-hours

		do {
			printf("Please, enter the length (in cm) of your one step here:[%d] ... [%d]\n", MIN_STRIDE, MAX_STRIDE);
			scanf("%lf", &stride);
		} while (stride < MIN_STRIDE || stride > MAX_STRIDE);
		//min and max for this value are from here: https://wpcalc.com/dlina-shaga/
		//min and max values for height to calculate stride are from these two websites: 
		//http://www.guinnessworldrecords.com/records/hall-of-fame/robert-wadlow-tallest-man-ever
		//https://en.wikipedia.org/wiki/List_of_the_verified_shortest_people

		stride = stride*.01;
		//multiplication to translate cm into m

		//calculation
		calories = (distance / stride) / 20;
		calorieStats[calorieNumber] = calories;
		calorieNumber++;

		//output
		printf("You have burned:%.0f calories today.\n", calories);
		
		//categorizing
		if (distance/stride <= LOW_STEPS ) {
			printf("Well Done! However, you should walk a bit more!\n");
		}
		else if (distance/stride >= HIGH_STEPS) {
			printf("Well Done! You walk a lot!\n");
		} 
		else {
			printf("Well Done! You walk just enough!\n");
		}
		
		//repeat
		printf("Would you like to start over? Press [Y] for yes or [N] for no.\n");
		scanf(" %c",&repeat);
		repeat = toupper(repeat);
		if (repeat != 'Y') break;
		
		i++;
	}
	//arrays
	i = 0;
	while (i < calorieNumber) {
		printf("Calories[%d]=%.1lf\n", i , calorieStats[i]);
		i++;
	}
	return 0;
}