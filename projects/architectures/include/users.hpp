#ifndef USERS_HPP
#define USERS_HPP

#include <string>
#include <iostream>
#include <vector>
// #include "accounts.hpp" // circular dependency, need to fix this

class Account;
class AccountBuilder;

// Can add roles and UML for later
class User {
private:
    std::string name;
    int balance;
    int profileId;
    int interestRate;
    std::vector<Account*> accounts;

public:
    User(std::string name, int balance);

    // Getter for name
    std::string getName() const;

    // Setter for name
    void setName(const std::string& newName);

    // Getter for balance
    int getBalance() const;

    // Setter for balance
    void setBalance(int newBalance);


    void addAccount(Account* account); 

    std::vector<Account*>& getAccounts();
    

    // Clone method to create a copy of the current user
    User* clone();

    // Overloading the << operator to print user details
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    ~User();
};

#endif // USERS_HPP
