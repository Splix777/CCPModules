/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalazar <fsalazar@student.42madrid.com:>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:43:42 by fsalazar          #+#    #+#             */
/*   Updated: 2023/09/12 14:43:43 by fsalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
int Account::checkAmount(void) const { return Account::_amount; }

void    Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void)
{
    time_t  fulltime;
    struct tm * timeinfo;

    time(&fulltime);
    timeinfo = localtime(&fulltime);
    std::cout << "[" << timeinfo->tm_year + 1900;
    if (timeinfo->tm_mon + 1 < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mon + 1;
    if (timeinfo->tm_mday < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mday << "_";
    if (timeinfo->tm_hour < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_hour << "";
    if (timeinfo->tm_min < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_min << "";
    if (timeinfo->tm_sec < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_sec << "] ";  
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
    this->_amount += deposit;
    _totalAmount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    return (true);
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account(void)
{
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount = 0;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}
