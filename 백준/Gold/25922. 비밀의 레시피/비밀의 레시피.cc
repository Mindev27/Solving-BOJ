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

void solve() {
    ll N; cin >> N;
    ll B = 1000000000;
    cout << "? 1000000000\n";
    cout << flush;
    ll v; cin >> v;

    vector<ll> a(N+1);
    for(ll i = 0; i <= N; i++){
        a[i] = v % B;
        v /= B;
    }
    cout << "! ";
    for(ll i = 0; i <= N; i++){
        if(i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    cout << flush;

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
