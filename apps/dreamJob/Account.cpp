
#include "Account.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm timeInfo;
    localtime_r(&currentTime, &timeInfo); 
    std::cout << "["
                    << std::setw(4) << std::setfill('0') << timeInfo.tm_year + 1900
                    << std::setw(2) << std::setfill('0') << timeInfo.tm_mon + 1
                    << std::setw(2) << std::setfill('0') << timeInfo.tm_mday
                    << "_"
                    << std::setw(2) << std::setfill('0') << timeInfo.tm_hour
                    << std::setw(2) << std::setfill('0') << timeInfo.tm_min
                    << std::setw(2) << std::setfill('0') << timeInfo.tm_sec
                    << "] ";
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<';';
	std::cout << "total:" << _amount <<';';
	std::cout << "deposits:" << _nbDeposits <<';';
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;

}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts <<';';
	std::cout << "total:" << _totalAmount <<';';
	std::cout << "deposits:" << _totalNbDeposits <<';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return 	_totalNbWithdrawals;
}

int	Account::getNbWithdrawals( void )
{
	return 	_totalNbDeposits;
}
	
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout <<  "index:" << _accountIndex << ";" << "p_amount:" <<  _amount << ";" ;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
		std::cout << "deposit:" << deposit << ";" ;
	std::cout << "amount:" << _amount << ";" << "nb_deposit:"<< _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (checkAmount() >= withdrawal)
	{
		_displayTimestamp();
		std::cout <<  "index:" << _accountIndex << ";" << "p_amount:" <<  _amount << ";" ;
		std::cout << "withdrawal:" << withdrawal << ";"; 
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;		
		std::cout << "amount:" << _amount << ";" << "nb_withdrawals:"<< _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		_displayTimestamp();
		std::cout <<  "index:" << _accountIndex << ";" << "p_amount:" <<  _amount << ";" << "withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount() const
{
	return _amount;
}


Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = Account::getNbAccounts();
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout <<  "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
}


Account::~Account( void )
{
	_displayTimestamp();
	std::cout <<  "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}