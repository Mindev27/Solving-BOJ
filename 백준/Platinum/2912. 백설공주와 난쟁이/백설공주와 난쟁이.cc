// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*

*/

int n, c, m;
int sqrtN;
vector<int> v;

struct Query {
    int idx, s, e;
    bool operator<(const Query &x) const {
        int b1 = s / sqrtN;
        int b2 = x.s / sqrtN;
        if (b1 != b2) return b1 < b2;
        return e < x.e;
    }
};

vector<Query> query;
int cnt[1000005];
int ans[1000005];

void solve() {
    cin >> n >> c;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        query.push_back({i, a, b});
    }

    sqrtN = max(1, (int)sqrt(n));

    sort(query.begin(), query.end());

    int L = 1, R = 0;

    for (auto &qq : query) {
        int s = qq.s;
        int e = qq.e;

        while (L > s) cnt[v[--L]]++;
        while (R < e) cnt[v[++R]]++;
        while (L < s) cnt[v[L++]]--;
        while (R > e) cnt[v[R--]]--;

        int len = e - s + 1;
        int maj = 0;

        for (int color = 1; color <= c; color++) {
            if (cnt[color] * 2 > len) {
                maj = color;
                break;
            }
        }

        ans[qq.idx] = maj;
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == 0)  cout << "no\n";
        else cout << "yes " << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}