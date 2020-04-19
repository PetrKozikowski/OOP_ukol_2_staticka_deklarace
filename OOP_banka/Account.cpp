#include <iostream>
#include <string>
#include "client.h"
#include "Account.h"


using namespace std;

double Account::interestRateAll = 0;
int Account::accountsCount = 0;
 
Account::Account()
{
	Account(0, nullptr, nullptr, 0);
}


Account::Account(int n, Client *c)
{
	Account(n, c, nullptr, 0);
}


Account::Account(int n, Client* c, double ir)
{
	Account(n, c, nullptr, 0);
}

Account::Account(int n, Client* c, Client* p)
{
	Account(n, c, p, 0);
}

Account::Account(int n, Client* c, Client* p, double ir)
{
	number = n;
	owner = c;
	partner = p;
	interestRate = ir;
	accountsCount++;
	cout << "Pocet uctu je: " << accountsCount << endl;
}

Account::~Account()
{
	accountsCount--;
}

int Account::GetNumber()
{
	return number;
}

Client* Account::GetOwner()
{
	return owner;
}

Client* Account::GetPartner()
{
	return partner;
}

double Account::GetInterestRate()
{
	return interestRate;
}

double Account::GetBalance()
{
	return balance;
}

bool Account::CanWithdraw(double a)
{
	if (a > balance)
	{
		cout << "Nedostatek penez!" << " Stav uctu: " << balance << endl;
		return false;
	}
	cout << "Muzes vybrat: " << balance << endl;
	return true;
}

void Account::Deposit(double a)
{
	balance += a;
	cout << "Vlozeno: " << a << " Stav uctu: " << balance << endl;
}

bool Account::Withdraw(double a)
{
	if (CanWithdraw(a) == true)
	{
		balance -= a;
		cout << "Vybrano: " << a << " Stav uctu: " << balance << endl;
		return true;
	}
	cout << "Nelze vybrat!" << " Stav uctu: " << balance << endl;
	return false;
}

void Account::AddInterest()
{
	if (interestRate == 0)
	{
		balance += balance * interestRateAll / 100;
	}
	else
	{
		balance += balance * interestRate / 100;
	}
}

int Account::GetAccountsCount()
{
	return accountsCount;
}


void Account::SetInterestRateAll(double intRate)
{
	interestRateAll = intRate;
}

double Account::GetInterestRateAll()
{
	return interestRateAll;
}



