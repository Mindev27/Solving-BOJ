#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double

/*
C가 굉장히 작음 심지어 N도 10

이건 10^5모든 경우를 다만들어봐라가 맞음
그럼 그렇게 해서 만들어진 요리시간이 있을때 
그 시간안에 요리를 몇개 만드는지는 어캐 찾지? 
음식개수가 좀 많은데

수학? LCM구해서 주기로 계산? 숫자가 너무 커질수도 있음
T시간동안 만든다고 하고 파라매트릭 하면 최대시간은 10^12할만함



*/

ll N, K, C, ans = LLONG_MAX;
vector<ll> v;
vector<int> cheer;

// 시간 t동안 만들때 개수가 K이상인가?
bool check(ll t, const vector<ll> &newV) {
    ll cnt = 0;
    for(ll i : newV) {
        cnt += t / i;
    }
    return cnt >= K;
}

void simulation() {
    // 응원으로 빼주기
    vector<ll> newV(v.begin(), v.end());

    for(int i : cheer) {
        newV[i] = max(1LL, newV[i] - 1);
    }

    // for(int i : cheer) cout << i << ' ';
    // cout << '\n';
    // for(ll &i : newV) cout << i << ' ';
    // cout << '\n';

    ll lo = 0, hi = 1e12 + 7;
    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid, newV)) hi = mid;
        else lo = mid;
    }

    // cout << hi << '\n';

    ans = min(ans, hi);
}

void dfs(int depth) {
    if(depth >= C) {
        simulation();
        return;
    }

    for(int i = 0; i < N; i++) {
        cheer.push_back(i);
        dfs(depth + 1);
        cheer.pop_back();
    }
}

void solve() {
    cin >> N >> K >> C;

    v.resize(N);
    for(ll &i : v) cin >> i;

    dfs(0);

    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}