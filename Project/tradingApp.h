#ifndef APP_H
#define APP_H

#include "common.h"
#include "simulator.h"
#include "trading.h"

//functions
void UI(MyPortfolio* pMyPortfolio);
int menu(MyPortfolio* pMyPortfolio);
int buyUI(MyPortfolio* pMyportfolio);
int sellUI(MyPortfolio* pMyportfolio);
void saveBalance(MyPortfolio* pMyportfolio, char* filename);
void readBalance(MyPortfolio* pMyportfolio, char* filename);
int worth(MyPortfolio* pMyportfolio);
int reset(MyPortfolio* pMyportfolio);

#endif