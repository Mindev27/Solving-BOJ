#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
/*
일단 나이브하게 다 만들어서 출력 O(Q*N^2) 무조건 터지고
쿼리당 수학적으로 O(1)에 뽑아내는게 정해인듯

일단 몇번째 껍질인지를 찾자 

N=5기준 총 3개의 껍질이 있음 (N개면 (N+1)/2 개의 껍질)

각 껍질에서 몇개가 있는가 
1층 -> 1~16 총 16개
2층 -> 17~24 총 8개
3층 -> 25 1개

1 8 16 24 32

1빼고 8베수로 개수가 늘어나네

t레이어 시작값은 1+4t(n-t)

1번 쿼리는 레이어 구하고 얼마나 떨어졌는가
걍 그레이어 맞추고 직접 만들기 ㄱㄱ


*/
ll getVal(int n, int x, int y) {
    int L = min(min(x-1, y-1), min(n-x, n-y));
    ll B = 1LL + 4LL * L * (n - L); // layer 시작값
    int len = n - 2*L;
    if (len == 1) return B; // 중앙

    if (x == L+1) {
        ll d = (y - (L+1));
        return B + d;
    } else if (y == n - L) {
        ll d = (len - 1) + (x - (L+1));
        return B + d;
    } else if (x == n - L) {
        ll d = 2LL*(len - 1) + ( (n - L) - y );
        return B + d;
    } else {
        ll d = 3LL*(len - 1) + ( (n - L) - x );
        return B + d;
    }
}

pii getPos(int n, ll z) {
    // L = floor((n - sqrt(n^2 - (z-1)))/2)
    ld disc = (ld)n*(ld)n - (ld)(z - 1);
    ld root = sqrtl(max((ld)0, disc));
    int L = (int)floor( ( (ld)n - root ) / 2.0L );

    ll B = 1LL + 4LL * L * (n - L);
    int len = n - 2*L;
    if (len == 1) return {L+1, L+1};

    ll d = z - B;
    if (d < len - 1) {
        return {L+1, (int)(L+1 + d)};
    } else if (d < 2LL*(len - 1)) {
        ll t = d - (len - 1);
        return {(int)(L+1 + t), n - L};
    } else if (d < 3LL*(len - 1)) {
        ll t = d - 2LL*(len - 1);
        return {n - L, (int)( (n - L) - t )};
    } else {
        ll t = d - 3LL*(len - 1);
        return { (int)( (n - L) - t ), L+1 };
    }
}

void solve() {
    int tp; cin >> tp;
    if (tp == 1) {
        int n, x, y; cin >> n >> x >> y;
        cout << getVal(n, x, y) << '\n';
    } else {
        int n; ll z; cin >> n >> z;
        auto [x, y] = getPos(n, z);
        cout << x << ' ' << y << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}
