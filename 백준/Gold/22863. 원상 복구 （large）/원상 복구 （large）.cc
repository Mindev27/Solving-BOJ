#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

ll N, K;
int D[1000005];
int S[1000005];
bool visited[1000005];
int res[1000005];
vector<vector<int>> cycle;
vector<int> temp; // 잠깐 사이클 저장

void DFS(int x) {
    if (visited[x]) return;
    visited[x] = true;
    temp.push_back(x);
    DFS(D[x]);
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }


    // D를 사이클로 만들자
    fill(visited, visited + 1000005, false);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            temp.clear();
            DFS(i);
            cycle.push_back(temp);
        }
    }

    for (auto v : cycle) {
        // v에 대해서 K번 나눈 사이클
        for (int i = 0; i < v.size(); i++) {
            ll nxtIdx = (i + (K % v.size())) % v.size();
            res[v[nxtIdx]] = S[v[i]];
        }
    }


    for (int i = 1; i <= N; i++) {
        cout << res[i] << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
