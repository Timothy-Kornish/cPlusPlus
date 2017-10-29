#include "trafficLight.h"

TrafficLight::TrafficLight(SignalColor initial_color) {
  switch(initial_color) {
    case SignalColor::Red:
    case SignalColor::Green:
    case SignalColor::Yellow:
      color = initial_color;
    default:
      color = SignalColor::Red;
  }
}

void TrafficLight::change() {
  if (color == SignalColor::Red) {
    color = SignalColor::Green;
  }
  else if (color == SignalColor::Green) {
    color = SignalColor::Yellow;
  }
  else if (color == SignalColor::Yellow) {
    color = SignalColor::Red;
  }
}

SignalColor TrafficLight::get_color() const {
  return color;
}
