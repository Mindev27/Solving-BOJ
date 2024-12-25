#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M, maxA, maxB;
void solve() {
    cin >> N;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
        maxA = max(maxA, a);
    }

    cin >> M;
    vector<int> B(M);
    for (int& b : B) {
        cin >> b;
        maxB = max(maxB, b);
    }

    int mx = max(maxA, maxB);
    auto itA = A.begin(), itB = B.begin();
    vector<int> ans;

    for (int i = mx; i >= 1; i--)
    {
        while (true)
        {
            auto nxt_a = find(itA, A.end(), i), nxt_b = find(itB, B.end(), i);
            if (nxt_a == A.end() || nxt_b == B.end())
                break;

            ans.push_back(i);
            itA = next(nxt_a), itB = next(nxt_b);
        }
    }

    cout << ans.size() << endl;
    for (int v : ans) cout << v << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) {
        solve();
    }

    return 0;
}