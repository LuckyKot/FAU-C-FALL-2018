#include "common.h"

int initializePortfolio(char* fileName, MyPortfolio* pMyPortfolio) {
	FILE* pFile = 0;
	int i = 0;
	
	pFile = fopen(fileName, "r");

	if (pFile == 0) {
		printf("file %s did not open\n", fileName);
		return;
	}
	while (fscanf(pFile, "%s %lf",pMyPortfolio->positions[i].ticker,
		&(pMyPortfolio->positions[i].price))> 0 && 
		i<pMyPortfolio->positionsCapacity) {
			
		pMyPortfolio->positions[i].shares = 0.0;
		i++;
	}
	pMyPortfolio->positionsSize = i;
	if (pFile) fclose(pFile);
}

Position* findStock(MyPortfolio* pMyPortfolio, char* ticker) {
	int i = 0;
	for (i; i < MAX_MY_STOCKS; i++) {
		if (strcmp(ticker, pMyPortfolio->positions[i].ticker)==0) {
			return &(pMyPortfolio->positions[i]);
		}
	}

	printf("Error: could not find ticker %s in Portfolio\n", ticker);

	return 0;
}