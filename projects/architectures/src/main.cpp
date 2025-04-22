#include <iostream>
#include "../include/banking.hpp"
#include "../include/accounts.hpp"

using namespace std;

// Project entry point
int main() {
    // Singleton pattern for banking system
    cout << "Initiating banking system..." << endl;

    BankingSystem* bankingSystem = BankingSystem::getInstance();

    cout << "Banking system status: " << *bankingSystem << endl;

    // Add a user to the banking system
    User* alice = bankingSystem->addUser("Alice", 1000);
    cout << "User Alice: " << *alice << endl;

    cout << "Banking system status: " << *bankingSystem << endl;

    // Cloning Alice for prototype pattern
    User* aliceClone = alice->clone();
    aliceClone->setName("Alice Clone");
    bankingSystem->addUser(aliceClone);

    cout << "Cloned User Alice: " << *aliceClone << endl;
    cout << "Banking system status: " << *bankingSystem << endl;

    // Adding accounts to Alice
    AccountBuilder accountBuilder;
    Account* checkingAccount = new Account(
        accountBuilder.setBalance(500)
                           .setAccountNumber(12345)
                           .setInterestRate(2)
                           .setAccountType(CHECKING)
                           .build()
    );

    alice->addAccount(checkingAccount);

    cout << "Account created for Alice: " << *checkingAccount << endl;
    cout << "Banking system status: " << *bankingSystem << endl;

    // Display Alice's accounts
    cout << "Alice's accounts:" << endl;
    for (const auto& account : alice->getAccounts()) {
        cout << *account << endl; // Dereference the pointer to print account details
    }

    // Clean up dynamically allocated memory
    delete checkingAccount;

    return 0;
}