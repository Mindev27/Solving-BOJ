#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>


bool used[20];
string s, path;
vector<string> res;

void dfs(int depth) {
    if (depth == s.size()) {
        res.push_back(path);
        return;
    }
    char last = 0;
    for (int i = 0; i < s.size(); i++) {
        if (used[i] || s[i] == last) continue;
        used[i] = true;
        path.push_back(s[i]);
        dfs(depth + 1);
        path.pop_back();
        used[i] = false;
        last = s[i];
    }
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        sort(s.begin(), s.end());
        path.clear();
        res.clear();
        memset(used, 0, sizeof(used));
        dfs(0);
        for (auto &x : res) cout << x << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
