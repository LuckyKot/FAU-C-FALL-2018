/*
* name: project 4
* author: --
* date: 2018/11/16
* added functionality: UI, option to buy any stock, option to sell any stock, automatically saves the portfolio and balance to load
* them next session, option to exit the program, option to evaluate your potfolio, option to reset everything. 
*/

#include "common.h"
#include "simulator.h"
#include "trading.h"
#include "tradingApp.h"

void banner() {
	printf("Welcome to stocks trading program\n");
}

void test() {
	char* fileName = "mystocks.txt";
	char* tFileName = "portfolio.txt";
	MyPortfolio myPortfolio;
	Position* pPosition;
	double newPrice = 0;
	char* ticker = "MSTR";
	double tickerDef = 5;
	char* secondTicker = "YNDX";
	myPortfolio.balance = INITIAL_BALANCE;
	myPortfolio.positionsCapacity = MAX_MY_STOCKS;

	banner();

	initializePortfolio(fileName, &myPortfolio);
	readPortfolio(tFileName, &myPortfolio);
//sets up the portfolio
	
//readPortfolio() will load previous portfolio if you traded before
	pPosition = findStock(&myPortfolio, ticker);
//find the right stock based on the ticker

//	printStock(pPosition);
//printf this one ticker's info
	printPortfolio(&myPortfolio);
//prints out the initial portfolio
	
	buy(&myPortfolio, ticker, 12500);
	buy(&myPortfolio, secondTicker, 3.6);
	buyWithPermission(&myPortfolio, ticker, 10);
//different operations with buying functions

	sell(&myPortfolio, ticker, 20);
	sell(&myPortfolio, secondTicker, 2.1);
	sellWithPermission(&myPortfolio, ticker, 5);
//different operations with selling functions 

	double balance = getBalance(&myPortfolio);

	printf("Your balance: %.2lf\n", balance);
//printing balance after all operations
	printPortfolio(&myPortfolio);
//printing portfolio after all the operations

	savePortfolio(tFileName, &myPortfolio);
//saves portfolio for the next use of this program 
}

void test4() {
	char* fileName = "mystocks.txt";
	char* tFileName = "portfolio.txt";
	MyPortfolio myPortfolio;
	Position* pPosition;
	myPortfolio.balance = INITIAL_BALANCE;
	myPortfolio.positionsCapacity = MAX_MY_STOCKS;

	banner();

	initializePortfolio(fileName, &myPortfolio);

	printPortfolio(&myPortfolio);

//	menu(&myPortfolio);

	currentPrice(&myPortfolio);

	UI(&myPortfolio);

	worth(&myPortfolio);
	reset(&myPortfolio);

}

void process() {
	char* fileName = "mystocks.txt";
	char* tFileName = "portfolio.txt";
	char* bFilename = "mybalance.txt";
	MyPortfolio myPortfolio;
	Position* pPosition;
	myPortfolio.balance = INITIAL_BALANCE;
	myPortfolio.positionsCapacity = MAX_MY_STOCKS;

	banner();

	initializePortfolio(fileName, &myPortfolio);
	readPortfolio(tFileName, &myPortfolio);
	readBalance(&myPortfolio,bFilename);
	//Initializes portfolio, loads portfolio and balance

	printPortfolio(&myPortfolio);
	//Prints portfolio the first time for user's reference
	UI(&myPortfolio);
	//Options menu with loop and exit

	saveBalance(&myPortfolio, bFilename);
	savePortfolio(tFileName, &myPortfolio);
	//Saves portfolio and balance in their respective files for future work
}

int main(void) {
//	test();
//	test4();
	process();
	return 0;
}