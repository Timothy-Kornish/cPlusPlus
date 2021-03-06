#include <iostream>
#include <vector>

struct Widget {
  int value;
  Widget(int value): value(value) {
    std::cout << "Creating Widget " << value << '\n';
  }
  ~Widget() {
    std::cout << "Destroying widget " << value << '\n';
  }
};

Widget *get_widget() {
  static int pos = 0;
  static std::vector<Widget *> widget_pool;

  widget_pool.push_back(new Widget(23)), widget_pool.push_back(new Widget(45));
  widget_pool.push_back(new Widget(16)), widget_pool.push_back(new Widget(12));
  widget_pool.push_back(new Widget(3)), widget_pool.push_back(new Widget(20));
  widget_pool.push_back(new Widget(10));

  pos = (pos + 1) % widget_pool.size();
  return widget_pool[pos];

}

void process(int n) {
  std::vector<Widget *> vec;
  while (n-- > 0) {
    vec.push_back(get_widget());
  }
  for (auto& elem : vec) {
    delete elem;
  }
}

int main() {
  std::cout << "Entering main\n";
  process(10);
  std::cout << "Leaving main\n";
}
