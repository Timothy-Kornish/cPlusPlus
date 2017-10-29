enum class SignalColor { Red, Green, Yellow };

class TrafficLight {
private:
  SignalColor color;
public:

  TrafficLight(SignalColor initial_color);
  void change();
  SignalColor get_color() const;
};
