#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int MAX = 50005;
int fail[MAX];
string A, W, S;

bool KMP(string T, string P) {
  // 실패 함수
  int m = P.size();
  for(int i = 1, j = 0; i < m; i++) {
    while(j > 0 && P[i] != P[j]) j = fail[j - 1];
    if(P[i] == P[j]) fail[i] = ++j;
  }

  // KMP 알고리즘
  bool isFound = false;
  for(int i = 0, j = 0; i < T.size(); i++) {
    while(j > 0 && T[i] != P[j]) j = fail[j - 1];
    if(T[i] == P[j]) {
      if(j == m - 1) {
        if(isFound) return false; // 두번나오면 false
        isFound = true;
        j = fail[j];
      }
      else j++;
    }
  }
  return isFound;
}

void solve() {
  vector<int> res;
  map<char, char> shift;

  // 시프트 전처리
  for(int i = 0; i < A.size() - 1; i++)
    shift[A[i]] = A[i + 1];  
  shift[A[(int)A.size() - 1]] = A[0];

  for(int i = 1; i <= A.size(); i++) {
    for(int j = 0; j < W.size(); j++) // W를 시프트하고
      W[j] = shift[W[j]];

    if(KMP(S, W)) res.push_back(i % A.size()); // KMP로 확인
  }

  // 정답 출력
  if(res.size() == 0) cout << "no solution\n";
  else if(res.size() == 1) cout << "unique: " << res[0] << '\n';
  else {
    sort(res.begin(), res.end());
    cout << "ambiguous: ";
    for(int &i : res) cout << i << ' ';
    cout << '\n';
  }
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    cin >> A >> W >> S;
    solve();
  }

  return 0;
}