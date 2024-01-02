#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

const int MAX = 100001;

int BFS(int n, int k);

int main() {
  int n, k;

  cin >> n >> k;

  cout << BFS(n, k) << "\n";
}

int BFS(int n, int k) {
  int visited[MAX] = {};
  memset(visited, -1, sizeof(visited));
  deque<int> dq;
  dq.push_back(n);

  visited[n] = 0;

  while (!dq.empty()) {
    int loc = dq.front();
    dq.pop_front();

    if (loc == k)
      return visited[loc];
    
    if (loc - 1 >= 0 && visited[loc - 1] == -1) {
      dq.push_back(loc - 1);
      visited[loc - 1] = visited[loc] + 1;
    }
    if (loc * 2 < MAX && visited[loc * 2] == -1) {
      dq.push_front(loc * 2);
      visited[loc * 2] = visited[loc];
    }
    if (loc + 1 < MAX && visited[loc + 1] == -1) {
      dq.push_back(loc + 1);
      visited[loc + 1] = visited[loc] + 1;
    }
  }
}