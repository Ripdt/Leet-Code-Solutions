#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isInsideMatrix(const int coordRow, const int coordCol, const int rows, const int cols) {
    const bool isAfterNorthWestBoundary = coordRow >= 0 && coordCol >= 0;
    const bool isB4SouthEastBoundary = coordRow < rows && coordCol < cols;
    return isAfterNorthWestBoundary && isB4SouthEastBoundary;
  }

  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> visitedPositions;
    int i = rStart, j = cStart;
    visitedPositions.push_back({ i, j });
    int step = 1;
    const int matrixSize = rows * cols;
    while (visitedPositions.size() < matrixSize) {
      for (int it = 1; it <= step; it++) {
        j++;

        if (isInsideMatrix(i, j, rows, cols)) {
          visitedPositions.push_back({ i, j });
        }
      }
      for (int it = 1; it <= step; it++) {
        i++;

        if (isInsideMatrix(i, j, rows, cols)) {
          visitedPositions.push_back({ i, j });
        }
      }
      step++;
      for (int it = 1; it <= step; it++) {
        j--;

        if (isInsideMatrix(i, j, rows, cols)) {
          visitedPositions.push_back({ i, j });
        }
      }
      for (int it = 1; it <= step; it++) {
        i--;

        if (isInsideMatrix(i, j, rows, cols)) {
          visitedPositions.push_back({ i, j });
        }
      }
      step++;
    }

    return visitedPositions;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> positions = s.spiralMatrixIII(5, 6, 1, 4);
  for (vector<int> position : positions) {
    cout << "[" << position[0] << ", " << position[1] << "]\n";
  }
}