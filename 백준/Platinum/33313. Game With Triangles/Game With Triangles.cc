#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

ll search(int k, int x_min, int x_max, const vector<ll>& sA, const vector<ll>& sB, int maxPairsA, int maxPairsB) {
    ll best = 0;
    for (int iter = 0; iter < 50; iter++) {
        if (x_max - x_min < 3) break;
        int leftT = x_min + (x_max - x_min) / 3;
        int rightT = x_max - (x_max - x_min) / 3;

        ll valL = -1, valR = -1;
        int yL = k - leftT;
        int yR = k - rightT;

        if (leftT >= 0 && leftT <= maxPairsA && yL >= 0 && yL <= maxPairsB) {
            valL = sA[leftT] + sB[yL];
        }
        if (rightT >= 0 && rightT <= maxPairsA && yR >= 0 && yR <= maxPairsB) {
            valR = sA[rightT] + sB[yR];
        }

        if (valL != -1) best = max(best, valL);
        if (valR != -1) best = max(best, valR);

        if (valL < valR) {
            x_min = leftT + 1;
        }
        else {
            x_max = rightT - 1;
        }
    }

    for (int xi = x_min; xi <= x_max; xi++) {
        int y = k - xi;
        if (xi < 0 || xi > maxPairsA) continue;
        if (y < 0 || y > maxPairsB) continue;
        best = max(best, sA[xi] + sB[y]);
    }
    return best;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int j = 0; j < m; j++) cin >> B[j];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int maxPairsA = n / 2;
    int maxPairsB = m / 2;

    vector<ll> sA(maxPairsA + 1, 0), sB(maxPairsB + 1, 0);
    for (int x = 1; x <= maxPairsA; x++) {
        sA[x] = sA[x - 1] + (A[n - x] - A[x - 1]);
    }
    for (int y = 1; y <= maxPairsB; y++) {
        sB[y] = sB[y - 1] + (B[m - y] - B[y - 1]);
    }

    int k_max = (n + m) / 3;
    while (k_max > 0) {
        int x_min = max(0, 2 * k_max - m);
        int x_max = min(k_max, n - k_max);
        if (x_min <= x_max) break;
        k_max--;
    }

    cout << k_max << "\n";

    for (int k = 1; k <= k_max; k++) {
        int x_min = max(0, 2 * k - m);
        int x_max = min(k, n - k);
        ll best = search(k, x_min, x_max, sA, sB, maxPairsA, maxPairsB);
        if (k > 1) cout << ' ';
        cout << best;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}