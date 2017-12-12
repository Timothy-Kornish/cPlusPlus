#include "signal.h"

Signal::Signal(int initial_color) {
  switch (initial_color) {
    case RED:
    case GREEN:
    case YELLOW:
      color = initial_color;
      break;
    default:
      color = RED;
  }
}

void Signal::change() {
  color = (color + 1) % 3;
}

int Signal::get_color() const {
  return color;
}
