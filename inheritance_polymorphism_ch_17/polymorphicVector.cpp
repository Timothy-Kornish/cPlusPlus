#include <string>
#include <vector>
#include <iostream>

class Text {
  std::string text;
public:
  Text(const std::string& t): text(t) {}
  virtual std::string get() const {
    return text;
  }
};

class FancyText: public Text {
  std::string left_bracket;
  std::string right_bracket;
  std::string connector;
public:
  FancyText(const std::string& t, const std::string& left,
            const std::string& right, const std::string& conn):
            Text(t), left_bracket(left), right_bracket(right),
            connector(conn) {}

  std::string get() const override {
    return left_bracket + Text::get() + right_bracket;
  }
};

class FixedText: public Text {
public:
  FixedText(): Text("FIXED") {}
};

int main() {
  std::vector<Text *> texts;
  texts.push_back(new Text("Wow"));
  texts.push_back(new FancyText("Wee", "[", "]", "-"));
  texts.push_back(new FixedText);
  texts.push_back(new FancyText("Whoa", ":", ":", ":"));
  for (auto t: texts) {
    std::cout << t->get() << '\n';
  }
}
