#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Account
{
public:
    int accountNo;
    string password;
    string name;
    int age;
    char sex;
    double amount;

    Account() : accountNo(0), password(""), name(""), age(0), sex('M'), amount(0.0) {}

    Account(int accNo, string pwd, string nm, int ag, char sx, double amt)
    {
        this->accountNo = accNo;
        this->password = pwd;
        this->name = nm;
        this->age = ag;
        this->amount = amt;
    }
};

class Bank
{
private:
    unordered_map<int, Account> accounts;

public:
    void createAccount(int accNo, string pwd, string nm, int ag, char sx, double amt)
    {
        if (accounts.find(accNo) != accounts.end())
        {
            cout << "Account with this number already exists.\n";
            return;
        }
        accounts[accNo] = Account(accNo, pwd, nm, ag, sx, amt);
        cout << "Account created successfully.\n";
    }

    void deleteAccount(int accNo, string pwd)
    {
        if (accounts.find(accNo) != accounts.end() && accounts[accNo].password == pwd)
        {
            accounts.erase(accNo);
            cout << "Account deleted successfully.\n";
        }
        else
        {
            cout << "Account not found or incorrect password.\n";
        }
    }

    void depositAmount(int accNo, double amt)
    {
        if (accounts.find(accNo) != accounts.end())
        {
            accounts[accNo].amount += amt;
            cout << "Amount deposited successfully.\n";
        }
        else
        {
            cout << "Account not found.\n";
        }
    }

    void withdrawAmount(int accNo, double amt)
    {
        if (accounts.find(accNo) != accounts.end())
        {
            if (accounts[accNo].amount >= amt)
            {
                accounts[accNo].amount -= amt;
                cout << "Amount withdrawn successfully.\n";
            }
            else
            {
                cout << "Insufficient balance.\n";
            }
        }
        else
        {
            cout << "Account not found.\n";
        }
    }

    void checkBalance(int accNo)
    {
        if (accounts.find(accNo) != accounts.end())
        {
            cout << "Current balance: " << accounts[accNo].amount << "\n";
        }
        else
        {
            cout << "Account not found.\n";
        }
    }

    void searchAccount(int accNo)
    {
        if (accounts.find(accNo) != accounts.end())
        {
            Account acc = accounts[accNo];
            cout << "Account No: " << acc.accountNo << "\n"
                 << "Name: " << acc.name << "\n"
                 << "Age: " << acc.age << "\n"
                 << "Sex: " << acc.sex << "\n"
                 << "Amount: " << acc.amount << "\n";
        }
        else
        {
            cout << "Account not found.\n";
        }
    }
};

int main()
{
    Bank bank;
    int choice;
    int accNo, age;
    double amount;
    string name, password;
    char sex;

    while (true)
    {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Delete Account\n";
        cout << "3. Deposit Amount\n";
        cout << "4. Withdraw Amount\n";
        cout << "5. Check Balance\n";
        cout << "6. Search Account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Name: ";
            cin.ignore();
            getline(std::cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Sex (M/F): ";
            cin >> sex;
            cout << "Enter Initial Amount: ";
            cin >> amount;
            bank.createAccount(accNo, password, name, age, sex, amount);
            break;
        case 2:
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Password: ";
            cin >> password;
            bank.deleteAccount(accNo, password);
            break;
        case 3:
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            bank.depositAmount(accNo, amount);
            break;
        case 4:
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            bank.withdrawAmount(accNo, amount);
            break;
        case 5:
            cout << "Enter Account No: ";
            cin >> accNo;
            bank.checkBalance(accNo);
            break;
        case 6:
            cout << "Enter Account No: ";
            cin >> accNo;
            bank.searchAccount(accNo);
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
