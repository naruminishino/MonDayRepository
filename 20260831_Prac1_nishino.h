#pragma once
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    std::string accountHolder; // 口座名義人
    double balance;            // 残高

public:

    BankAccount(const string& holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n"; //入金されたか確認
        }
        else {
            cout << "Invalid deposit amount.\n"; //無効な入金額
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n"; //出金
        }
        else
        {
            cout << "Invalid withdraw amount or insufficient funds.\n"; //残高が不足していることを表示
        }
    }

    void displayAccountInfo() const
    {
        cout << "Account Holder: " << accountHolder << "\n"
            << "Current Balance: " << balance << "\n"; //現在の残高を表示
    }
};
