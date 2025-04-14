#include "../include/banking.hpp"
#include "../include/users.hpp"

// Initialize the static member
BankingSystem *BankingSystem::instance = nullptr;

// Private constructor
BankingSystem::BankingSystem() {}

// Public method to get the unique instance or create it
BankingSystem *BankingSystem::getInstance()
{
    if (instance == nullptr)
    {
        instance = new BankingSystem();
    }
    return instance;
}

// Method to add a user
User BankingSystem::addUser(const std::string &userName, int balance = 0)
{
    User newUser(userName, balance);
    users.push_back(newUser);
    std::cout << "User " << userName << " added to the banking system." << std::endl;
    return newUser;
}

// Method to display all users
void BankingSystem::displayUsers() const
{
    std::cout << "Users in the banking system:" << std::endl;
    for (const auto &user : users)
    {
        std::cout << "- " << user << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const BankingSystem &bankingSystem)
{
    os << "BankingSystem with users: ";
    for (const auto &user : bankingSystem.users)
    {
        os << user << " ";
    }
    return os;
}

// Destructor
BankingSystem::~BankingSystem()
{
    std::cout << "BankingSystem instance destroyed." << std::endl;
}
