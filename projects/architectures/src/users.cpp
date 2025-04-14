#include "../include/users.hpp"

// Constructor
User::User(std::string name, int balance) : name(std::move(name)), balance(balance) {}

// Getter for name
std::string User::getName() const {
    return name;
}

// Setter for name
void User::setName(const std::string& newName) {
    name = newName;
}

// Getter for balance
int User::getBalance() const {
    return balance;
}

// Setter for balance
void User::setBalance(int newBalance) {
    balance = newBalance;
}

// Overloading the << operator to print user details
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User{name: " << user.name << ", balance: " << user.balance << "}";
    return os;
}

// Clone method to create a copy of the current user
User* User::clone() {
    return new User(*this); // Create a new User object as a copy of the current one
}

// Destructor
User::~User() {
    // No dynamic memory to clean up, so the destructor is empty
    std::cout << "User " << name << " destroyed." << std::endl;
}
