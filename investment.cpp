
/***********************
	Aaron E. Befus
	CS 210
	Project 2
	2/5/2025
************************/

#include "investment.h"

using namespace std;

// Default constructor - zero-initializes all data
Investment::Investment() :
	m_initialAmount(0.0),
	m_monthlyDeposit(0.0),
	m_interestRate(0.0),
	m_numYears(0)
{
}

// Yearly balance and interest earned 
// bool argument determines whether monthly deposits are considered
void Investment::printReport(bool withMonthly)
{
	// Report Header with and without monthly deposits
	if (withMonthly)
	{
		cout << "\n" << setfill(' ') << setw(7) << "";
		cout << "Balance and Interest With Additional Monthly Deposity";
	}
	else
	{
		cout << "\n" << setfill(' ') << setw(6) << "";
		cout << "Balance and Interest Without Additional Monthly Deposity";
	}

	cout << "\n" << setfill('=') << setw(67) << "" << "\n";
	cout << setfill(' ') << " Year |";
	cout << setw(9) << "" << "Year End Balance" << setw(8) << "";
	cout << "| Year End Earned Interest \n";
	cout << setfill('-') << setw(67) << "" << endl;
	cout << setfill(' ');

	// Stringstream and string for formatted output
	ostringstream oss;
	oss << fixed << setprecision(2);
	string output;

	// Set starting values for investment calculation
	int numYears = getNumYears();
	double currentBalance = getInitialAmount();
	double rate = getInterestRate() / 100.0;
	double interest = 0.0;
	double interestEarned = 0.0;

	// Set monthly deposit amount according to report needed
	double depositedAmount = 0.0;
	if (withMonthly)
	{
		depositedAmount = getMonthlyDeposit();
	}

	for (int i = 1; i <= numYears; ++i)
	{
		// Reset interest earned for the year
		interestEarned = 0.0;

		// Loop 12 months and accrue interest
		for (int j = 1; j <= 12; ++j)
		{
			// Add in monthly deposit
			currentBalance += depositedAmount;

			// Calculate interest earned for the month
			interest = currentBalance * (rate / 12.0);

			// Add compounded interest to running balance
			currentBalance += interest;

			// Add interest to interest earned over the year
			interestEarned += interest;
		}
		
		// Print year
		if (i < 10)
		{
			cout << "   " << i << "  |";
		}
		else if (i < 100)
		{
			cout << "  " << i << "  |";
		}
		else if (i < 1000)
		{
			cout << "  " << i << " |";
		}

		// Create string of dollar sign and balance at year's end
		oss.str("");
		oss << "$" << currentBalance;
		output = oss.str();

		// Print balance right-justified
		cout << setfill(' ') << setw(32) << right << output << " |";

		// Create string of dollar sign and yearly interest accrued
		oss.str("");
		oss << "$" << interestEarned;
		output = oss.str();
		cout << setw(25) << right << output;

		// Horizontal line for table
		cout << "\n" << setfill('-') << setw(67) << "";
		cout << endl;
	}
}

// Getter/settter pair for inital investment amount
void Investment::setInitialAmount(double t_initialAmount)
{
	m_initialAmount = t_initialAmount;
}

double Investment::getInitialAmount()
{
	return m_initialAmount;
}

// Getter/setter pair for monthly deposit amount
void Investment::setMonthlyDeposit(double t_monthlyDeposit)
{
	m_monthlyDeposit = t_monthlyDeposit;
}

double Investment::getMonthlyDeposit()
{
	return m_monthlyDeposit;
}

// Getter/setter pair for annual interest rate of investment
void Investment::setInterestRate(double t_interestRate)
{
	m_interestRate = t_interestRate;
}

double Investment::getInterestRate()
{
	return m_interestRate;
}

// Getter/setter pair for duration of the investment in years
void Investment::setNumYears(int t_numYears)
{
	m_numYears = t_numYears;
}

int Investment::getNumYears()
{
	return m_numYears;
}