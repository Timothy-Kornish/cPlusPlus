#include <string>

class Account {

private:

  std::string name;
  int id;
  double balance;

public:

  void deposit(double amount) {
    balance += amount;
  }

  bool withdraw(double amount) {
    bool result = false;
    if (balance - amount > 0) {
      balance -= amount;
      result = true;
    }
    return result;
  }
};
