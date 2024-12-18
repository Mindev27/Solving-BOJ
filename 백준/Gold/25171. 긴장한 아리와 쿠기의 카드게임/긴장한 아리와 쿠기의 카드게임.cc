#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

ll N;
ll x, y, ans = 0;
ll a[505];

// 공격력 왼 오 인덱스 주어질때 가능한 체력
ll find(ll atk, ll Lidx, ll Ridx) {
    ll needHp = (((y - 1) / atk) + 1) * x; // 필요한 체력
    ll l = (Lidx == 0) ? Ridx + 1 : 0;
    ll curSum = 0;
    ll curAns = 0;
    for (ll r = l; r < N; r++) {
        if (r == Lidx) { r = Ridx; continue;}
        curSum += a[r];
        while (curSum > needHp) {
            if(r <= Lidx) curAns += (N - r) - (Ridx - Lidx + 1);
            else curAns += (N - r);
                
            curSum -= a[l];
            l++;
            if (l == Lidx) {
                l = Ridx + 1;
            }
        }
    }

    return curAns;
}
void solve() {
    cin >> N >> x >> y;
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
    }

    // l~r이 공격력
    for(ll l = 0; l < N; l++) {
        ll curSum = 0;
        for(ll r = l; r < N; r++) {
            curSum += a[r];
            ans += find(curSum, l , r);
        }
    }

    if(ans > 0) cout << ans;
    else cout << "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;   
}