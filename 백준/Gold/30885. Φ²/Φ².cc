#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first 
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first 
#define Y second
#define pii pair<int, int>

ll N;
stack<pll> s1, s2;

void solve() {
    cin >> N;
    for (ll i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        s1.push({ x, i });
    }

    while (s1.size() + s2.size() > 1) {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        auto [cur, idx] = s2.top();
        s2.pop();
        ll add = 0;

        if (!s1.empty() && s1.top().X <= cur) {
            add += s1.top().X;
            s1.pop();
        }

        if (!s2.empty() && s2.top().X <= cur) {
            add += s2.top().X;
            s2.pop();
        }

        s1.push({ cur + add, idx });
    }

    cout << s1.top().X << '\n' << s1.top().Y;
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
