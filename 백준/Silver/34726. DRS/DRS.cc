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

ll N, T;
vector<pair<string, ll>> v;

void solve(){
    cin >> N >> T;

    for(int i = 0; i < N; i++) {
        string s; ll x; cin >> s >> x;
        v.push_back({s, x});
    }

    for(int i = 1; i < N; i++) {
        v[i].Y += v[i-1].Y;
        v[i].Y %= T;
    }

    sort(v.begin(), v.end(), [&](pair<string, ll>&a, pair<string, ll>&b) {
        return a.Y < b.Y;
    });

    vector<string> ans;
    for(int i = 0; i < N - 1; i++) {
        if(v[i+1].Y - v[i].Y <= 1000) {
            ans.push_back(v[i+1].X);
        } 
    }
    if(T - v.back().Y + v[0].Y <= 1000) ans.push_back(v[0].X);

    if(ans.empty()) {
        cout<< "-1";
        return;
    }
    sort(ans.begin(), ans.end());
    for(string s : ans) cout << s << ' ';
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