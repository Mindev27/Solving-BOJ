#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

ll N;
ll cnt[200005];
vector<ll> v;      // distinct한 숫자 모음 

void solve() {
    memset(cnt, 0, sizeof(cnt));
    v.clear();

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll k; cin >> k;
        v.push_back(k);
        cnt[k]++;
    }

    // cout << "v : ";
    // for(int &i : v) cout << i << ' ';
    // cout << '\n';
    ll ans = 0;

    if (cnt[0] >= 2) { // 어떤 숫자를 넣어도 가능
        ans += (cnt[0] * (cnt[0] - 1) / 2) * (N - cnt[0]); // (0, 0, x) 조합
        ans += cnt[0] * (cnt[0] - 1) * (cnt[0] - 2) / 6; // 0끼리 조합 
    }

    if (cnt[1] >= 1) {
        for (ll i = 2; i <= 200000; i++) {
            if (cnt[i] >= 2) {
                ans += cnt[1] * (cnt[i] * (cnt[i] - 1)) / 2; // 1개수 * (cnt[i]개중 2개 뽑기)
            }
        }

        // 1끼리
        ans += cnt[1] * (cnt[1] - 1) * (cnt[1] - 2) / 6;
    }

    sort(v.begin(), v.end());

    for (ll i = 0; i < v.size(); i++) {
        if (v[i] == 0 || v[i] == 1) continue;
        for (ll j = i + 1; j < v.size(); j++) {
            if (v[j] == 0 || v[j] == 1) continue;

            ll want = v[i] * v[j];
            if (want > 200000) continue;
            ans += cnt[want];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}