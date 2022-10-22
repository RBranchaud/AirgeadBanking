//     Ryan Branchaud 
//     Project Two: Airgead Banking
//     CS-210-T1115 Programming Languages 22EW1
//     10/01/2022

#include <iostream>     // include to display cout to screen
#include <Windows.h>     // include to compile for windows
#include "ScreenDisplay.h"     // include header to supply definitions and declarations

using namespace std;

void ScreenDisplay::displayMenu() {

	cout << ":+:::::::::::::::::::::::::::::+:" << endl;
	cout << ":+:::::::: Data Input :::::::::+:" << endl;

	cout << "Initial Investment Amount: " << endl;
	cin >> openInvestment;
	openAmnt = openInvestment;

		if (openInvestment < 0) {
			cout << "Invalid investment amount." << endl;
			displayMenu();
		}

	AirgeadBanking::SetInitAmnt(openInvestment);
	cout << "Monthly Deposit: " << endl;
	cin >> depositMonthly;

		if (depositMonthly < 0) {
			cout << "Invalid deposit amount." << endl;
			displayMenu();
		}

	AirgeadBanking::SetMonthlyDep(depositMonthly);
	cout << "Annual Interest: " << endl;
	cin >> annualInt;

		if (annualInt < 0) {
			cout << "Invalid interest amount." << endl;
			displayMenu();
		}

	AirgeadBanking::SetAnnualInt(annualInt);
	cout << "Number of Years: " << endl;
	cin >> yrs;

		if (yrs < 0) {
			cout << "Invalid number of years." << endl;
			displayMenu();
		}

	AirgeadBanking::SetNumberYrs(yrs);
	verificationMenu();
}

void ScreenDisplay::verificationMenu() {

	cout << ":+:::::::::::::::::::::::::::::+:" << endl;
	cout << ":+:::::::: Data Input :::::::::+:" << endl;

	cout << " " << endl;
	cout << "Initial Investment Amount: $" << AirgeadBanking::GetInitAmnt() << endl;
	cout << "Monthly Deposit: $" << AirgeadBanking::GetMonthlyDep() << endl;
	cout << "Annual Interest: %" << AirgeadBanking::GetAnnualInt() << endl;
	cout << "Number of Years: " << AirgeadBanking::GetNumberYrs() << endl;

	cout << " " << endl;
	cout << ":+:::::::::::::::::::::::::::::+:" << endl;

	cout << " " << endl;
	cout << "Press 1: Everything Looks Accurate!" << endl;
	cout << "Press 2: I Need to Change Something!" << endl;

	while (onInputScreen) {

		cin >> input;

		switch (input) {

		case 1:

			system("cls");
			wOutDeposits();
			wDeposits();
			onInputScreen = false;
			break;

		case 2:

			system("cls");
			displayMenu();
			onInputScreen = false;
			break;

		default:

			cout << " " << endl;
			cout << "Press 1: Everything Looks Accurate!" << endl;
			cout << "Press 2: I Need to Change Something!" << endl;
			onInputScreen = true;

		}
	}
}

void ScreenDisplay::wOutDeposits() {

	cout << ":+::                             Balance and Interest Without Additional Monthly Deposits" << setfill(' ') << setw(33) << "::+:" << endl;
	cout << ":$::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::$:" << endl;

	cout << setfill(' ') << setw(1);
	cout << ":+:: " << setfill(' ') << setw(2) << "Month " << " ]::[ " << setfill(' ') << setw(2) << "Opening Balance $ ";
	cout << "]::[" << setfill(' ') << setw(2) << " Monthly Deposit $ " << "]::[ " << setfill(' ') << setw(3) << "Total $ ";
	cout << "]::[" << setfill(' ') << setw(2) << " Monthly Interest $ " << "]::[ " << setfill(' ') << setw(2) << "Closing Balance $ " << "::+:" << endl;

	cout << ":$::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::$:" << endl;

	for (i = 0; i < AirgeadBanking::YrsToMonths(); ++i) {
		openInvestment = GetInitAmnt();
		rate = ((openInvestment + 0) * (GetAnnualInt() / 100.00) / 12.00);
		bal = openInvestment + rate;

		cout << setprecision(2) << fixed << ":+:: " << setfill(' ') << setw(3) << (i + 1) << "    ]::[ " << setfill(' ') << setw(10) << openInvestment << setfill(' ') << setw(12);
		cout << "]::[" << setfill(' ') << setw(10) << 0 << setfill(' ') << setw(13) << "]::[" << setfill(' ') << setw(7) << (openInvestment + 0) << "  ]::[";
		cout << setfill(' ') << setw(12) << rate << setfill(' ') << setw(12) << "]::[" << setfill(' ') << setw(12) << bal << "       ::+:" << endl;

		SetInitAmnt(bal);
	}

	cout << ":$::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::$:" << endl;

	}

void ScreenDisplay::wDeposits() {

	cout << ":+::                               Balance and Interest With Additional Monthly Deposits" << setfill(' ') << setw(34) << "::+:" << endl;
	cout << ":$::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::$:" << endl;

	cout << setfill(' ') << setw(1);
	cout << ":+:: " << setfill(' ') << setw(2) << "Month " << " ]::[ " << setfill(' ') << setw(2) << "Opening Balance $ ";
	cout << "]::[" << setfill(' ') << setw(2) << " Monthly Deposit $ " << "]::[ " << setfill(' ') << setw(3) << "Total $ ";
	cout << "]::[" << setfill(' ') << setw(2) << " Monthly Interest $ " << "]::[ " << setfill(' ') << setw(2) << "Closing Balance $ " << "::+:" << endl;

	cout << ":$::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::$:" << endl;

	SetInitAmnt(openAmnt);

	for (i = 0; i < AirgeadBanking::YrsToMonths(); ++i) {
		openInvestment = GetInitAmnt();
		rate = ((openInvestment + depositMonthly) * (GetAnnualInt() / 100.00) / 12.00);
		bal = openInvestment + depositMonthly + rate;

		cout << setprecision(2) << fixed << ":+:: " << setfill(' ') << setw(4) << (i + 1) << "   ]::[ " << setfill(' ') << setw(11) << openInvestment << setfill(' ') << setw(11);
		cout << "]::[" << setfill(' ') << setw(12) << depositMonthly << setfill(' ') << setw(11) << "]::[" << setfill(' ') << setw(8) << (openInvestment + depositMonthly) << " ]::[";
		cout << setfill(' ') << setw(12) << rate << setfill(' ') << setw(12) << "]::[" << setfill(' ') << setw(13) << bal << "      ::+:" << endl;

		SetInitAmnt(bal);
	}

	cout << ":$::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::$:" << endl;
	cout << endl;
	cout << "Press 1 to Edit." << endl;
	cout << "Press 2 to Exit." << endl;

	while (onInputScreen == true) {

		cin >> input;

		switch (input) {

		case 1:
			system("cls");
			displayMenu();
			onInputScreen = false;
			break;

		case 2:
			exit(1);

		default:
			cout << "Press 1 to Edit." << endl;
			cout << "Press 2 to Exit." << endl;
			onInputScreen = true;
		}
	}
}
