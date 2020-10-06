#include "Account.h"

class Checkings : public Account
{
private:
	double c_balance = 0;

public:
	void setBalance(double deposit);
	double getBalance() const;
	void setWithdraw();
	void setDeposit();
	double getTransfer();
};
