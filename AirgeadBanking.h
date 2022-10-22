//     Ryan Branchaud 
//     Project Two: Airgead Banking
//     CS-210-T1115 Programming Languages 22EW1
//     10/01/2022

#pragma once

class AirgeadBanking {

public:

	void SetInitAmnt(float initInvest);     // set initial investment amount

	float GetInitAmnt();     // get initial investment amount

	void SetMonthlyDep(float deposit);     // set monthly deposit

	float GetMonthlyDep();     // get monthly deposit

	void SetAnnualInt(float interest);     // set annual interest

	float GetAnnualInt();     // get annual interest

	void SetNumberYrs(float years);     // set number of years

	int GetNumberYrs();     // get number of years

	float GetClosingBal();     // get closing balance

	float intRate();     // interest rate

	int YrsToMonths();     // years to months

private:

	float initAmnt;     // initial amount

	float monthlyDep;     // monthly deposit

	float annualInt;     // annual interest

	float numberYrs;     // number of years

	float monthlyIntRate;     // monthly interest rate

	float months;  

	float closingBal;     // closing balance

	float rate;
	
	float yrsToMonths;     // years to months

	float input;     // user input

};