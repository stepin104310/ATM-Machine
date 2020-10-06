#include "Account.h"

class Savings : public Account
{
private:
	double s_balance = 0;

public:
	void setSavingsBalance(double Balance);
	double getSavingsBalance() const;
	void setWithdraw();
	void setDeposit();
	double getTransfer();
};
