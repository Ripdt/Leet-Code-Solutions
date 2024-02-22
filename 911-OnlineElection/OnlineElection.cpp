#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int>& votes, vector<int>& timesRegistered) :
    times(timesRegistered)
  {
    /*19 ms*/
    unordered_map<int, int> votesPerCandidate;
    int winner = -1;

    for (int time = 0; time < times.size(); time++) {
      votesPerCandidate[votes[time]]++;
      if (votesPerCandidate[votes[time]] >= votesPerCandidate[winner]) {
        winner = votes[time];
      }
      winnersByTime.push_back(winner);
    }
  }

  int q(int t) {
    /*time limit or 280ms*
    /*
    const int idx = (upper_bound(times.begin(), times.end(), t) - times.begin()) - 1;
    map<int, int> votesPerCandidate;
    int mostVotedCandidate = 0, maxVotes = 0;
    for (int i = 0; i <= idx; i++) {
      const int candidate = votes[i];
      const int qtdVotes = ++votesPerCandidate[candidate];
      if (qtdVotes >= maxVotes) {
        mostVotedCandidate = candidate;
        maxVotes = qtdVotes;
      }
    }
    */
    /*245 ms*/
    /*
    int i = 0;
    const int timesSize = times.size();
    int* votesPerCandidate = new int[votes.size()] {0};
    int mostVotedCandidate = 0, maxVotes = 0;
    do {
      const int candidate = votes[i];
      const int qtdVotes = ++votesPerCandidate[candidate];
      if (qtdVotes >= maxVotes) {
        mostVotedCandidate = candidate;
        maxVotes = qtdVotes;
      }
      i++;
    } while (times[i] <= t);

    delete[] votesPerCandidate;
    */

    const int index = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
    return winnersByTime[index];
  }
private:
  vector<int> winnersByTime;
  const vector<int> times;
};

int main()
{
  vector<int> persons = { 0, 1, 1, 0, 0, 1, 0 };
  vector<int> times = { 0, 5, 10, 15, 20, 25, 30 };
  TopVotedCandidate c(persons, times);

  cout << c.q(3) << endl;
  cout << c.q(12) << endl;
  cout << c.q(25) << endl;
}