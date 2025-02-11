#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N, K;
vector<int> v;

void solve() {
    cin >> N >> K;

    // cout << N << ' ' << (N+1) / 2 << '\n';
    if(N - ((N + 1) / 2) < K) { cout << "NIE"; return; }

    for(int i = 1; i <= N / 2; i++) {
        v.push_back(i + N / 2);
        v.push_back(i);
    }
    if(N % 2 == 1) v.push_back(N);

    for(int &i : v) cout << i << ' ';
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