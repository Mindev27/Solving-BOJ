#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> adj[30];

int get(string s) {
    return s[0] - 'A';
}

string find(int start, int end) {
    queue<vector<int>> q;
    vector<bool> visited(30, false);

    q.push({start});
    visited[start] = true;

    while (!q.empty()) {
        vector<int> path = q.front();
        q.pop();

        int cur = path.back();

        if (cur == end) {
            string result;
            for (int node : path) {
                result += char(node + 'A');
            }
            return result;
        }

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                vector<int> newPath = path;
                newPath.push_back(next);
                q.push(newPath);
            }
        }
    }

    return "";
}

void solve() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;

        int uId = get(u);
        int vId = get(v);

        adj[uId].push_back(vId);
        adj[vId].push_back(uId);
    }

    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;

        int uId = get(u);
        int vId = get(v);

        cout << find(uId, vId) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
