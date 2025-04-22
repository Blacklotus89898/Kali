#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>
#include "users.hpp"

// Enum for account types
enum AccountType { CHECKING, SAVINGS, LOAN };

class Account {
private:
    int balance;
    int accountNumber;
    int interestRate;
    AccountType accountType;

public:
    // Constructor
    Account(int balance, int accountNumber, int interestRate, AccountType accountType);

    // Getter and Setter for balance
    int getBalance() const;
    void setBalance(int newBalance);

    // Getter and Setter for accountNumber
    int getAccountNumber() const;
    void setAccountNumber(int newAccountNumber);

    // Getter and Setter for interestRate
    int getInterestRate() const;
    void setInterestRate(int newInterestRate);

    // Getter and Setter for accountType
    AccountType getAccountType() const;
    void setAccountType(AccountType newAccountType);

    // Clone method to create a copy of the current Account
    Account* clone();

    // Overloading the << operator to print Account details
    friend std::ostream& operator<<(std::ostream& os, const Account& Account);

    // Destructor
    ~Account();
};

class AccountBuilder {
    private:
        int balance = 0;
        int accountNumber = 0;
        int interestRate = 0;
        AccountType accountType = CHECKING;
    
    public:
        AccountBuilder& setBalance(int balance);
        AccountBuilder& setAccountNumber(int accountNumber);
        AccountBuilder& setInterestRate(int interestRate);
        AccountBuilder& setAccountType(AccountType accountType);
    
        Account build();
    };
#endif 
