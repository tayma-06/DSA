#include<iostream>
#include<string>
using namespace std;

// Encapsulation example
class Account
{
private:
    // we are hiding sensitive data members
    double balance;
    string password;
public:
    // non-sensitive data members
    string accountId;
    string username;
    void setBalance(double newBalance)
    {
        balance = newBalance;
    }
    void setPassword(string newPassword)
    {
        password = newPassword;
    }
    double getBalance()
    {
        return balance;
    }
    string getPassword()
    {
        return password;
    }
};

int main()
{
    Account acc;
    acc.accountId = "123456";
    acc.username = "john_doe";
    acc.setBalance(1000.50);  // setting balance using setter
    acc.setPassword("securepassword"); // setting password using setter
    cout << "Account ID: " << acc.accountId << endl;
    cout << "Username: " << acc.username << endl;
    cout << "Balance: $" << acc.getBalance() << endl; // getting balance using getter
    cout << "Password: " << acc.getPassword() << endl; // getting password using getter
    return 0;
}