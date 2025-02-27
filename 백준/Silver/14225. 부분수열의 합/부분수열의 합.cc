#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int MAX = 2000000;
int N;
bool tmp[MAX + 5];
bool visited[MAX + 5];

void solve() {
    cin >> N;
    fill(visited, visited + MAX + 5, false);
    visited[0] = true;

    for(int i = 0; i < N; i++) {
        fill(tmp, tmp + MAX + 5, false);
        int x; cin >> x;
        
        for(int i = 0; i <= MAX; i++) {
            if(visited[i] && x + i <= MAX) {
                tmp[x + i] = true;
                tmp[i] = true;
            }
        }
        tmp[x] = true;

        for(int i = 0; i <= MAX; i++) {
            visited[i] = tmp[i];
        }
    }

    for(int i = 1; i <= MAX; i++) {
        if(!visited[i]) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
