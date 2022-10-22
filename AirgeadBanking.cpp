//     Ryan Branchaud 
//     Project Two: Airgead Banking
//     CS-210-T1115 Programming Languages 22EW1
//     10/01/2022#include <iostream>

#include "AirgeadBanking.h"     // include header to supply definitions and declarations

void AirgeadBanking::SetInitAmnt(float initInvest) {     // Initial amount setter
	initAmnt = initInvest;
}

float AirgeadBanking::GetInitAmnt() {     // Initial amount getter
	return initAmnt;
}

void AirgeadBanking::SetMonthlyDep(float deposit) {     // Monthly deposit setter
	monthlyDep = deposit;
}

float AirgeadBanking::GetMonthlyDep() {     // Monthly deposit getter
	return monthlyDep;
}

void AirgeadBanking::SetAnnualInt(float interest) {     // Annual interest setter
	annualInt = interest;
}

float AirgeadBanking::GetAnnualInt() {     // Annual interest getter
	return annualInt;
}

void AirgeadBanking::SetNumberYrs(float years) {     // Number of years setter
	numberYrs = years;
}

int AirgeadBanking::GetNumberYrs() {     // Number of years getter
	return numberYrs;
}

float AirgeadBanking::GetClosingBal() {     // Closing balance getter
	return ((GetInitAmnt() + GetMonthlyDep()) + intRate());
}

float AirgeadBanking::intRate() {     // Monthly interest getter
	rate = ((GetInitAmnt() + GetMonthlyDep()) * (annualInt / 100.00) / 12.00);
	return rate;
}

int AirgeadBanking::YrsToMonths() {     // To get months from years
	months = GetNumberYrs() * 12;
	return months;
}