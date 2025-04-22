#include "../include/accounts.hpp"

// Constructor
Account::Account(int balance, int accountNumber, int interestRate, AccountType accountType)
    : balance(balance), accountNumber(accountNumber), interestRate(interestRate), accountType(accountType) {}

// Getter and Setter for balance
int Account::getBalance() const {
    return balance;
}

void Account::setBalance(int newBalance) {
    balance = newBalance;
}

// Getter and Setter for accountNumber
int Account::getAccountNumber() const {
    return accountNumber;
}

void Account::setAccountNumber(int newAccountNumber) {
    accountNumber = newAccountNumber;
}

// Getter and Setter for interestRate
int Account::getInterestRate() const {
    return interestRate;
}

void Account::setInterestRate(int newInterestRate) {
    interestRate = newInterestRate;
}

// Getter and Setter for accountType
AccountType Account::getAccountType() const {
    return accountType;
}

void Account::setAccountType(AccountType newAccountType) {
    accountType = newAccountType;
}

// Clone method to create a copy of the current Account
Account* Account::clone() {
    return new Account(*this);
}

// Overloading the << operator to print Account details
std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account Number: " << account.accountNumber
       << ", Balance: " << account.balance
       << ", Interest Rate: " << account.interestRate
       << ", Account Type: " << account.accountType;
    return os;
}

// Destructor
Account::~Account() {}

// AccountBuilder methods
AccountBuilder& AccountBuilder::setBalance(int balance) {
    this->balance = balance; // Correctly assign to the member variable
    return *this;
}

AccountBuilder& AccountBuilder::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber; // Correctly assign to the member variable
    return *this;
}

AccountBuilder& AccountBuilder::setInterestRate(int interestRate) {
    this->interestRate = interestRate; // Correctly assign to the member variable
    return *this;
}

AccountBuilder& AccountBuilder::setAccountType(AccountType accountType) {
    this->accountType = accountType; // Correctly assign to the member variable
    return *this;
}

Account AccountBuilder::build() {
    return Account(balance, accountNumber, interestRate, accountType);
}