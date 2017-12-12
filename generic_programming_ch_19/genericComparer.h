#ifndef GENERICCOMPARER_H_
#define GENERICCOMPARER_H_

template <typename T>
class Comparer {
  int compare_count;
  int swap_count;
  bool (*comp)(const T&, const T&);

protected:
  virtual bool compare_impl(const T& m, const T& n) {
    return comp(m, n);
  }

  virtual void swap_impl(T& m, T& n) {
    T temp = m;
    m = n;
    n = temp;
  }

public:

  Comparer(bool (*f)(const T&, const T&)):
           compare_count(0), swap_count(0), comp(f) {}

  void reset() {
    compare_count = swap_count = 0;
  }

  bool compare(const T& m, const T& n) {
    compare_count++;
    return compare_impl(m, n);
  }

  void swap(T& m, T& n) {
    swap_count++;
    swap_impl(m, n);
  }

  int comparisons() const {
    return compare_count;
  }

  int swaps() const {
    return swap_count;
  }

};

#endif
