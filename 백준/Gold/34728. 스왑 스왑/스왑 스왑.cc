/*
writter : exzile_27
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double

/*

*/


void solve(){
    int N; cin >> N;
    vector<int> v(N);

    int cnt = 0;
    for(int &i : v) cin >> i;
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-1; j++) {
            if(v[j] > v[j+1]) {
                cnt++;
                swap(v[j], v[j+1]);
            }
        }
    }

    cout << (cnt % 2 == 1 ? "No": "Yes");
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