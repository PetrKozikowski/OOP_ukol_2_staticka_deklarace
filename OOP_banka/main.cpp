#include <iostream>
#include "client.h"
#include "Account.h"
#include "Bank.h"

using namespace std;


int main()
{
	
	const int NAME_COUNT = 10;
	const double INTEREST_RATE = 1.5;
	const double INTEREST_RATE_ALL = 5.;
	bool st;

	string prijmeni[NAME_COUNT] = {
		"Bjornsson",
		"Hall",
		"Shaw",
		"Stoltman",
		"Carter",
		"Kramer",
		"Jagger",
		"Jenkins",
		"Jones",
		"Jackson"
	};
		
	string jmeno[NAME_COUNT] = {
		"Peter",
		"Curtis",
		"Frank",
		"John",
		"Radim",
		"Mark",
		"Ferdinand",
		"Robert",
		"Ethan",
		"Ramon"
	};

	const int b1_clients_count = NAME_COUNT * NAME_COUNT + 2;
	const int b1_accounts_count = NAME_COUNT * NAME_COUNT + 2;
	Client* client1, * client2, * client3, * client4;
	Account* account1, * account2, * account3, * account4;

	Bank* bank1 = new Bank{ b1_clients_count, b1_accounts_count };
	// Vytvoøení sta klientù a sta úètù.
	cout << "*** Test statickych promennych ***" << endl;
	for (int i = 0; i < NAME_COUNT; i++)
	{
		if (i == 2)
		{
			i = i * 2 / 2;

		}
		client2 = nullptr;
		for (int j = 0; j < NAME_COUNT; j++)
		{
			string s1 = jmeno[j] + ' ' + prijmeni[i];
			string s2 = jmeno[(j + 1) % 10] + ' ' + prijmeni[i];
			client1 = bank1->CreateClient(1000 + 10 * i + j, s1);
			if (10 * i + j != 0)
			{
				 bank1->CreateAccount(50000 + 10 * i + j, client1, client2, INTEREST_RATE + (double)j/10 );
			}
			else
			{
				 bank1->CreateAccount(50000 + 10 * i + j, client1, INTEREST_RATE + (double)j/10 );
			}
			client2 = client1;
		}

	}
	/*cout << endl;
	cout << "*** Pokus o vytvoreni uctu do plneho seznamu ***" << endl;
	account2 = bank1->CreateAccount(5, client1);
	
	cout << endl;
	cout << "*** Pokus o vlozeni klienta do plneho seznamu ***" << endl;
	client2 = bank1->CreateClient(5, "Petr Kozikowski");*/

	// Testování funkce GetClient
	cout << endl;
	cout << "*** Testovani funkce GetCode ***" << endl;
	client1 = bank1->GetClient(1050);
	cout << "client1 name: " << client1->GetName() << "  client1 code: " << client1->GetCode() << endl; 

	// Testování funkce GetAccount
	cout << endl;
	cout << "*** Testovani funkce GetAccount ***" << endl;
	account1  = bank1->GetAccount(50050);
	if (account1->GetOwner() != nullptr && account1->GetPartner() != nullptr)
	{
		cout << "account1 owner: " << account1->GetOwner()->GetName() << "  account1 partner: " << account1->GetPartner()->GetName() << endl;
		cout << "account1 number: " << account1->GetNumber() << "  account1 balance: " << account1->GetBalance() << "  account1 interestrate: " << account1->GetInterestRate() << endl;
	}
	cout << "*** Vkladame castku 1000 ***" << endl;
	account1->Deposit(1000.);
	cout << "*** Lze vybrat 500? ***" << endl;
	st = account1->CanWithdraw(500.);
	cout << "*** Lze vybrat 1500? ***" << endl;
	st = account1->CanWithdraw(1500.);
	cout << "*** Pokus o vyssi vyber - 1500 ***" << endl;
	st = account1->Withdraw(1500.);
	cout << "*** Pokus o vyber - 700 ***" << endl;
	st = account1->Withdraw(700.);
	cout << endl;
	cout << "*** Pridani uroku ***" << endl;
	Account::SetInterestRateAll(INTEREST_RATE_ALL);
	cout << "Vychozi urokova sazba je: " << Account::GetInterestRateAll() << endl;
	bank1->AddInterest();
	cout << "Stav uctu: " << account1->GetBalance() << endl;

	client3 = bank1->CreateClient(3000, "Peter Swanson");
	account3 = bank1->CreateAccount(60000, client3, nullptr, INTEREST_RATE);
	account3->Deposit(1000.);
	
	client4 = bank1->CreateClient(3001, "Charles Swanson");
	account4 = bank1->CreateAccount(60001, client4, nullptr, 0);
	account4->Deposit(1000.);

	cout << "Stav uctu 1 pred vlozenim uroku: " << account3->GetBalance() << endl;
	cout << "Stav uctu 2 pred vlozenim uroku: " << account4->GetBalance() << endl;

	bank1->AddInterest();

	cout << "Stav uctu 1 po pripocteni klientskeho uroku 1,5%: " << account3->GetBalance() << endl;
	cout << "Stav uctu 2 po pripocteni vychoziho uroku 5%: " << account4->GetBalance() << endl;

 	/*cout << "*** Pokus o vytvoreni uctu do plneho seznamu ***" << endl;
	account2 = bank1->CreateAccount(5, client1);

	cout << endl;
	cout << "*** Pokus o vlozeni klienta do plneho seznamu ***" << endl;
	client2 = bank1->CreateClient(5, "Petr Kozikowski");*/

	delete bank1;



	return 0;

}