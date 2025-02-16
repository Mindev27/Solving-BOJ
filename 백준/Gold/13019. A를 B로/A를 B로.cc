#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

string a, b;

void solve() {
    cin >> a;
    cin >> b;

    // b랑 a의 하나씩 매칭할거임
    int cnt = 0;

    for(int i = a.size() - 1, j = b.size() - 1; i >= 0; i--) {
        if(a[i] == b[j]) {
            j--;
        }
        else cnt++;    
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a == b) cout << cnt;
    else cout << "-1";
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