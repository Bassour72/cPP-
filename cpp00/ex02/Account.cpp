#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
// ---------------------- [ Constructor ] ----------------------//
Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}
Account::Account(int initial_deposit, int amount)
{
    _amount = initial_deposit + amount;
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

// ---------------------- [ Destructor ] -----------------------//
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

// ------------------- [ Static Getters ] ----------------------//
int Account::getNbAccounts(void) 
{ 
    return (_nbAccounts); 
}
int Account::getTotalAmount(void) 
{ 
    return (_totalAmount); 
}
int Account::getNbDeposits(void) 
{ 
    return (_totalNbDeposits); 
}
int Account::getNbWithdrawals(void) 
{ 
    return (_totalNbWithdrawals); 
}
// ------------------ [ Display Bank Info ] -------------------//
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

// -------------------- [ Deposit Function  ] ------------------//
void Account::makeDeposit(int deposit)
{
    if (deposit <= 0) 
        return;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

// ------------------ [ Withdrawal Function ] -----------------//
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";

    if (withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }

    std::cout << withdrawal;
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;

    return (true);
}




// --------------------- [ Check Amount  ] ---------------------//
int Account::checkAmount(void) const
{
    return (_amount);
}

// -------------------- [ Display Status ] --------------------//
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

// ------------------ [ Timestamp Functions  ]-----------------//
void Account::_displayTimestamp(void)
{
    time_t timestamp = time(NULL);
    tm datetime = *localtime(&timestamp);

    int year = datetime.tm_year + 1900;
    int month = datetime.tm_mon + 1;
    int day = datetime.tm_mday;
    int hours = datetime.tm_hour;
    int minutes = datetime.tm_min;
    int seconds = datetime.tm_sec;

    std::cout << "[" << year;

    if (month < 10) 
        std::cout << '0';
    std::cout << month;

    if (day < 10) 
        std::cout << '0';
    std::cout << day << "_";

    if (hours < 10) 
        std::cout << '0';
    std::cout << hours;

    if (minutes < 10) 
        std::cout << '0';
    std::cout << minutes;

    if (seconds < 10) 
        std::cout << '0';
    std::cout << seconds;

    std::cout << "]";
}


