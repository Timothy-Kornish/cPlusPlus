#include <iostream>
#include <iomanip>
#include <string>

class Account {

  std::string name;
  int id;
  double balance;

public:

  Account(const std::string& customer_name, int account_number, double amount):
          name(customer_name), id(account_number), balance(amount) {
    if (amount < 0) {
      std::cout << "Warning: negative account balance\n";
      balance = 0.0;
    }
  }

  void deposit(double amount) {
    balance += amount;
  }

  bool withdraw(double amount) {
    bool result = false;
    if (balance - amount >= 0) {
      balance -= amount;
      result = true;
    }
    return result;
  }

  void display() {
    std::cout << "Name: " << name << ", ID: " << id << ", Balance: " << balance << '\n';
  }

};

int main() {

  Account acct1("Joe", 2312, 1000.00);
  Account acct2("Moe", 2313, 500.29);

  acct1.display();
  acct2.display();
  std::cout << "-------------------------\n";
  acct1.withdraw(800.00);
  acct2.deposit(20.25);
  acct1.display();
  acct2.display();
}
