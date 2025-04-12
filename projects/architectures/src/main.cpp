#include <iostream>
#include "../include/banking.hpp"

using namespace std;

int main() {

    cout << "Initiating banking system..." << endl;

    BankingSystem* bankingSystem = BankingSystem::getInstance();

    cout << "Banking system status: " << *bankingSystem << endl;

    User alice = bankingSystem->addUser("Alice", 1000);
    
    cout << "User Alice:" << alice << endl;

    cout << "Banking system status: " << *bankingSystem << endl;

    return 0;
}
