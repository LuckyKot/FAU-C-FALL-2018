#include "trading.h"


void savePortfolio(char* filename, MyPortfolio *pMyPortfolio) {
	FILE* pFile = 0;

	pFile = fopen(filename, "w");

	if (pFile == 0) {
		printf("Could not open %s file", filename);
	}

	for (int i = 0; i < MAX_MY_STOCKS; i++) {
		fprintf(pFile, "%s %lf\n", pMyPortfolio->positions[i].ticker, pMyPortfolio->positions[i].shares);
	}

	if (pFile) fclose(pFile);

}


int readPortfolio(char* filename, MyPortfolio* pMyPortfolio) {
	FILE* pFile = 0;
	int i = 0;

	pFile = fopen(filename, "r");

	if (pFile == 0) {
		printf("file %s did not open\n", filename);
		return;
	}
	while (fscanf(pFile, "%s %lf", pMyPortfolio->positions[i].ticker,
		&(pMyPortfolio->positions[i].shares))> 0 &&
		i<pMyPortfolio->positionsCapacity) {

		i++;
	}

	if (pFile) fclose(pFile);
}


void printStock(Position* pPosition) {

	printf("ticker: %s price: %.2lf # of shares: %.2lf\n", pPosition->ticker, pPosition->price, pPosition->shares);

}


void printPortfolio(MyPortfolio* pMyPortfolio) {
	printf("=================================\n");
	for (int i = 0; i < MAX_MY_STOCKS; i++) {
		printf("%s %.2lf %.2lf\n", pMyPortfolio->positions[i].ticker,
			pMyPortfolio->positions[i].price,
			pMyPortfolio->positions[i].shares);
	}
	printf("=================================\n");
}


double getBalance(MyPortfolio* pMyPortfolio) {
	return pMyPortfolio->balance;
}


double buy(MyPortfolio* pMyPortfolio, char* ticker, double shares) {
	int i = 0;
	double rawPrice = 0.0;
	double price = 0.0;

	printf("Attempting to buy %.2lf %s\n", shares, ticker);

	rawPrice = getSimulatedPrice(pMyPortfolio, ticker);

	price = rawPrice * shares;
//	printf("%lf\n", price);

	if (price > pMyPortfolio->balance) {
		printf("insufficient funds for the transaction\n");
	}
	else {
		pMyPortfolio->balance -= price;

		for (i; i < MAX_MY_STOCKS; i++) {
			if (strcmp(ticker, pMyPortfolio->positions[i].ticker) == 0) {
				printf("Transaction complete\n");
				pMyPortfolio->positions[i].shares += shares;
				pMyPortfolio->positions[i].price = rawPrice;
			}
		}
	}
}


double sell(MyPortfolio* pMyPortfolio, char* ticker, double shares) {
	int i = 0;
	double price = 0;
	printf("attempting to sell %.2lf %s\n", shares, ticker);
	price = getSimulatedPrice(pMyPortfolio, ticker);
	for (i; i < MAX_MY_STOCKS; i++) {
		if (strcmp(ticker, pMyPortfolio->positions[i].ticker) == 0) {
			if (shares > pMyPortfolio->positions[i].shares) {
				printf("not enough shares to sell\n");
			}
			else {
				pMyPortfolio->positions[i].shares -= shares;
				pMyPortfolio->balance += shares * price;
				printf("Transaction complete\n");
			}
		}
	}

}


double buyWithPermission(MyPortfolio* pMyPortfolio, char* ticker, double shares) {
	double price = getSimulatedPrice(pMyPortfolio, ticker);
	price = price * shares; 
	char answer = 0;
	printf("The next operation of buying %s will cost you %lf for %lf shares\n", ticker, price, shares);
	printf("Would you like to proceed? (Y or N)\n");
	scanf(" %c", &answer);
	answer = toupper(answer);
	if (answer == 'Y'){
		buy(pMyPortfolio, ticker, shares);
	}
	else {
		printf("The operation has been canceled\n");
	}

}


double sellWithPermission(MyPortfolio* pMyPortfolio, char* ticker, double shares) {
	double price = getSimulatedPrice(pMyPortfolio, ticker);
	price = price * shares;
	char answer = 0;
	printf("The next operation of selling %s will result in profit of %lf for %lf shares\n", ticker, price, shares);
	printf("Would you like to proceed? (Y or N)\n");
	answer = 0;
	scanf(" %c", &answer);
	answer = toupper(answer);
	if (answer == 'Y') {
		sell(pMyPortfolio, ticker, shares);
	}
	else {
		printf("The operation has been canceled\n");
	}
}
