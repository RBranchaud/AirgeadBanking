//     Ryan Branchaud 
//     Project Two: Airgead Banking
//     CS-210-T1115 Programming Languages 22EW1
//     10/01/2022

#pragma once
#include <iostream>     // include to display cout to screen
#include <iomanip>     // include to format output
#include "AirgeadBanking.h"     // include header to supply definitions and declarations

using namespace std;

class ScreenDisplay : public AirgeadBanking {

public:

	void displayMenu();

	void wDeposits();

	void wOutDeposits();

	void verificationMenu();

private:

	int i;

	int input = 3;

	float openAmnt;

	float openInvestment;

	float depositMonthly;

	float annualInt;

	float rate;

	float bal;

	float endTotal;

	int yrs;

	bool onInputScreen = true;

};