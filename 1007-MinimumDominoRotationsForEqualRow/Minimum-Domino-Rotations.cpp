#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MIN_DOMINO_VALUE 1
#define MAX_DOMINO_VALUE 6

class Solution {
public:
  bool numberHasValidQuantityOfAppearences(
    const int number, 
    const vector<int>& priority, 
    const vector<int>& swapping, 
    int& appearencesInSwapping
  ) const {
    int appearencesPrioritized = 0;
    appearencesInSwapping = 0;
    for (int i = 0; i < priority.size(); i++) {
      if (priority[i] == number) appearencesPrioritized++;
      else if (swapping[i] == number) appearencesInSwapping++;
    }

    return appearencesPrioritized + appearencesInSwapping == priority.size();
  }

  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    const size_t size = tops.size();
    int minRotations = (int)size + 1;
    for (int number = MIN_DOMINO_VALUE; number <= MAX_DOMINO_VALUE; number++) {
      int qtdRotations;
      if (numberHasValidQuantityOfAppearences(number, tops, bottoms, qtdRotations)) {
        minRotations = min(qtdRotations, minRotations);
      }
      if (numberHasValidQuantityOfAppearences(number, bottoms, tops, qtdRotations)) {
        minRotations = min(qtdRotations, minRotations);
      }
    }

    return minRotations > size ? -1 : minRotations;
  }
};

int main()
{
  vector<int> tops1 = { 2,1,2,4,2,2 }, bottoms1 = { 5,2,6,2,3,2 };
  Solution s1;
  cout << s1.minDominoRotations(tops1, bottoms1) << endl; // 2

  vector<int> tops2 = { 3,5,1,2,3 }, bottoms2 = { 3,6,3,3,4 };
  Solution s2;
  cout << s2.minDominoRotations(tops2, bottoms2) << endl; // -1

  vector<int> tops3 = { 1,2,1,1,1,2,2,2 }, bottoms3 = { 2,1,2,2,2,2,2,2 };
  Solution s3;
  cout << s3.minDominoRotations(tops3, bottoms3) << endl; // 1

  return 1;
}