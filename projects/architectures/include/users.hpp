#ifndef USERS_HPP
#define USERS_HPP

#include <string>
#include <iostream>

// Can add roles and UML for later
class User {
private:
    std::string name;
    int balance;

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

    // Overloading the << operator to print user details
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    ~User();
};

#endif // USERS_HPP
