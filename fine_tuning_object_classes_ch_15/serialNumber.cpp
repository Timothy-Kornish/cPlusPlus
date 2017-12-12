#include <iostream>

class Widget {

  static int serial_number_source;

  int serial_number;
public:

  Widget(): serial_number(serial_number_source++) {}

  int get_serial_number() const {
    return serial_number;
  }
};

int Widget::serial_number_source = 1;

int main() {
  Widget w1, w2, w3, w4;

  std::cout << "w1 serial number = " << w1.get_serial_number() << '\n';
  std::cout << "w2 serial number = " << w2.get_serial_number() << '\n';
  std::cout << "w3 serial number = " << w3.get_serial_number() << '\n';
  std::cout << "w4 serial number = " << w4.get_serial_number() << '\n';
}
