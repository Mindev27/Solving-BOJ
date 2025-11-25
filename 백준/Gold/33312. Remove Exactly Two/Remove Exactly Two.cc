#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

vector<vector<int>> adj;
vector<set<int>> adjSet;
int n;

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    adjSet.assign(n + 1, set<int>());

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjSet[u].insert(v);
        adjSet[v].insert(u);
    }

    if (n == 2) { cout << "0\n"; return; }

    vector<pii> degreeList;
    for (int i = 1; i <= n; i++) {
        degreeList.push_back({ adj[i].size(), i });
    }
    sort(degreeList.begin(), degreeList.end(), greater<pii>());

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < n; j++) {
            int remove1 = degreeList[i].Y;
            int remove2 = degreeList[j].Y;
            int temp;
            if (adjSet[remove1].find(remove2) == adjSet[remove1].end())
                temp = adj[remove1].size() + adj[remove2].size() - 1;
            else temp = adj[remove1].size() + adj[remove2].size() - 2;
            ans = max(ans, temp);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}