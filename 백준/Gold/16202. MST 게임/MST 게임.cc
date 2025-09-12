#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, M, k;
int p[1005];
pii edges[10005];

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);

    if(x < y) p[y] = x;
    else p[x] = y;
}

int kruscal(int start) { // start부터 간선 가져감
    vector<pair<pii, int>> v;
    for(int i = start; i < M; i++) {
        v.push_back({edges[i], i + 1});
    }

    for(int i = 1; i <= N; i++) p[i] = i;

    // 어차피 가중치는 idx+1임
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        int a = v[i].X.X;
        int b = v[i].X.Y;
        int w = v[i].Y;

        // cout << a << ' ' << b << ' ' << w << '\n';
        // cout << find(a) << ' ' << find(b) << '\n';

        if(find(a) == find(b)) continue;
        merge(a, b);
        ans += w;
        cnt++;
        // cout << "ans : " << ans  << '\n';
    }

    if(cnt == N-1) return ans;
    else return 0;
}

void solve() {
    cin >> N >> M >> k;

    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        edges[i].X = a;
        edges[i].Y = b;
    }

    // 가장작은건 크루스칼에서 무조건 선택.
    // 그러면 MST에서 젤 작은 가중치 간선은 무조건 젤 작은거임
    // 얘를 없애고 MST를 돌리자

    int idx = 0;
    while(k--) {
        int ans = kruscal(idx);
        cout << ans << ' ';
        idx++;
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