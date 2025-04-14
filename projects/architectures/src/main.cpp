#include <iostream>
#include "../include/banking.hpp"

using namespace std;

int main() {

    // Singleton pattern for banking system
    cout << "Initiating banking system..." << endl;

    BankingSystem* bankingSystem = BankingSystem::getInstance();

    cout << "Banking system status: " << *bankingSystem << endl;

    User* alice = bankingSystem->addUser("Alice", 1000);
    
    cout << "User Alice:" << *alice << endl;

    cout << "Banking system status: " << *bankingSystem << endl;


    // Cloning Alice for prototype pattern
    User* aliceClone = alice->clone();

    cout << "Cloned User Alice:" << aliceClone << endl;

    bankingSystem->addUser(aliceClone);

    cout << "Banking system status: " << *bankingSystem << endl;
    
    aliceClone->setName("Alice Clone");
    
    cout << "Banking system status: " << *bankingSystem << endl;

    return 0;
}   
