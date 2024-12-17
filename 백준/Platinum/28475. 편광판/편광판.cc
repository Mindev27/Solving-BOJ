#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, m;
int a[200005];
bool seg[1000005];
 
// 리프에는 편광판 사이에 지나다닐 수 있는지를 확인
bool init(int node, int s, int e){
    if(s==e) {
        if(abs(a[s] - a[s + 1]) == 2 || abs(a[s] - a[s + 1]) == 6) {
            seg[node] = false;
        }
        else seg[node] = true;
        return seg[node];
    }
    bool left = init(node*2, s, (s+e)/2);
    bool right = init(node*2+1, (s+e)/2+1, e);

    return seg[node]= left && right;
}
 
void update(int node, int s, int e, int idx){
    if(s <= idx && idx <= e){
        if(s==e) {
            if(abs(a[s] - a[s + 1]) == 2 || abs(a[s] - a[s + 1]) == 6) {
                seg[node] = false;
            }
            else seg[node] = true;
        }
        else{
            update(node*2, s, (s+e)/2, idx);
            update(node*2+1, (s+e)/2+1, e, idx);
            seg[node] = seg[node*2] && seg[node*2+1];
        }
    }
}
 
bool query(int node, int s, int e, int l, int r){
    if(e < l || r < s) return true;
    else if(l <= s && e <= r) return seg[node];
    else return query(node*2, s, (s+e)/2, l, r) && query(node*2+1, (s+e)/2+1, e, l, r);
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    init(1, 0, n-2);

    while(m--){
        int q, x, y;
        cin >> q >> x >> y;
        if(q == 1){
            a[x-1] = y;
            if(x > 1) update(1, 0, n-2, x-2);
            if(x < n) update(1, 0, n-2, x-1);
        }
        else{
            cout << (query(1, 0, n-2, x-1, y-2) ? 1 : 0) <<'\n';
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