#include <string>
#include <iostream>

class Text {
  std::string text;
public:

  Text(const std::string& t): text(t) {}

  virtual std::string get() const {
    return text;
  }

  virtual void append(const std::string& extra) {
    text += extra;
  }
};

class FancyText: public Text {
  std::string left_bracket;
  std::string right_bracket;
  std::string connector;
public:

  FancyText(const std::string& t, const std::string& left,
            const std::string& right, const std::string& conn):
            Text(t), left_bracket(left), right_bracket(right), connector(conn) {}

  std::string get() const override {
    return left_bracket + Text::get() + right_bracket;
  }

  void append(const std::string& extra) override {
    Text::append(connector + extra);
  }
};

class FixedText: public Text {
public:

  FixedText(): Text("FIXED") {}

  void append(const std::string&) override {

  }
};

int main() {
  Text t1("plain");
   FancyText t2("fancy", "<<", ">>", "***");
   FixedText t3;
   std::cout << t1.get() << '\n';
   std::cout << t2.get() << '\n';
   std::cout << t3.get() << '\n';
   std::cout << "-------------------------\n";
   t1.append("A");
   t2.append("A");
   t3.append("A");
   std::cout << t1.get() << '\n';
   std::cout << t2.get() << '\n';
   std::cout << t3.get() << '\n';
   std::cout << "-------------------------\n";
   t1.append("B");
   t2.append("B");
   t3.append("B");
   std::cout << t1.get() << '\n';
   std::cout << t2.get() << '\n';
   std::cout << t3.get() << '\n';
}
