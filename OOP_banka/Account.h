#pragma once
//#include "client.h"

class Account
{
private:
	static int accountsCount;
	int number;
	double balance;
	double interestRate;
	static double interestRateAll;

	Client* owner;
	Client* partner;
public:
	Account();
	Account(int n, Client* c);
	Account(int n, Client* c, double ir);
	Account(int n, Client* c, Client* p);
	Account(int n, Client* c, Client* p, double ir);
	~Account();

	static int GetAccountsCount();
	int GetNumber();
	static void SetInterestRateAll(double intRate);
	static double GetInterestRateAll();
	double GetBalance();
	double GetInterestRate();
	Client *GetOwner();
	Client *GetPartner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();

};

