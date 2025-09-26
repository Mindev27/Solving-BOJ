#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>

/*
한 사이클짜리 순열이 되어야함

이렇게 되는게 몇개있지
(n-1)!이면 다 못함
결국 애네들이 사이클들로 분할될텐데
하나씩 끊어서 싹다 연결시키면 되잖아
그럼 사이클 개수만 세자
*/

int N;
bool visited[55];
vector<int> v;

void dfs(int x) {
    if(visited[x]) return;
    visited[x] = true;

    dfs(v[x]);
}

void solve() {
    cin >> N;
    v.resize(N);
    for(int &i : v) cin >> i;

    
    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            cnt++;
            dfs(i);
        }
    }

    if(cnt == 1) cout << 0;
    else cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}
