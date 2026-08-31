#include "20260831_Prac1_nishino.h"
using namespace std;

int main() 
{
    BankAccount account("Alice", 5000.0); //口座名義人の名前

    account.displayAccountInfo();

    account.deposit(1000.0);
    account.withdraw(2000.0);
    account.withdraw(5000.0); // 残高不足で失敗

    account.displayAccountInfo();

    return 0;
}
