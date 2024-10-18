#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class ATM {
    struct Account {
        string password;
        double balance;
        vector<string> transactions;
    };
    map<string, Account> accounts;
    const double interestRate = 0.03;

public:
    void createAccount(const string& username, const string& password, double balance = 0) {
        if (accounts.find(username) != accounts.end()) {
            cout << "Account with username '" << username << "' already exists.\n";
        } else {
            accounts[username] = {password, balance, {}};
            cout << "Account successfully created for " << username << "!\n";
        }
    }

    bool authenticate(const string& username, const string& password) {
        if (accounts.find(username) != accounts.end() && accounts[username].password == password) {
            return true;
        } else {
            cout << "Authentication failed! Please check your username and password.\n";
            return false;
        }
    }

    void deposit(const string& username, const string& password, double amount) {
        if (authenticate(username, password)) {
            accounts[username].balance += amount;
            accounts[username].transactions.push_back("Deposited: $" + to_string(amount));
            cout << "$" << amount << " deposited successfully.\n";
        }
    }

    void withdraw(const string& username, const string& password, double amount) {
        if (authenticate(username, password)) {
            if (accounts[username].balance >= amount) {
                accounts[username].balance -= amount;
                accounts[username].transactions.push_back("Withdrew: $" + to_string(amount));
                cout << "$" << amount << " withdrawn successfully.\n";
            } else {
                cout << "Insufficient balance! Current balance: $" << accounts[username].balance << "\n";
            }
        }
    }

    void viewBalance(const string& username, const string& password) {
        if (authenticate(username, password)) {
            cout << "Current balance: $" << accounts[username].balance << "\n";
        }
    }

    void viewTransactions(const string& username, const string& password) {
        if (authenticate(username, password)) {
            cout << "Transaction history for " << username << ":\n";
            for (const string& t : accounts[username].transactions) {
                cout << t << "\n";
            }
        }
    }

    void calculateInterest(const string& username, const string& password, int years) {
        if (authenticate(username, password)) {
            double interest = accounts[username].balance * interestRate * years;
            cout << "Interest for " << years << " year(s) at 3%: $" << interest << "\n";
        }
    }

    bool accountExists(const string& username) {
        return accounts.find(username) != accounts.end();
    }
};

int main() {
    ATM atm;
    int choice;
    string username, password;
    double amount;
    int years;
    char continueChoice;

    do {
        cout << "\n----- Welcome to the ATM System -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Balance\n";
        cout << "5. View Transactions\n";
        cout << "6. Calculate Interest\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a new username: ";
                cin >> username;
                if (atm.accountExists(username)) {
                    cout << "Account with this username already exists.\n";
                } else {
                    cout << "Enter a password: ";
                    cin >> password;
                    cout << "Enter initial balance: ";
                    cin >> amount;
                    atm.createAccount(username, password, amount);
                }
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                atm.deposit(username, password, amount);
                break;
            case 3:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                atm.withdraw(username, password, amount);
                break;
            case 4:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                atm.viewBalance(username, password);
                break;
            case 5:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                atm.viewTransactions(username, password);
                break;
            case 6:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter number of years: ";
                cin >> years;
                atm.calculateInterest(username, password, years);
                break;
            case 7:
                cout << "Thank you for using the ATM system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Thank you for using the ATM system. Goodbye!\n";
    return 0;
}
