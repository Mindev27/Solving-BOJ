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
일단 재배열 부등식으로 큰거끼리 작은거끼리 곱하는게 최적임
결국 x랑 x-1을 다 고려해야할듯
일단 막대가 10000개이긴해
NlogN이나 N으로 뚫는거

일단 역순정렬해서 젤위에 4개를 볼때 되는지 안되는지 다 체크하면 2^4 = 16임
일단 되면 그거 빼면 되지 ㅇㅇ
안되면 가장 큰거 버려 어차피 못쓰잖아. 큰것과 작은것을 섞을때가 있나? -> 재배열 부등식으로 컷

그럼 싹다 해보기 굿
왜 틀리는가

11 10 7 3 3
이거면 못찾긴하네 걍 쌍으로 처리해야할듯



*/

int N;
ll ans = 0;

void solve(){
    cin >> N;
    priority_queue<ll> pq;
    for(int i = 0; i < N; i++){
        ll x; cin >> x;
        pq.push(x);
    }

    // 한 변 후보
    priority_queue<ll> side;

    while(pq.size() >= 2){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();

        if(a == b){
            side.push(a);
        }
        else if(a - 1 == b){
            side.push(b);
        }
        else{
            pq.push(b);
        }
    }

    ll ans = 0;
    while(side.size() >= 2){
        ll x = side.top(); side.pop();
        ll y = side.top(); side.pop();
        ans += x * y;
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