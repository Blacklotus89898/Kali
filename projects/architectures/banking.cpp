#include <iostream>
#include <vector>
#include <string>

// Singleton pattern for a banking system
class BankingSystem
{
private:
    static BankingSystem *instance; // pointer to unique instance
    std::vector<std::string> users; // vector to store user names

    // private constructor to prevent instantiation
    BankingSystem() {}

public:
    // public method to get the unique instance or create it
    static BankingSystem *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new BankingSystem();
        }
        return instance;
    }

    // method to add a user
    void addUser(const std::string &userName)
    {
        users.push_back(userName);
        std::cout << "User " << userName << " added to the banking system." << std::endl;
    }

    // method to display all users
    void displayUsers() const
    {
        std::cout << "Users in the banking system:" << std::endl;
        for (const auto &user : users)
        {
            std::cout << "- " << user << std::endl;
        }
    }

    // destructor
    ~BankingSystem()
    {
        std::cout << "BankingSystem instance destroyed." << std::endl;
        delete instance;
    }
};

// Initialize the static member
BankingSystem *BankingSystem::instance = nullptr;