#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, Q, MAX_ST;
ll seg[4000005];

void update(int i, ll val) {
    i += MAX_ST / 2; // 리프 인덱스 맞추기
    while(i > 0) {
        seg[i] += val;
        i /= 2;
    }
}

ll get(int L, int R, int nodeNum, int nodeL, int nodeR) {
    if(L <= nodeL && nodeR <= R) return seg[nodeNum];
    if(nodeR < L || R < nodeL) return 0;
    int mid = (nodeL + nodeR) / 2;
    return get(L, R, nodeNum * 2, nodeL, mid) 
        + get(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

void solve() {
    cin >> N >> Q;

    // [1, MAX_ST/2] 까지는 노드, [MAX_ST/2 + 1, MAX_ST]는 리프
    int expo = 0;
    while(N >= (1 << expo)) expo++;
    MAX_ST = 2 * (1 << expo) - 1;

    while(Q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1) { // y일에 z추가
            update(y, (ll)z);
        }
        else {
            cout << get(y - 1, z - 1, 1, 0, MAX_ST/2) << '\n';
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