#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <vector>
#include <string>

#include "users.hpp"

// Singleton pattern for a banking system
class BankingSystem
{
private:
    static BankingSystem *instance; // pointer to unique instance
    // std::vector<User> users; // vector to store user names
    std::vector<User*> users;


    // private constructor to prevent instantiation
    BankingSystem();

public:
    // public method to get the unique instance or create it
    static BankingSystem *getInstance();

    // method to add a user
    User* addUser(const std::string &userName, int balance);

    // void addUser(const User &user);
    void addUser(User* user);
    

    // method to display all users
    void displayUsers() const;

    friend std::ostream& operator<<(std::ostream& os, const BankingSystem& bankingSystem);


    // destructor
    ~BankingSystem();
};

#endif // BANKING_H
