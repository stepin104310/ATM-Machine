/*---------AUTOMATED TELLER MACHINE----------*/

#include <iostream>
#include <string>
#include "Account.h"
#include "Checkings.h"
#include "Savings.h"
using namespace std;

int AccountDetails[] = {
	1234,
	1998,
	100,
	600,
};

bool validatePin(int pin)
{
	if (pin == AccountDetails[0])
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Functions */

int mainMenu()
{
	int choice = 0;
	cout << "\n-----------------------------" << endl;
	cout << "|What would you like to do? |" << endl;
	cout << "-----------------------------" << endl;
	cout << "| 1. Deposit                |" << endl;
	cout << "| 2. Withdraw               |" << endl;
	cout << "| 3. Check Balance          |" << endl;
	cout << "| 4. Transfer Money         |" << endl;
	cout << "| 5. [Exit]                 |" << endl;
	cout << "-----------------------------" << endl;

	cin >> choice;
	return choice;
}

int main()
{
	//Object Instantiation
	Account accObj;
	Checkings checkObj;
	Savings savObj;

	int pin;
	cout << "Welcome to Bank of Programming.\n\tPlease enter your pin number to access your account:" << endl;
	do
	{
		cin >> pin;

		if (validatePin(pin))
		{

			accObj.setAccountName("Sachin", "Kumar");
			string fullName = accObj.getAccountName();

			cout << "-----------------------------" << endl;
			cout << "|    Welcome, " << fullName << "    |" << endl;
			cout << "-----------------------------" << endl;

			bool isNotFinished = true;
			int accountChoice = -1;

			do
			{
				switch (mainMenu())
				{
					//Calling Deposit Function
				case 1:
					cout << "-------------------------------------------------" << endl;
					cout << "| Which account would you like to deposit into? |" << endl;
					cout << "-------------------------------------------------" << endl;
					cout << "| 1. Checking                                   |" << endl;
					cout << "| 2. Savings                                    |" << endl;
					cout << "-------------------------------------------------" << endl;

					cin >> accountChoice;
					switch (accountChoice)
					{
					case 1:
						checkObj.setDeposit();
						break;
					case 2:
						savObj.setDeposit();
						break;
					default:
						cout << "Invalid choice! Please select again." << endl;
						break;
					}

					break;

					// call withdraw
				case 2:
					cout << "-------------------------------------------------" << endl;
					cout << "|       Which account to withdraw from?       |" << endl;
					cout << "-------------------------------------------------" << endl;
					cout << "| 1. Checking                                   |" << endl;
					cout << "| 2. Savings                                    |" << endl;
					cout << "-------------------------------------------------" << endl;

					cin >> accountChoice;
					switch (accountChoice)
					{ //nested switch case to chose account type
					case 1:
						checkObj.setWithdraw();
						break;
					case 2:
						savObj.setWithdraw();
						break;
					default:
						cout << "Invalid choice! Please select again." << endl;
						break;
					}

					break;
				case 3:

					// call to check balance
					cout << "-------------------------------------------------" << endl;
					cout << "|       Check Account Balance for?              |" << endl;
					cout << "-------------------------------------------------" << endl;
					cout << "| 1. Checking                                   |" << endl;
					cout << "| 2. Savings                                    |" << endl;
					cout << "-------------------------------------------------" << endl;

					cin >> accountChoice;
					switch (accountChoice)
					{
					case 1:
						cout << "Your current Checking balance is $" << checkObj.getBalance();
						break;

					case 2:
						cout << "Your current Savings balance is $" << savObj.getSavingsBalance();
						break;

					default:
						cout << "Invalid choice! Please select again." << endl;
						break;
					}
					break;

				case 4:

					cout << "-------------------------------------------------" << endl;
					cout << "| Select the type of transfer                    |" << endl;
					cout << "-------------------------------------------------" << endl;
					cout << "| 1. Checkings to Savings                        |" << endl;
					cout << "| 2. Savings to Checkings                        |" << endl;
					cout << "-------------------------------------------------" << endl
						 << endl;

					cin >> accountChoice;
					switch (accountChoice)
					{
					case 1:
					{
						double depositTOsav = checkObj.getTransfer();
						savObj.setSavingsBalance(depositTOsav);
						break;
					}
					case 2:
					{
						double depositTOcheck = savObj.getTransfer();
						checkObj.setBalance(depositTOcheck);
						break;
					}
					default:
						cout << " Invalid choice! Please select again." << endl;
					}

					break;

					// Call for EXIT on menu.
				case 5:
					cout << "Thank you for Choosing our Bank! Stay Safe! Stay Healthy!." << endl;
					isNotFinished = false;
					break;

				default:
					cout << "Invalid choice! Please select again." << endl;
					break;
				}

			} while (isNotFinished);
		}
		else
		{
			cout << "Invalid pin. Please enter pin number:" << endl;
		}

	} while (!validatePin(pin));

	system("pause");
	return 0;
}
