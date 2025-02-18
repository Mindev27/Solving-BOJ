#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

void solve() {
    int N, D;

    while(true) {
        cin >> N >> D;
        if(N == 0 && D == 0) break;

        vector<int> sum(N, 0);
        vector<stack<int>> v;
        int mx = -1;

        for(int i = 0; i < N; i++) {
            stack<int> tmp;
            int x; cin >> x;
            int s = 0;

            while(x--) {
                int a; cin >> a;
                s += a;
                tmp.push(a);
            }

            v.push_back(tmp);
            sum[i] = s;
            mx = max(mx, s);
        }

        // 그리디하게 큰 것부터 없애기
        bool flag = true;
        while(true) {
            int target = -1;
            int newMax = -1;
            for(int i = 0; i < N; i++) { // i번째를 제거하면

                // i를 제거할때 max값
                int tmpMax = -1;
                for(int j = 0; j < N; j++) {
                    if(v[j].empty()) continue;
                    if(i == j) tmpMax = max(tmpMax, sum[j] - v[j].top());
                    else tmpMax = max(tmpMax, sum[j]);
                }
                if(!v[i].empty() && tmpMax - (sum[i] - v[i].top()) <= D) {
                    target = i;
                    break;
                }
            }

            if(target == -1) {
                flag = false;
                break;
            }

            sum[target] -= v[target].top();
            v[target].pop();

            // 새로운 최대값을 구하기
            for(int i = 0; i < N; i++)
                newMax = max(newMax, sum[i]);

            mx = newMax;

            // 다 폐기했으면 끗
            bool allEmpty = true;
            for(int i = 0; i < N; i++) {
                if(!v[i].empty()) {
                    allEmpty = false;
                    break;
                }
            }
            if(allEmpty) break;
        }

        if(flag) cout << "Yes\n";
        else cout << "No\n";
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
