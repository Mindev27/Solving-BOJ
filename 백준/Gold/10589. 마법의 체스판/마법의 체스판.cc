// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
oxoxox
xoxoxo
oxoxox


oooooo
xxxxxx
oooooo




*/

void solve() {
    int N, M;
    cin >> N >> M;

    cout << N/2 + M/2 << '\n';

    // 먼저 열을 싹다 조지기 1,j에서 N, j까지
    for(int j = 2; j <= M; j += 2) {
        cout << "1 " << j << " " << N << " " << j << '\n';
    }

    // 나머지 같아진 행들 조지기
    for(int i = 2; i <= N; i += 2) {
        cout << i << " 1 " << i << " " << M << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}
