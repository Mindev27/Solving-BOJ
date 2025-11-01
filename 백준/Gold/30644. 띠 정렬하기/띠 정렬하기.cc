/*
writter : exzile_27
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double

/*
일단 연결되어있는 놈들이면 쭉 이어서 자르면 됨
역순도 상관없어 일단 정렬한걸 두고 이어지는걸 생각해보자

싹다 가위질이 되고 우리는 붙이는걸 생각할거임
그럼 언제 붙일수 있는데? -> 등수가 인접한 놈들
그러면 미리 인덱싱을 박아두고 정렬해서 차이가 1나면 붙일 수 있는거잖아

*/

int N;
vector<pii> v;

void solve(){
    cin >> N;
    v.resize(N);
    int idx = 0;
    for(auto &[x, y] : v) {
        cin >> x;
        y = idx++;
    }

    sort(v.begin(), v.end()); // 값으로 정렬

    int ans = N - 1; // 가위질
    for(int i = 0; i < N - 1; i++) {
        if(abs(v[i].Y - v[i+1].Y) == 1) {
            ans--;
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