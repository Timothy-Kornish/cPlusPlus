#ifndef COMPARER_H_
#define COMPARER_H_

class Comparer {
  int compare_count;
  int swap_count;
  bool (*comp)(int, int);

protected:
  virtual bool compare_impl(int m, int n);
  virtual void swap_impl(int& m, int& n);

public:
  Comparer(bool (*f)(int, int));
  void reset();
  bool compare(int m, int n);
  void swap(int& m, int& n);
  int comparisons() const;
  int swaps() const;
};
#endif
