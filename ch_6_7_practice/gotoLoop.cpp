#include <iostream>

int main() {
  int count = 1;
top:
  if (count > 5) {
    goto end;
  }
  std::cout << count << '\n';
  count++;
  goto top;
end:
  ;
}
