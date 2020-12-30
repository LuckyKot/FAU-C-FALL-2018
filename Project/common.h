#ifndef COMMON_H
#define COMMON_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TICKER_SIZE 10
#define MAX_MY_STOCKS 5
#define INITIAL_BALANCE 20000

typedef struct {
	char ticker[MAX_TICKER_SIZE];
	double price;
	double shares;
} Position;

typedef struct {
	double balance;
	Position positions[MAX_MY_STOCKS];
	int positionsSize;
	int positionsCapacity;  //Should be set to MAX_MY_STOCKS
} MyPortfolio;

int initializePortfolio(char* fileName, MyPortfolio* pMyPortfolio);
Position* findStock(MyPortfolio* pMyPortfolio, char* ticker);

#endif

