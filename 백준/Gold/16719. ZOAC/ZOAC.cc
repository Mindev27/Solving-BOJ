#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
일단 뭘 보여줄거냐 하면
공개안된것중에 가장 사전순으로 앞서는거 고르면 됨
100자리 이하니까 그냥 완탐 돌리면 됨
*/

string s;
vector<int> vis;

void printNow() {
    for (int i = 0; i < s.size(); i++) {
        if (vis[i]) cout << s[i];
    }
    cout << '\n';
}

void dfs(int l, int r) {
    if (l > r) return;
    int idx = l;
    for (int i = l + 1; i <= r; i++) {
        if (s[i] < s[idx]) idx = i;
    }
    vis[idx] = 1;
    printNow();
    dfs(idx + 1, r);
    dfs(l, idx - 1);
}

void solve() {
    cin >> s;
    vis.resize(s.size(), 0);
    dfs(0, s.size() - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}
