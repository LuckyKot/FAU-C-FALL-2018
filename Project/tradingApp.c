#include "tradingApp.h"

//The UI function which loops the menu and listens for output of menu function 
//in order to exit the program the menu function's value must turn to 1

void UI(MyPortfolio* pMyPortfolio) {
	int i = 0;
	int end = 0;
	for (i; i < 50; i++) {
		end = menu(pMyPortfolio);
		if (end == 1) {
			break;
		}
	}
}

//menu function allows the user to choose the needed function by entering the specified number
//with help of switch() function

int menu(MyPortfolio* pMyPortfolio) {
	int x = 0;
	printf("Please, choose your option:\n1. Show your portfolio\n2. Buy stock\n3. Sell stock\n4. Show Balance\n");
	printf("5. Show current price of stocks\n6. Show current worth of portfolio\n7. Reset the portfolio\n8. Exit\n");
	scanf("%d", &x);
	double balance = 0;
	switch (x) {
	case 1:
		printPortfolio(pMyPortfolio);
		break;
	case 2:
		//buy
		buyUI(pMyPortfolio);
		break;
	case 3:
		//sell
		sellUI(pMyPortfolio);
		break;
	case 4:
		//balance
		balance = getBalance(pMyPortfolio);
		printf("Your balance: %.2lf\n", balance);
		break;
	case 5:
		//current prices
		currentPrice(pMyPortfolio);
		break;
	case 6:
		//current worth
		worth(pMyPortfolio);
		break;
	case 7:
		//reset portfolio
		reset(pMyPortfolio);
		break;
	case 8:
		//exit
		return 1;
		break;
	default:
		printf("Wrong entry\n");
		break;
	}
}

//buyUI function lets user to choose the stock he/she would like to buy and amount of shares, then plugs in the values 
//into the buyWithPermission() function that was earlier created in project 3

int buyUI(MyPortfolio* pMyportfolio) {
	int ticker = 0;
//	char* ticker = 0;
	double shares = 0;
	printf("You chose to buy stock\n");
	printf("Please, choose the ticker you would like to buy\n");
	for (int i = 0; i < pMyportfolio->positionsSize;i++) {
		printf("%d.%s\n", i+1, pMyportfolio->positions[i].ticker);
	}
	printf("Press 6 to cancel and return to main menu\n");
	scanf("%d",&ticker);
	switch (ticker) {
	case 1:
		printf("Please, enter amount of shares you would like to buy:\n");
		scanf("%lf",&shares);
		buyWithPermission(pMyportfolio, pMyportfolio->positions[ticker-1].ticker,shares);
	//	buy(pMyportfolio, "YNDX", shares);
		break;
	case 2:
		printf("Please, enter amount of shares you would like to buy:\n");
		scanf("%lf", &shares);
		buyWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 3:
		printf("Please, enter amount of shares you would like to buy:\n");
		scanf("%lf", &shares);
		buyWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 4:
		printf("Please, enter amount of shares you would like to buy:\n");
		scanf("%lf", &shares);
		buyWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 5:
		printf("Please, enter amount of shares you would like to buy:\n");
		scanf("%lf", &shares);
		buyWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 6:
		printf("The operation was canceled\n");
		break;
	default:
		printf("You chose the wrong option, operation canceled\n");
		break;
	}

	/*printf("Please, enter a ticker you would like to buy:\n");
	scanf("%s", &ticker);
	printf("Please, enter the amount of shares you would like to buy:\n");
	scanf("%lf", &shares);
	buyWithPermission(pMyportfolio, &ticker, shares);*/
}

//sellUI function lets user to choose the stock he/she would like to buy and amount of shares, then plugs in the values 
//into the sellWithPermission() function that was earlier created in project 3

int sellUI(MyPortfolio* pMyportfolio) {
	int ticker = 0;
	double shares = 0;
	printf("You chose to sell stock\n");
	printf("Please, choose the ticker you would like to sell\n");
	for (int i = 0; i < pMyportfolio->positionsSize; i++) {
		printf("%d.%s\n", i + 1, pMyportfolio->positions[i].ticker);
	}
	printf("Press 6 to cancel and return to main menu\n");
	scanf("%d", &ticker);
	switch (ticker) {
	case 1:
		printf("Please, enter amount of shares you would like to sell:\n");
		scanf("%lf", &shares);
		sellWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 2:
		printf("Please, enter amount of shares you would like to sell:\n");
		scanf("%lf", &shares);
		sellWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 3:
		printf("Please, enter amount of shares you would like to sell:\n");
		scanf("%lf", &shares);
		sellWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 4:
		printf("Please, enter amount of shares you would like to sell:\n");
		scanf("%lf", &shares);
		sellWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 5:
		printf("Please, enter amount of shares you would like to sell:\n");
		scanf("%lf", &shares);
		sellWithPermission(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker, shares);
		break;
	case 6:
		printf("The operation was canceled\n");
		break;
	default:
		printf("You chose the wrong option, operation canceled\n");
		break;
	}
}

//saveBalance function not accessible in the menu, automatically save balance into balance.txt file before the exit
//saves the balance for future use

void saveBalance(MyPortfolio* pMyportfolio,char* filename) {
	FILE* pFile = 0;

	pFile = fopen(filename, "w");

	if (pFile == 0) {
		printf("Could not open %s file", filename);
	}
	else {
		fprintf(pFile, "%lf", pMyportfolio->balance);
	}
	

	if (pFile) fclose(pFile);
}

//saveBalance function not accessible in the menu, automatically reads balance in balance.txt file before the exit
//reads the balance saved before

void readBalance(MyPortfolio* pMyportfolio, char* filename){
	FILE* pFile = 0;

	pFile = fopen(filename, "r");

	if (pFile == 0) {
		printf("file %s did not open\n", filename);
		pMyportfolio->balance = INITIAL_BALANCE;
	} else {
		fscanf(pFile,"%lf",&pMyportfolio->balance);
	}

	if (pFile) fclose(pFile);
}

//worth function calculates overall worth of portfolio for user's reference

int worth(MyPortfolio* pMyportfolio) {
	double summ = 0;
	int i = 0;
	for (i; i < pMyportfolio->positionsCapacity; i++) {
		summ += pMyportfolio->positions[i].shares*pMyportfolio->positions[i].price;
	}
	printf("Your portfolio's worth at the moment is:%.2lf\n",summ);
}

//reset function resets the whole portfolio, setting all prices to their original value, setting shares amount to 0 for all tickers
//and sets the balance to original value (20000)

int reset(MyPortfolio* pMyportfolio) {
	FILE* pFile = 0;
	char* filename = "mystocks.txt";
	int k = 0;
	printf("You are about to reset your whole portfolio\n");
	printf("All prices will be set to default, shares set to 0 and balance will be set to default\n");
	printf("Would you like to proceed? (Y or N)\n");
	char answer = 0;
	scanf(" %c", &answer);
	answer = toupper(answer);
	if (answer == 'Y') {
		pMyportfolio->balance = INITIAL_BALANCE;
		pFile = fopen(filename, "r");
		if (pFile == 0) {
			printf("file %s did not open\n", filename);
			return;
		}
		while (fscanf(pFile, "%s %lf", pMyportfolio->positions[k].ticker,
			&(pMyportfolio->positions[k].price))> 0 &&
			k<pMyportfolio->positionsCapacity) {

			pMyportfolio->positions[k].shares = 0.0;
			k++;
		}
		pMyportfolio->positionsSize = k;
		if (pFile) fclose(pFile);
		printf("Reset complete\n");
	} else {
		printf("The reset has been canceled\n");
	}
}

//currentPrice checks the current price of ticker of choice or all tickers at once

int currentPrice(MyPortfolio* pMyportfolio) {
	int ticker = 0;
	double price = 0;
	printf("You chose to check prices\n");
	printf("Please, choose the ticker you would like to know the price of:\n");
	for (int i = 0; i < pMyportfolio->positionsSize; i++) {
		printf("%d.%s\n", i + 1, pMyportfolio->positions[i].ticker);
	}
	printf("6.All stocks\n");
	printf("Press 7 to cancel and return to main menu\n");
	scanf("%d", &ticker);
	switch (ticker) {
	case 1:
		price = getSimulatedPrice(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker);
		printf("The price of %s is %.2lf\n", pMyportfolio->positions[ticker - 1].ticker, price);
		break;
	case 2:
		price = getSimulatedPrice(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker);
		printf("The price of %s is %.2lf\n", pMyportfolio->positions[ticker - 1].ticker, price);
		break;
	case 3:
		price = getSimulatedPrice(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker);
		printf("The price of %s is %.2lf\n", pMyportfolio->positions[ticker - 1].ticker, price);
		break;
	case 4:
		price = getSimulatedPrice(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker);
		printf("The price of %s is %.2lf\n", pMyportfolio->positions[ticker - 1].ticker, price);
		break;
	case 5:
		price = getSimulatedPrice(pMyportfolio, pMyportfolio->positions[ticker - 1].ticker);
		printf("The price of %s is %.2lf\n", pMyportfolio->positions[ticker - 1].ticker, price);
		break;
	case 6:
		for (int i = 0; i < pMyportfolio->positionsSize; i++) {
			price = getSimulatedPrice(pMyportfolio, pMyportfolio->positions[i].ticker);
			printf("%s %.2lf\n",pMyportfolio->positions[i].ticker,price);
		}
		break;
	case 7:
		printf("The operation was canceled\n");
		break;
	default:
		printf("You chose the wrong option, operation canceled\n");
		break;
	}
}