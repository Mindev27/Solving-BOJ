#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAX = 1900000;
ll val[MAX];
int indegree[MAX];
vector<vector<int>> adj(MAX);
int M, N;

// 좌표를 문자열로 변환환
string toStr(int x, int y) {
    string col = "";
    int temp = x + 1;
    while (temp > 0) {
        int rem = (temp - 1) % 26;
        col = char('A' + rem) + col;
        temp = (temp - 1) / 26;
    }
    return col + to_string(y + 1);
}

// 문자열을 i, j좌표로 변환환
pii toNum(string s) {
    int pos = 0;
    while (pos < s.size() && isalpha(s[pos])) pos++;
    string colStr = s.substr(0, pos);
    string rowStr = s.substr(pos);

    int x = 0;
    for (char c : colStr) {
        x = x * 26 + (c - 'A' + 1);
    }
    x -= 1;

    return { x, stoi(rowStr) - 1 };
}

void solve() {
    cin >> M >> N;

    for (int i = 0; i < N * M; i++) {
        val[i] = 0;
        indegree[i] = 0;
        adj[i].clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            string s; cin >> s;
            int idx = i * M + j; // 현재 칸 인덱스

            if (s[0] == '=') {
                s = s.substr(1);
                vector<string> cur;
                string temp = "";
                for (char& c : s) {
                    if (c == '+') {
                        cur.push_back(temp);
                        temp = "";
                    }
                    else temp += c;
                }
                if (!temp.empty()) {
                    cur.push_back(temp);
                }

                for (auto& i : cur) {
                    pii pos = toNum(i);
                    int preIdx = pos.Y * M + pos.X;
                    adj[preIdx].push_back(idx);
                    indegree[idx]++;
                }
            }
            else {
                val[idx] = stoll(s);
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < N * M; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& v : adj[u]) {
            val[v] += val[u];
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int idx = i * M + j;
            cout << val[idx] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc; cin >> Tc;
    while (Tc--) {
        solve();
    }

    return 0;
}
