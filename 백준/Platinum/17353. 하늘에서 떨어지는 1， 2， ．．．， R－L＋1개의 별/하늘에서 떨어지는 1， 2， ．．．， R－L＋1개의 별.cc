#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

ll arr[1000005];
ll slopeSeg[4000005], slopeLazy[4000005];
ll interceptSeg[4000005], interceptLazy[4000005];
int N, Q;

void buildSlope(int node, int start, int end) {
    if (start == end) {
        slopeSeg[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    buildSlope(node * 2, start, mid);
    buildSlope(node * 2 + 1, mid + 1, end);
    slopeSeg[node] = slopeSeg[node * 2] + slopeSeg[node * 2 + 1];
}

void buildIntercept(int node, int start, int end) {
    if (start == end) {
        interceptSeg[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildIntercept(node * 2, start, mid);
    buildIntercept(node * 2 + 1, mid + 1, end);
    interceptSeg[node] = interceptSeg[node * 2] + interceptSeg[node * 2 + 1];
}

void slopePropagate(int node, int start, int end) {
    if (slopeLazy[node] != 0) {
        slopeSeg[node] += (end - start + 1) * slopeLazy[node];
        if (start != end) {
            slopeLazy[node * 2] += slopeLazy[node];
            slopeLazy[node * 2 + 1] += slopeLazy[node];
        }
        slopeLazy[node] = 0;
    }
}

void interceptPropagate(int node, int start, int end) {
    if (interceptLazy[node] != 0) {
        interceptSeg[node] += (end - start + 1) * interceptLazy[node];
        if (start != end) {
            interceptLazy[node * 2] += interceptLazy[node];
            interceptLazy[node * 2 + 1] += interceptLazy[node];
        }
        interceptLazy[node] = 0;
    }
}

void slopeUpdateRange(int node, int start, int end, int l, int r, ll val) {
    slopePropagate(node, start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        slopeLazy[node] += val;
        slopePropagate(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    slopeUpdateRange(node * 2, start, mid, l, r, val);
    slopeUpdateRange(node * 2 + 1, mid + 1, end, l, r, val);
    slopeSeg[node] = slopeSeg[node * 2] + slopeSeg[node * 2 + 1];
}

void interceptUpdateRange(int node, int start, int end, int l, int r, ll val) {
    interceptPropagate(node, start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        interceptLazy[node] += val;
        interceptPropagate(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    interceptUpdateRange(node * 2, start, mid, l, r, val);
    interceptUpdateRange(node * 2 + 1, mid + 1, end, l, r, val);
    interceptSeg[node] = interceptSeg[node * 2] + interceptSeg[node * 2 + 1];
}

ll slopeQueryRange(int node, int start, int end, int l, int r) {
    slopePropagate(node, start, end);
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return slopeSeg[node];
    int mid = (start + end) / 2;
    return slopeQueryRange(node * 2, start, mid, l, r)
        + slopeQueryRange(node * 2 + 1, mid + 1, end, l, r);
}

ll interceptQueryRange(int node, int start, int end, int l, int r) {
    interceptPropagate(node, start, end);
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return interceptSeg[node];
    int mid = (start + end) / 2;
    return interceptQueryRange(node * 2, start, mid, l, r)
        + interceptQueryRange(node * 2 + 1, mid + 1, end, l, r);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    buildSlope(1, 1, N);
    buildIntercept(1, 1, N);

    cin >> Q;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int L, R; cin >> L >> R;
            slopeUpdateRange(1, 1, N, L, R, 1);
            interceptUpdateRange(1, 1, N, L, R, 1 - (ll)L);
        }
        else {
            int X; cin >> X;
            ll sVal = slopeQueryRange(1, 1, N, X, X);
            ll cVal = interceptQueryRange(1, 1, N, X, X);
            cout << sVal * X + cVal << "\n";
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
