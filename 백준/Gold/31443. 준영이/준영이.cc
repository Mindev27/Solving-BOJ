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
dp[i][j] := i*j 크기를 자를때 최대 이득값
가로에 대해서 세로에 대해서 다 짤라보기?

1000 * 1000에 재귀들어가면 터지겠는데

뭔가 2로 최대한 많이 만들면 되지 않을까라는 생각
응 아니고

2*4조각이 있을때 4 4로 쪼개면 16임
짝짝이면 걍 2로 쪼개는게 왜 최적이 아닌가? 흠...

10조각짜리가 있다고 해보자 5 5로 쪼개면 25 2가 5개면 32
걍 무조건 큰데
홀수로 쪼개는게 좋은가?
2^500 > 3^333 인디

x가 2k라고 할때 k*k >= 2*k임
그러면 걍 반으로 계속 쪼개는게 이득인딩

500 500
250 250
125 125
홀홀로 쪼개나
그러면 말 되긴하네

걍 무조건 다 쪼갠다고 생각해보자

1000 -> 500^2 -> 250 ^4 -> 125 ^ 8 -> 63^8 + 62^8
2나 3될때까지

행열은 서로 독립인듯 
2 * 3 일때는 2^1 / 3^1인데 1^3인게 더 이득임

2 * 5... 얘는 2 3 2 3이 이득인데
아 3이 더 이득이네 왜지 ㅋㅋ


*/

const ll MOD = 1e9 + 7;

ll get(int x) {
    ll side = 1;
    
}

void solve(){
    ll N, M;
    cin >> N >> M;
    ll x = N * M;

    ll side = 1;
    if(x % 3 == 0) {
        for(int i = 0; i < x / 3; i++) {
            side = (side * 3) % MOD;
        }
    } else if(x % 3 == 1) {
        for(int i = 0; i < x / 3 - 1; i++) {
            side = (side * 3) % MOD;
        }
        if(x != 1) side = (side * 4) % MOD;

    } else {
        for(int i = 0; i < x / 3; i++) {
            side = (side * 3) % MOD;
        }
        side = (side * 2) %  MOD;
    }
    
    cout << side << '\n';
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