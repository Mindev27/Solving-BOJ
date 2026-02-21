// Writer : exzile_27
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

/*
항상 제곱으로 커진다.
그말은 즉 max(X,Y)를 관리해야한다는것

O(N)으로 똑똑하게 해결하는법이 있을듯

1100100
0100011
S->T 는 몇번이지?

2번
1100001
6번
1000011
7반
0100011

그냥 K회를 반반 쪼개서 제곱후 더하기?인듯
*/


void solve() {
    int N, M;
    cin >> N >> M;

    int len = N+M;

    string s, t; cin >> s >> t;

    vector<int> oneS, oneT; // s에서 1위치


    for(int i = 0; i < len; i++) {
        if(s[i] == '1') oneS.push_back(i);
        if(t[i] == '1') oneT.push_back(i);
    } 

    ll cnt = 0;
    for(int i = 0; i < M; i++) {
        cnt += abs(oneS[i] - oneT[i]);
    }

    if(cnt%2==0) {
        cout << 2LL * (cnt/2) * (cnt/2) << '\n';
    }
    else {
        cout << 1LL * (cnt/2) * (cnt/2) + 1LL * (cnt/2+1)*(cnt/2+1) << '\n';
    }
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