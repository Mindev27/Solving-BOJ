#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
일단 인접하려면 어떻게 생겨야하나 보자
N=5일때 인접할 수 있는 공간은 총 4개다
여기서 2개를 선택

o를 빈거 x가 인접한거라고 하면

A o A o A o A o A
A x A x A o A o A
A o A x A x A o A
A o A o A x A x A
A x A o A o A x A
...

많은데?

일단 미리 전처리하고 온라인 쿼리로 들어가면 될거고
더 관찰을 해보자
결국 인접하는 곳 좌우에는 무조건 1이와야한다.
그렇게 볼까? f(i, j) := 길이 i문자열까지 있고, 인접 개수가 j개일때 경우의 수

f(i, j) = f(i-1, j)... 에바고;

마지막이 0인지 1인지도 관리를 해야할듯
f(i, j, k) := 길이 i문자열까지 있고, 인접 개수가 j개이며 끝이 k로 끝날때 경우의 수

f(i, j, 0) = f(i-1, j, 0) + f(i-1, j, 1) // 0으로 끝날때는 앞전에서 0이던 1이던 안늘어남
f(i, j, 1) = f(i-1, j, 0) + f(i-1, j-1, 1) // 1로 끝나면 뒤에서 1이어서 개수 +1되는 경우

상태공간 2NK 전처리하면 끗

*/

int dp[105][105][2];

void precalc() {
    memset(dp, 0, sizeof(dp));

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            // 끝이 0
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];

            // 끝이 1
            dp[i][j][1] = dp[i-1][j][0];
            if (j > 0) dp[i][j][1] += dp[i-1][j-1][1];
        }
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << dp[a][b][0] + dp[a][b][1] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precalc();

    int Tc = 1;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
