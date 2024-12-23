#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 5;
const int SIZE = 1 << 22;
int N, K;
pii seg[SIZE];
int ans[2000005];

void changeNode(int op, int node, int val) {
    if (op == 1) { // 1이면 val보다 작은 애들은 val까지 커져야함 하한 증가
        seg[node].X = max(seg[node].X, val);
        seg[node].Y = max(seg[node].Y, val);
    }
    else { // val보다 크놈들을 val까지 작아야함 상한 감소
        seg[node].X = min(seg[node].X, val);
        seg[node].Y = min(seg[node].Y, val);
    }
}
void update(int s, int e, int node, int l, int r, int op, int val) {
    if (e < l || r < s) return;
    if (s <= l && r <= e) {
        // 현재 노드 데이터 변경
        changeNode(op, node, val);
        return;
    }

    int mid = (l + r) / 2;

    // 오른쪽 자식
    changeNode(1, node * 2 + 1, seg[node].X); // 부모 노드의 하한보다는 커야함
    changeNode(0, node * 2 + 1, seg[node].Y); // 부모 노드의 상한보다는 작아야함

    // 왼쪽 자식
    changeNode(1, node * 2, seg[node].X); // 부모 노드의 하한보다는 커야함
    changeNode(0, node * 2, seg[node].Y); // 부모 노드의 상한보다는 작아야함

    seg[node] = { 0, INF };
    update(s, e, node * 2, l, mid, op, val);
    update(s, e, node * 2 + 1, mid + 1, r, op, val);
}

void last(int node, int l, int r) {
    if (l == r) {
        ans[l] = seg[node].X;
        return;
    }

    changeNode(1, node * 2, seg[node].X);
    changeNode(0, node * 2, seg[node].Y);

    changeNode(1, node * 2 + 1, seg[node].X);
    changeNode(0, node * 2 + 1, seg[node].Y);
    seg[node] = { 0, INF };

    int mid = (l + r) / 2;
    last(node * 2, l, mid);
    last(node * 2 + 1, mid + 1, r);
}

void solve() {
    cin >> N >> K;

    fill(seg, seg + SIZE, make_pair(-INF, INF));

    while (K--) {
        int op, l, r, h;
        cin >> op >> l >> r >> h;
        update(l, r, 1, 0, N - 1, op, h);
    }

    // 다 내려주기
    last(1, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
