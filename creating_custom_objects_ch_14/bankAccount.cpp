#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

class Account {
public:
  std::string name;
  int id;
  double balance;
};

void add_account(std::vector<Account>& accts) {
  std::string name;
  int number;
  double amount;

  std::cout << "Enter name, account number, and account balance: ";
  std::cin >> name >> number >> amount;

  Account acct;
  acct.name = name;
  acct.id = number;
  acct.balance = amount;

  accts.push_back(acct);
}

void print_accounts(const std::vector<Account>& accts) {
  int n = accts.size();
  for (int i = 0; i < n; i++) {
    std::cout << accts[i].name << ", " << accts[i].id << ", " << accts[i].balance << '\n';
  }
}

void swap(Account& er1, Account er2) {
  Account temp = er1;
  er1 = er2;
  er2 = temp;
}

bool less_than_by_name(const Account& e1, const Account& e2) {
  return e1.name < e2.name;
}

bool less_than_by_id(const Account& e1, const Account& e2) {
  return e1.id < e2.id;
}

bool less_than_by_balance(const Account& e1, const Account& e2) {
  return e1.balance < e2.balance;
}

void sort(std::vector<Account>& db, bool (*func)(const Account&, const Account&)) {
  int size = db.size();
  for (int i = 0; i < size - 1; i++) {
    int smallest = i;
    for (int j = i + 1; j < size; j++) {
      if(func(db[j], db[smallest])) {
        smallest = j;
      }
    }
    if (smallest != i) {
      swap(db[i], db[smallest]);
    }
  }
}

int main() {
  std::vector<Account> customers;

  char cmd;
  bool done = false;

  do {

    std::cout << "[A]dd [N]ame [I]D [B]alance [Q]uit ==> ";
    std::cin >> cmd;
    cmd = toupper(cmd);
    switch (cmd) {
      case 'A':
        add_account(customers);
        break;
      case 'P':
        print_accounts(customers);
        break;
      case 'N':
        sort(customers, less_than_by_name);
        print_accounts(customers);
        break;
      case 'I':
        sort(customers, less_than_by_id);
        print_accounts(customers);
        break;
      case 'B':
        sort(customers, less_than_by_balance);
        print_accounts(customers);
        break;
      case 'Q':
        done = true;
        break;
      default:
        done = true;
        break;
    }

  } while (!done);
}
