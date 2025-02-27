
/***********************
	Aaron E. Befus
	CS 210
	Project 2
	2/5/2025
************************/

#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iomanip>
#include <iostream>
#include <sstream>

class Investment
{
private:
	double	m_initialAmount;
	double	m_monthlyDeposit;
	double	m_interestRate;
	int		m_numYears;

public:
	Investment();

	void printReport(bool withMonthly);

	void setInitialAmount(double t_initialAmount);
	double getInitialAmount();
	
	void setMonthlyDeposit(double t_monthlyDeposit);
	double getMonthlyDeposit();
	
	void setInterestRate(double t_interestRate);
	double getInterestRate();

	void setNumYears(int t_numYears);
	int getNumYears();	
};

#endif
