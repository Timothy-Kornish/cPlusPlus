#ifndef SIGNAL_H_
#define SIGNAL_H_

class Signal {
  int color;
public:
  static const int RED = 0; // static: helps reduce number of repitions in memory
  static const int GREEN = 1;
  static const int YELLOW = 2;

  Signal(int initial_color);
  void change();
  int get_color() const;
};

#endif
