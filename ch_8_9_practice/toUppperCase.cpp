#include <iostream>
#include <cctype>

int main() {
  for (char lower = 'a'; lower <= 'z'; lower++) {
    // toupper() returns an int, not char
    char upper = toupper(lower);
    // use a static_cast to insure a character
    upper = static_cast<char>(toupper(lower));
    std::cout << lower << " => " << upper << '\n';
  }
}
