// @author    Clément Vidon
// @created   230324 11:42:14  by  clem@spectre
// @modified  230419 18:43:44  by  clem@spectre
// @filename  PhoneBook.cpp

#include <cstdio>
#include <ctime>
#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*  ACCESSORS
------------------------------------------------- */

int Account::getNbAccounts( void ) {
  return _nbAccounts;
}

int Account::getTotalAmount( void ) {
  return _totalAmount;
}

int Account::getNbDeposits( void ) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
  _displayTimestamp();
  std::cout << " accounts:" << getNbAccounts();
  std::cout << ";total:" << getTotalAmount();
  std::cout << ";deposits:" << getNbDeposits();
  std::cout << ";withdrawals:" << getNbWithdrawals();
  std::cout << std::endl;
  return;
}

/*  CONSTRUCTOR DESTRUCTOR
------------------------------------------------- */

Account::Account( void )
  : _accountIndex( _nbAccounts ),
    _amount( 0 ),
    _nbDeposits( 0 ),
    _nbWithdrawals( 0 ) {
  ++_nbAccounts;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";created";
  std::cout << std::endl;
  return;
}

Account::Account( int initial_deposit )
  : _accountIndex( _nbAccounts ),
    _amount( initial_deposit ),
    _nbDeposits( 0 ),
    _nbWithdrawals( 0 ) {
  ++_nbAccounts;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";created";
  std::cout << std::endl;
  return;
}

Account::~Account( void ) {
  --_nbAccounts;
  _totalAmount -= _amount;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";closed";
  std::cout << std::endl;
  return;
}

/*  MEMBER FUNCTIONS
------------------------------------------------- */

void Account::_displayTimestamp( void ) {
  char buf[18];

  std::time_t ts = std::time( NULL );
  std::strftime( buf, sizeof( buf ), "[%Y%m%d_%H%M%S]", std::localtime( &ts ) );
  std::cout << buf;
  return;
}

void Account::makeDeposit( int deposit ) {
  if( deposit >= 0 ) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits += _nbDeposits;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
  }
  return;
}

bool Account::makeWithdrawal( int withdrawal ) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount;
  std::cout << ";withdrawal:";
  if( checkAmount() && _amount >= withdrawal ) {
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
    return true;
  }
  std::cout << "refused" << std::endl;
  return false;
}

int Account::checkAmount( void ) const {
  return ( _amount > 0 );
}

void Account::displayStatus( void ) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";deposits:" << _nbDeposits;
  std::cout << ";withdrawals:" << _nbWithdrawals;
  std::cout << std::endl;
  return;
}
