#include <iostream>
#include <memory>

class Widget {
public:
  Widget() {
    std::cout << "Creating a widget ("
    << reinterpret_cast<uintptr_t>(this) << '\n';
  }
  ~Widget() {
    std::cout << "Destroying a widget ("
    << reinterpret_cast<uintptr_t>(this) << '\n';
  }
};

int main() {
  auto p = std::make_shared<Widget>();
  std::cout << p.use_count() << '\n';
  auto q = p;
  std::cout << p.use_count() << '\n';
  auto r = p;
  std::cout << p.use_count() << '\n';
  r = nullptr;
  std::cout << p.use_count() << '\n';
  q = nullptr;
  std::cout << p.use_count() << '\n';
  p = nullptr;
  std::cout << p.use_count() << '\n';
}
