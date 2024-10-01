#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int n;
unordered_map<string, int> nameToId;
vector<string> idToName;
vector<vector<int>> adj; // 인접 리스트
vector<int> indegree;    // 진입 차수
int id = 0;

void solve() {

  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin >> ws, s); // 전체 라인 입력 (공백 포함)
    stringstream ss(s);
    string s1, op, s2;
    ss >> s1 >> op >> s2;

    // 이름을 ID로 매핑
    if (nameToId.find(s1) == nameToId.end()) {
      nameToId[s1] = id++;
      idToName.push_back(s1);
      adj.emplace_back();
      indegree.push_back(0);
    }
    if (nameToId.find(s2) == nameToId.end()) {
      nameToId[s2] = id++;
      idToName.push_back(s2);
      adj.emplace_back();
      indegree.push_back(0);
    }

    int u = nameToId[s1];
    int v = nameToId[s2];

    if (op == ">") {
      adj[u].push_back(v); // s1 > s2이면 s1에서 s2로 간선
      indegree[v]++;
    }
    else if (op == "<") {
      adj[v].push_back(u); // s1 < s2이면 s2에서 s1로 간선
      indegree[u]++;
    }
  }

  int numNode = id;
  queue<int> q;
  int visited = 0;

  // 진입 차수가 0인 노드를 큐에 추가
  for (int i = 0; i < numNode; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  // 위상 정렬
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited++;
    for (int v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  // 모든 노드를 방문했는지 확인
  if (visited == numNode) {
    cout << "possible\n";
  }
  else {
    cout << "impossible\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
