#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

// 일단 K이상이면 무조건 되니까 1개만 씀
// 되는 조합의 수만 세면 된다. 순서는 정렬됨 상관 X
// K미만 숫자들을 잘 매칭시켜야함

int N, K, ans = 0;
vector<int> v;

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x >= K) ans++;
        else v.push_back(x);
    }

    sort(v.begin(), v.end());
    for (int l = 0, r = v.size() - 1; l < r;) {
        if (v[l] + v[r] >= K) {
            ans++;
            l++, r--;
        }
        while (l < r && v[l] + v[r] < K) {
            l++;
        }
    }

    cout << (ans == 0 ? -1 : ans) << '\n';
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