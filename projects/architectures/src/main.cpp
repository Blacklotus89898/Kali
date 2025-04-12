#include <iostream>
#include "../include/banking.hpp"

using namespace std;

int main() {

    cout << "Program entry point" << endl;

    cout << "Initiating banking system..." << endl;
    BankingSystem* bankingSystem = BankingSystem::getInstance();

    User alice = bankingSystem->addUser("Alice", 1000);
    
    cout << "User alice:" << alice << endl;

    cout << "Bnaking system instance: " << bankingSystem << endl;

    return 0;
}