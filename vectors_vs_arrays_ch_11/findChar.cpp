#include <iostream>

bool findChar(const char *s, char ch) {
  while (*s != '\0') {
    if (*s == ch) {
      return true;
    }
    s++;
  }
  return false;
}

int main() {
  const char *phrase = "this is a phrase";
  for (char ch = 'a'; ch <= 'z'; ch++) {
    std::cout << '\'' << ch << '\'' << " is ";
    if (!findChar(phrase, ch)) {
      std::cout << "NOT ";
    }
    std::cout << "in " << '\"' << phrase << '\"' << '\n';
  }
}
