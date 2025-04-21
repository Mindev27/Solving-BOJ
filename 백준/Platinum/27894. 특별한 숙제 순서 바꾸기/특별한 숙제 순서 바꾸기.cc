#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double, double>

int N;
int x[100005], a[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (a[i] != x[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "POSSIBLE";
        return;
    }

    for (int i = 0; i < N - 2; i++) {
        if (a[i] < a[i + 1] && a[i + 1] < a[i + 2]) {
            cout << "POSSIBLE";
            return;
        }
        if (a[i] > a[i + 1] && a[i + 1] > a[i + 2]) {
            cout << "POSSIBLE";
            return;
        }
    }

    cout << "IMPOSSIBLE";
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