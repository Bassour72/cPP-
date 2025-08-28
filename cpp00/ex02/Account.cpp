#include "Account.hpp"
// Static member initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_year = 0;
int Account::_month = 0;
int Account::_day = 0;
int Account::_minutes = 0;
int Account::_hours = 0;
int Account::_seconds = 0;
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
    return _nbAccounts; 
}
int Account::getTotalAmount(void) 
{ 
    return _totalAmount; 
}
int Account::getNbDeposits(void) 
{ 
    return _totalNbDeposits; 
}
int Account::getNbWithdrawals(void) 
{ 
    return _totalNbWithdrawals; 
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
    return _amount;
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
    _year = datetime.tm_year + 1900;
    _month = datetime.tm_mon + 1;
    _day = datetime.tm_mday;
    _seconds = datetime.tm_sec;
	_hours =datetime.tm_hour;
	_minutes = datetime.tm_min;
    Print_date_DDMMYYYY();
}
void Account::printWithZero(int value) 
{
    if (value < 10) 
        std::cout << '0';
    std::cout << value;
}

void Account::Print_date_DDMMYYYY(void)
{
    std::cout << "[" << _year;
    printWithZero(_month);
    printWithZero(_day);
    std::cout << "_";
    printWithZero(_hours);
    printWithZero(_minutes);
    printWithZero(_seconds);
    std::cout << "]";
}

