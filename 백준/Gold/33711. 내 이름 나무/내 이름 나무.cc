#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int MAX = 35005;

int N, M, K, W;
vector<int> g[MAX];
int dist[MAX];
int own[MAX];

bool check(vector<int> v) {
    if (v.size() <= 1) return false;

    queue<int> q;
    vector<int> visited;

    for (int s : v) {
        if (dist[s] == -1) visited.push_back(s);
        dist[s] = 0;
        own[s] = s;
        q.push(s);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] == K) continue;

        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                own[v] = own[u];
                visited.push_back(v);
                q.push(v);
            }
            else if (own[v] != own[u]) {
                int total = dist[u] + dist[v] + 1;

                if (total <= K) {
                    for (int x : visited) {
                        dist[x] = -1;
                        own[x] = 0;
                    }
                    return true;
                }
            }
        }
    }

    for (int x : visited) { dist[x] = -1; own[x] = 0; }
    return false;
}

void solve() {
    cin >> N >> M >> K;
    cin >> W;

    for (int i = 1; i <= N; i++) {
        g[i].clear();
        dist[i] = -1;
        own[i] = 0;
    }

    unordered_map<string, vector<int>> name;

    for (int i = 0; i < W; i++) {
        int u; string s;
        cin >> u >> s;
        name[s].push_back(u);
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (auto &kv : name) {
        vector<int>& group = kv.Y;
        if (group.size() <= 1) continue;
        if (check(group)) {
            cout << "POWERFUL CODING JungHwan\n";
            return;
        }
    }

    cout << "so sad\n";
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