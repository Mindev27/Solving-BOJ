#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
일단 굉장히 붙어있는경우가 많이 나오고 대부분 1로 빠질듯
일단 0개수랑 1개수가 3배수여야하고

쿼리마다 n을 돌면 터지는데? 걍 무조건 전처리로 O(1)로 해야함

0 1 0 1 0 1
얘는 일단 비용이 2+1 =3 임

0 1 0 1 0 1 0 1 0 1 0 1
1 1 0 1 0 1 0 1 1
0 0 1 0 1 1
얘는 2 + 1 + 1 + 1

걍 처음에 붙어있는거 하나도 없는지 있는지 체크하면 될듯

*/

int N, Q;
vector<int> v;
vector<int> prefone, prefzero;

int getone(int l, int r) {
    return prefone[r] - prefone[l-1];
}

int getzero(int l, int r) {
    return prefzero[r] - prefzero[l-1];
}

void solve() {
    cin >> N >> Q;
    v.resize(N+1);
    for(int i = 1; i <= N; i++) cin >> v[i];

    prefone.resize(N+1, 0);
    prefzero.resize(N+1, 0);

    for(int i = 1; i <= N; i++) {
        if(v[i] == 1) {
            prefone[i] = prefone[i-1] + 1;
            prefzero[i] = prefzero[i-1];
        }
        else {
            prefone[i] = prefone[i-1];
            prefzero[i] = prefzero[i-1] + 1;
        }
    }

    vector<int> prefEq(N+1, 0);
    for (int i = 1; i <= N-1; i++) {
        prefEq[i] = prefEq[i-1] + (v[i] == v[i+1] ? 1 : 0);
    }
    prefEq[N] = prefEq[N-1];


    while (Q--) {
        int a, b; cin >> a >> b;

        int one = getone(a, b);
        int zero = getzero(a, b);
        if (one % 3 != 0 || zero % 3 != 0) {
            cout << "-1\n";
            continue;
        }

        int ans = one/3 + zero/3;
        if (ans == 0) {
            cout << "0\n";
            continue;
        }

        int flag = prefEq[b-1] - prefEq[a-1];
        cout << ans + (flag == 0 ? 1 : 0) << '\n';
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