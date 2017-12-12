#include <iostream>
#include <memory>
#include <vector>

struct Widget {
  int value;
  Widget(int value): value(value) {
    std::cout << "Creating Widget " << value << '\n';
  }
  ~Widget() {
    std::cout << "Destroying Widget " << value << '\n';
  }
};

std::shared_ptr<Widget> get_widget() {
  static int pos = 0;
  static std::vector<std::shared_ptr<Widget> > widget_pool;

  widget_pool.push_back(std::make_shared<Widget>(23)); // will error out, std::make_shared<Widget>() needs empty params
  widget_pool.push_back(std::make_shared<Widget>(45));
  widget_pool.push_back(std::make_shared<Widget>(16));
  widget_pool.push_back(std::make_shared<Widget>(12));
  widget_pool.push_back(std::make_shared<Widget>(3));
  widget_pool.push_back(std::make_shared<Widget>(20));
  widget_pool.push_back(std::make_shared<Widget>(10));

  pos = (pos + 1) % widget_pool.size();
  return widget_pool[pos];
}

void process(int n) {
  std::vector<std::shared_ptr<Widget> > vec;
  while (n-- > 0) {
    vec.push_back(get_widget());
  }
}

int main() {
  std::cout << "Entering main\n";
  process(10);
  std::cout << "Leaving main\n";
}
