#include <iostream>
#include <cmath>
#include <Typeinfo>

template<class T, class U>

auto add(T t, U u) -> decltype(t + u) {
  return t + u;
}

auto
