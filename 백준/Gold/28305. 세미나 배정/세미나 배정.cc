#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, T;
vector<int> a;

// 최대로 겹치는게 k일때 가능함?
bool check(int k) {
    // 시작날짜
    int st[200005];
    for(int i = 0; i < a.size(); i++) {
        if(i < k) {
            st[i] = max(1, a[i] - T + 1);
        }
        else {
            // i - k번째 세미나가 끝난 다음날 넣어야함
            st[i] = max({1, a[i] - T + 1, st[i - k] + T});
        }
    }

    for(int i = 0; i < a.size(); i++) {
        // a[i]가 [st[i], st[i] + T - 1]사이인가
        if(st[i] <= a[i] && a[i] <= st[i] + T - 1);
        else return false;
    }

    return true;
}

void solve() {
    cin >> N >> T;
    a.resize(N);
    for(int &i : a) cin >> i;

    sort(a.begin(), a.end());

    // 경계가 항상 [lo, hi]
    int lo = 0, hi = 999999;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid;
    }

    cout << hi << '\n';
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
