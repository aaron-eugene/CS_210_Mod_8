
/***********************
	Aaron E. Befus
	CS 210
	Project 2
	2/5/2025
************************/

#include <iomanip>
#include <iostream>

#include "console_effects.h"
#include "investment.h"

using namespace std;

// Works in conjunction with Invest object to assign its values
void dataInput(Investment& investment);

// Input validation helper functions
double getValidDouble(const string& prompt);
int getValidInt(const string& prompt, int rangeLow, int rangeHigh);

// Application exit prompt
bool exitApp();


int main()
{
	// Set console text to bright green
	ConsoleEffects::greenText();

	// Set floating-point precision for console ouptut
	cout << fixed << setprecision(2);

	Investment investment;

	// Application loop
	while (true)
	{
		// Begin with data input screen
		dataInput(investment);

		ConsoleEffects::clearConsole();

		// Print report of investment with no monthly deposits
		investment.printReport(false);

		// Print report of investment with monthly deposits
		investment.printReport(true);

		// Prompt user to enter new investment or quit
		if (exitApp())
		{
			cout << "\nExiting application..." << endl;
			break;
		}

		ConsoleEffects::clearConsole();
	}

	// Reset console color back to white
	ConsoleEffects::whiteText();

	return 0;
}

// Data input screen - validate input and print
void dataInput(Investment& investment)
{
	// Print the menu header
	cout << "\n" << setfill('*') << setw(43) << "\n";
	cout << setw(15) << "" << " Data Input " << setw(15) << "" << endl;

	// Gather initial investment amount, print it, and update investment object
	string prompt = "Initial Investment Amount: ";
	double initialAmount = getValidDouble(prompt);

	cout << prompt << "$" << initialAmount << endl;
	investment.setInitialAmount(initialAmount);

	// Gather monthly deposit amount, print it, and update investment object
	ConsoleEffects::clearCurrentLine();
	prompt = "Monthly Deposit: ";
	double monthlyDeposit = getValidDouble(prompt);
	
	cout << prompt << "$" << monthlyDeposit << endl;
	investment.setMonthlyDeposit(monthlyDeposit);

	// Gather annual interest rate, print it, and update investment object
	ConsoleEffects::clearCurrentLine();
	prompt = "Annual Interest: ";
	double interestRate = getValidDouble(prompt);
	
	cout << prompt << "%" << interestRate << endl;
	investment.setInterestRate(interestRate);

	// Gather investment duration, print it, and update investment object
	ConsoleEffects::clearCurrentLine();
	prompt = "Number of years: ";
	int numYears = getValidInt(prompt, 1, 100);

	cout << prompt << numYears << endl;
	investment.setNumYears(numYears);
	
	// Prompt user to continue app
	ConsoleEffects::clearCurrentLine();
	cout << "Press ENTER key to continue...";
	char c = getchar();
}

double getValidDouble(const string& prompt)
{
	double value;
	double epsilon = 1e-9;

	while (true)
	{
		cout << prompt;
		cin >> value;

		// Check for bad input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');

			ConsoleEffects::clearCurrentLine();
			cout << "Error: Please enter a valid amount";
			ConsoleEffects::moveUpLine();
			ConsoleEffects::clearCurrentLine();
		}
		// Check for negative values
		else if (value < -epsilon)
		{
			cin.ignore(1024, '\n');

			ConsoleEffects::clearCurrentLine();
			cout << "Error: Please enter a non-negative amount";
			ConsoleEffects::moveUpLine();
			ConsoleEffects::clearCurrentLine();
		}
		else
		{
			cin.ignore(1024, '\n');

			ConsoleEffects::moveUpLine();
			ConsoleEffects::clearCurrentLine();
			return value;
		}
	}
}

int getValidInt(const string& prompt, int rangeLow, int rangeHigh)
{
	int value;

	while (true)
	{
		cout << prompt;
		cin >> value;

		// Check for bad input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');

			ConsoleEffects::clearCurrentLine();
			cout << "Error: Please enter a valid amount";
			ConsoleEffects::moveUpLine();
			ConsoleEffects::clearCurrentLine();
		}
		// Check range
		else if ((value < rangeLow) || (value > rangeHigh))
		{
			cin.ignore(1024, '\n');
			
			ConsoleEffects::clearCurrentLine();
			cout << "Error: Please enter a value within the range ";
			cout << "(" << rangeLow << " - " << rangeHigh << ")";
			ConsoleEffects::moveUpLine();
			ConsoleEffects::clearCurrentLine();
		}
		else
		{
			cin.ignore(1024, '\n');

			ConsoleEffects::moveUpLine();
			ConsoleEffects::clearCurrentLine();
			return value;
		}
	}
}

// Application exit prompt
bool exitApp()
{
	cout << "\nEnter 'n' to begin new investment, or 'q' to exit application: ";
	char userChoice = '\0';
	bool result = true;

	while (true)
	{
		cin >> userChoice;
		
		// User wants to exit application
		if ((userChoice == 'q') || (userChoice == 'Q'))
		{;
			break;
		}
		// User wants to coninue using app
		else if ((userChoice == 'n') || (userChoice == 'N'))
		{
			result = false;
			break;
		}
		// Bad input
		else
		{
			ConsoleEffects::clearCurrentLine();
			ConsoleEffects::moveUpLine();
			ConsoleEffects::clearCurrentLine();
			cout << "Error: invalid input.\n";
			cout << "Please enter 'n' to begin new investment, or 'q' to exit application: ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}

	return result;
}
