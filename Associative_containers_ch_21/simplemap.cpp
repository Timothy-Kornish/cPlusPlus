#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, int> container;

  container["Fred"] = 22;
  container["Ella"] = 21;
  container["Owen"] = 34;
  container["Zoe"]  = 29;

  std::cout << container["Ella"] << " " << container["Zoe"] << " " << container["bell"] << '\n';
}
