/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:15:07 by pablo             #+#    #+#             */
/*   Updated: 2025/09/03 12:22:50 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include "ctime"
#include "iomanip"

    int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
   return ( Account::_nbAccounts ); 
}
int Account::getTotalAmount()
{
    return(Account::_totalAmount);
}
int Account::getNbDeposits()
{
    return( Account::_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
    return(Account::_totalNbWithdrawals);
}
int Account::checkAmount() const
{
    return(this->_amount);
}
Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "amount:" << this->_amount << ";" ;
    std::cout << "created" << std::endl;
}
Account::~Account()
{
    Account::_displayTimestamp();
    std::cout <<"index:" << this->_accountIndex << ";";
    std::cout <<"amount:" << this->_amount << ";";
    std::cout <<"closed" << std::endl;
}
void Account::_displayTimestamp()
{
   std::time_t now = std::time(0);
   std::tm *local = std::localtime(&now);
   std::cout << "[";
   std::cout << std::setw(4) << std::setfill('0') << (local->tm_year + 1900);
   std::cout << std::setw(2) << std::setfill('0') << (local->tm_mon + 1);
   std::cout << std::setw(2) << std::setfill('0') << (local->tm_mday);
   std::cout << "_";
   std::cout << std::setw(2) << std::setfill('0') << (local->tm_hour);
   std::cout << std::setw(2) << std::setfill('0') << (local->tm_min);
   std::cout << std::setw(2) << std::setfill('0') << (local->tm_sec);
   std::cout << "] ";
}
void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals<< std::endl;
}
void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout <<"index:" << this->_accountIndex << ";";
    std::cout <<"amount:" << this->_amount << ";";
    std::cout <<"deposits:" << this->_nbDeposits <<";";
    std::cout <<"withdrawals:" << this->_nbWithdrawals << std::endl;
}
void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout <<"index:" << this->_accountIndex << ";";
    std::cout <<"p_amount:" << this->_amount << ";"; 
    std::cout <<"deposit:" << deposit <<";";
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout <<"index:" << this->_accountIndex << ";";
    std::cout <<"p_amount:" << this->_amount << ";";
    if(withdrawal > this->_amount || withdrawal < 0)
    {
        std::cout<<"withdrawal:refused" << std::endl;
        return(false);
    }
    std::cout<<"withdrawal:" << withdrawal <<";";
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -=withdrawal;
    Account::_totalNbWithdrawals++;
    std::cout<<"amount:"<<this->_amount <<";";
    std::cout<<"nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return(true);   
}

