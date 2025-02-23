/*
N^s크기의 프랙탈이고
재귀로 역으로 들어갈거임
8^10 = 2^30 = 1024 ^ 3 = 10^9 + @ = 1500000000
전체 보드의 크기는 최대 10^18임 

다 만들수는 없을듯? 굉장히 힘듦...

뭔가 R1 R2의범위가 굉장히 작음

네모가 생기는것에 규칙이 있나?

s = 3, N = 3, k = 1이다

크기는 3^3 = 27이고
27*27임

크기가 (k)*(k)인거 그리고

(k*N)*(k*N) 인거 그리고
(k*N^2) * (k*N^2) 인거 그리고

풀이:
i, j에 색이 칠해져있는지 판별하자

N^s 크기, i, j면 N*N으로 분할할때 칸이 어디인지는 알겠지

그 칸에서 가운데면 검은색 아니라면 보정해서 다시 들어가자

그렇게 모든 칸을 체크 ㅇㅇ
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

ll s, N, K, R1, R2, C1, C2;
ll sz; // 한변 길이

// d*d에서 x, y가 가운데인가 즉 색칠되었는가
bool check(ll d, ll x, ll y) {
    // cout << d << ' ' << x << ' ' << y << '\n';

    // 기저상태
    if(d == 1) return false; // 하나짜리면 흰색임

    ll curSz = d / N;

    ll xidx = x / curSz; // x에서 몇번째 영역인지
    ll yidx = y / curSz; // y에서 몇번째 영역인지

    // 짝 홀 나누자
    if(N % 2 == 0) {
        long double mid = N / 2 - 0.5f; // 가운데
        ll gap = K / 2;
        if(abs(xidx - mid) <= gap && abs(yidx - mid) <= gap) return true;
        else {
            ll newX = x % curSz;
            ll newY = y % curSz;
            return check(curSz, newX, newY);
        }
    }
    else { // 홀
        ll mid = N / 2;
        ll gap = (K+1) / 2 - 1; // 가운데랑 인덱스랑 gap이하면 검은색
        if(abs(xidx - mid) <= gap && abs(yidx - mid) <= gap) return true;
        else {
            ll newX = x % curSz;
            ll newY = y % curSz;
            return check(curSz, newX, newY);
        }
    }
}

void solve() {
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    sz = 1;
    for(int i = 0; i < s; i++) sz *= N;

    for(int i = R1; i <= R2; i++) {
        for(int j = C1; j <= C2; j++) {
            // check(sz, i, j);
            // cout << '\n';
            if(check(sz, i, j)) cout << "1";
            else cout << "0";
        }
        cout << '\n';
    }

    
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
