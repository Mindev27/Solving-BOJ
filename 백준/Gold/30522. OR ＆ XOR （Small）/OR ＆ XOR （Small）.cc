#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
/*
2^10이라 결국 중복이 많음 A에서 압축하고 B에서 압축하고
미리 1024개 전처리하기

*/

void solve() {
    ll N, p; cin >> N >> p;
    vector<ll> a(N), b(N);
    for(ll &i : a) cin >> i;
    for(ll &i : b) cin >> i;

    ll acnt[1050]{};
    ll bcnt[1050]{};
    for(ll &i : a) acnt[i]++;
    for(ll &i : b) bcnt[i]++;

    // x, y에 대해서 XOR에서 OR로 바꿀때 크게 변해야함
    // 미리 전처리 클수록 이득임
    vector<pair<pll, ll>> gap; // x, y, 바꿀때 이득
    for(ll i = 0; i <= 1024; i++) {
        for(ll j = 0; j <= 1024; j++) {
            gap.push_back( {{i, j}, (i | j) - (i ^ j)} );
        }
    }

    sort(gap.begin(), gap.end(), [&](pair<pll, ll> x, pair<pll, ll> y) {
        return x.Y > y.Y;
    });

    // 각 a b조합에 대해서 계산해보자
    ll ans = 0;
    for(auto &i : gap) {
        ll x = i.X.X;
        ll y = i.X.Y;
        ll w = i.Y;

        if(acnt[x] == 0 || bcnt[y] == 0) continue;

        // cout << x <<  ' ' << y << '\n';

        ll curCnt = acnt[x] * bcnt[y]; // 현재 조합의 개수

        if(curCnt <= p) { // 지금 조합이 p보다 작음 -> 싹다 OR로 계산
            ans += 1LL * acnt[x] * bcnt[y] * (x | y);
            p -= curCnt;
        }
        else { // 딱 p개만 or로 계산하고 나머지는 xor로 계산
            ans += p * (x | y);
            ans += (curCnt - p) * (x ^ y);
            p = 0;
        }
    }

    cout << ans << '\n';
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