#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
일단 파라매트릭 서치를 해야할것 같다는 생각이 듦

d가 매우크다.
결정문제로 치환해보자 M개를 지울 수 있을때
학생들이 점프하는 최소 거리중 최댓값이 X이상일 수 있는가?

TTTT FFFF 
로 갈듯

각 루프마다 그리디하게 현재 위치에서 적어도 X가 될때까지 제거해 나가야함

*/

ll d, N, M;
vector<ll> v;

bool check(ll x) {
    int cnt = 0; // 제거한 개수
    ll cur = 0;

    for(int i = 0; i < N; i++) {
        if(v[i] - cur < x) { // v[i]는 제거하기
            cnt++;
        }
        else {
            cur = v[i];
        }
    }
    if(d - cur < x) return false; // 입구까지 거리

    return cnt <= M;
}

void solve() {
    cin >> d >> N >> M;
    
    v.resize(N);
    for(auto &i : v) cin >> i;
    
    sort(v.begin(), v.end());

    ll lo=0, hi=1e9+5;

    while(lo + 1 < hi) {
        ll mid = (lo + hi) >> 1;
        if(check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';
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