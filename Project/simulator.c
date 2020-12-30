#include "simulator.h"

double getSimulatedPrice(MyPortfolio* pMyPortfolio, char* ticker) {
	int i;
	double perturbation = 0;
	double multiplier = 0;
	double currentPrice;
	Position* pPosition;
	pPosition = findStock(pMyPortfolio, ticker);
	currentPrice = pPosition->price;
	perturbation = 2 / currentPrice;

	multiplier = ((double) rand())/RAND_MAX*perturbation;
	multiplier -= perturbation / 2;
	multiplier += 1;

	currentPrice *= multiplier;

	//printf("current Price: %lf \n", currentPrice);

	return currentPrice;
}