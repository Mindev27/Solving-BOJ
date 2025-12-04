// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>


void solve() {
    int n;
    cin >> n;

    

    if (n == 3) {
        cout << "2 to -1\n";
        cout << "5 to 2\n";
        cout << "3 to -3\n";
        return;
    }

    int i = 0;
    int x = -1;
    
    for (i = 0; i < n - 7; i += 4) {
        cout << 2 * n - 2 - i << " to " << -1 + i << "\n";
        cout << 3 + i << " to " << 2 * n - 2 - i << "\n";
    }

    int rem = n - i;

    if (rem == 4) {
        for (int j : {6, 3, 0, 7}) {
            cout << j + i << " to " << x + i << "\n";
            x = j;
        }
    }
    else if (rem == 5) {
        for (int j : {8, 3, 6, 0, 9}) {
            cout << j + i << " to " << x + i << "\n";
            x = j;
        }
    }
    else if (rem == 6) {
        for (int j : {10, 7, 2, 6, 0, 11}) {
            cout << j + i << " to " << x + i << "\n";
            x = j;
        }
    }
    else if (rem == 7) {
        for (int j : {8, 5, 12, 3, 9, 0, 13}) {
            cout << j + i << " to " << x + i << "\n";
            x = j;
        }
    }

    for (i = i - 4; i >= 0; i -= 4) {
        cout << i << " to " << 2 * n - 5 - i << "\n";
        cout << 2 * n - 1 - i << " to " << i << "\n";
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
