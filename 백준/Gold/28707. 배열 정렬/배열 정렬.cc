#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N, M;
vector<int> A;
set<vector<int>> visited;
using T = pair<int, vector<int>>;
priority_queue<T, vector<T>, greater<T>> pq;

bool isSorted(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}

void solve() {
    cin >> N;
    A.resize(N);
    for (int& i : A) cin >> i;

    cin >> M;
    vector<tuple<int, int, int>> LRC(M);
    for (auto& [l, r, c] : LRC)
        cin >> l >> r >> c, --l, --r;

    pq.push({ 0, A });

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (visited.count(v))
            continue;

        visited.insert(v);
        if (isSorted(v)) {
            cout << d << '\n';
            return;
        }

        for (auto [l, r, c] : LRC) {
            auto T = v;
            swap(T[l], T[r]);
            pq.push({ d + c, T });
        }
    }

    cout << -1 << '\n';
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