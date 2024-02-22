#include <iostream>

class Solution {
public:
  int countTriples(int a, int top) {
    int triples = 0;
    for (int b = 1; b < top; b++) {
      if (a != b) {
        const double product = a * a + b * b;
        const int c = static_cast<int>(sqrt(product));
        if (c > top) {
          break;
        }
        if (c * c == product) {
          triples += 2;
        }
      }
    }
    return triples;
  }

  int countTriples(int n) {
    int triples = 0;
    for (int i = 1; i < n; i++) {
      triples += countTriples(i, n);
    }
    return triples;
  }
};

int main()
{
  Solution s;
  std::cout << s.countTriples(18);
}