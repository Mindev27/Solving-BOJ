#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

// [i, j)로 칸을 표현하자
// 0, 4면 0 1 2 3 4이니까 [0,5)

const int MAX = 1000000;
ll N, K;
vector<pll> v;
ll imos[MAX + 5];

void solve() {
    cin >> N >> K;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].X >> v[i].Y;
    }

    // 0 1 2 3 4 5
    // +1       -1
    // 1 1 1 1 1 0  굿
    fill(imos, imos + MAX + 5, 0);
    for (auto& [s, e] : v) {
        imos[s] += 1;
        imos[e] -= 1;
    }

    for (int i = 1; i <= MAX; i++) {
        imos[i] += imos[i - 1];
    }

    // 투포인터
    ll sum = imos[0];
    for (int l = 0, r = 0; l <= MAX; l++) {
        while (r < MAX && sum < K) {
            r++;
            sum += imos[r];
        }

        if (sum == K) {
            cout << l << ' ' << r + 1;
            return;
        }

        sum -= imos[l];
    }

    cout << "0 0";
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