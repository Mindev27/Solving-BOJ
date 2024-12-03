#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int SIZE = 205;
int N, M;
vector<int> v, po;
vector<int> adj[SIZE];
vector<int> tree[SIZE]; 
int dp[SIZE][2];
bool visited[SIZE];


void makeTree(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            tree[node].push_back(next);
            makeTree(next);
        }
    }
}

// i번째 노드가 루트일때 최대 값 반환 0: 안가져감
int DFS(int node, int special) {
    if (dp[node][special] != -1)
        return dp[node][special];

    if (special == 0) {                 // 현재 노드 안가져감 -> 나머지중에 최대로 싹 쓸기
        dp[node][special] = 0;
        for (int child : tree[node]) {
            dp[node][special] += max(DFS(child, 0), DFS(child, 1));
        }
    } else {                            // 현재 노드 가져감
        dp[node][special] = v[node];    // 에너지 더하고
        for (int child : tree[node]) {
            dp[node][special] += DFS(child, 0); // 싹다 못들고감
        }
    }
    return dp[node][special];
}

void solve() {
    cin >> N >> M;
    v.resize(N);
    po.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < M; i++) {
       cin >> po[i];
    }

    // 그래프 만들기
    for (int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            int gap = abs(v[j] - v[i]);
            bool isFind = false;
            for(int k = 0; k < po.size(); k++) {
                if(gap == po[k]) { isFind = true; break; }
            }

            if(isFind) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    int result = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            makeTree(i);
            result += max(DFS(i, 0), DFS(i, 1));
        }
    }

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
