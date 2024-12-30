#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, Q;
ll arr[100005], diffArr[100005];
ll segSum[400005], lazySum[400005];
ll segGCD[400005];

ll gcdFunc(ll a, ll b) {
    if (b == 0) return a < 0 ? -a : a;
    return gcdFunc(b, a % b);
}

ll buildSum(int n, int s, int e) {
    if (s == e) {
        segSum[n] = arr[s];
        return segSum[n];
    }
    int m = (s + e) / 2;
    buildSum(n * 2, s, m);
    buildSum(n * 2 + 1, m + 1, e);
    segSum[n] = segSum[n * 2] + segSum[n * 2 + 1];
    return segSum[n];
}

void propagateSum(int n, int s, int e) {
    if (lazySum[n] != 0) {
        segSum[n] += (e - s + 1) * lazySum[n];
        if (s != e) {
            lazySum[n * 2] += lazySum[n];
            lazySum[n * 2 + 1] += lazySum[n];
        }
        lazySum[n] = 0;
    }
}

void updateSum(int n, int s, int e, int l, int r, ll val) {
    propagateSum(n, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazySum[n] += val;
        propagateSum(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    updateSum(n * 2, s, m, l, r, val);
    updateSum(n * 2 + 1, m + 1, e, l, r, val);
    segSum[n] = segSum[n * 2] + segSum[n * 2 + 1];
}

ll querySum(int n, int s, int e, int l, int r) {
    propagateSum(n, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return segSum[n];
    int m = (s + e) / 2;
    return querySum(n * 2, s, m, l, r) + querySum(n * 2 + 1, m + 1, e, l, r);
}

ll buildGCD(int n, int s, int e) {
    if (s == e) {
        segGCD[n] = diffArr[s];
        return segGCD[n];
    }
    int m = (s + e) / 2;
    ll leftG = buildGCD(n * 2, s, m);
    ll rightG = buildGCD(n * 2 + 1, m + 1, e);
    segGCD[n] = gcdFunc(leftG, rightG);
    return segGCD[n];
}

void updatePointGCD(int n, int s, int e, int idx, ll val) {
    if (idx < s || e < idx) return;
    if (s == e) {
        segGCD[n] += val;
        return;
    }
    int m = (s + e) / 2;
    updatePointGCD(n * 2, s, m, idx, val);
    updatePointGCD(n * 2 + 1, m + 1, e, idx, val);
    segGCD[n] = gcdFunc(segGCD[n * 2], segGCD[n * 2 + 1]);
}

ll queryGCD(int n, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return segGCD[n];
    int m = (s + e) / 2;
    ll leftG = queryGCD(n * 2, s, m, l, r);
    ll rightG = queryGCD(n * 2 + 1, m + 1, e, l, r);
    return gcdFunc(leftG, rightG);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 2; i <= N; i++) {
        diffArr[i] = arr[i] - arr[i - 1];
    }

    buildSum(1, 1, N);
    buildGCD(1, 2, N);

    cin >> Q;
    while (Q--) {
        ll T; int A, B;
        cin >> T >> A >> B;
        if (T != 0) {
            updateSum(1, 1, N, A, B, T);
            if (A >= 2) updatePointGCD(1, 2, N, A, T);
            if (B + 1 <= N) updatePointGCD(1, 2, N, B + 1, -T);
        }
        else {
            ll leftVal = querySum(1, 1, N, A, A);
            if (A == B) {
                cout << (leftVal < 0 ? -leftVal : leftVal) << "\n";
            }
            else {
                ll g = queryGCD(1, 2, N, A + 1, B);
                ll ans = gcdFunc(leftVal, g);
                cout << (ans < 0 ? -ans : ans) << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
