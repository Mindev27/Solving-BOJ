#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

long double r, cx,cy, xs, ys, xe, ye;

void solve() {
    cin >> r >> cx >> cy >> xs >> ys >> xe >> ye;
    
    // 직사각형 내부에 중심이 있는지 확인
    if(cx >= xs && cx <= ys && cy >= ys && cy <= ys) {
        cout << "The given circle and rectangle overlap.\n";
        return;
    }

    // 이제 외부에 중심이 있음
    // 겹칠때 모서리가 들어가는경우, 한변이랑 만나는 경우
    // 모서리랑 겹치는 경우
    // 걍 가장 가까운 점 찾자
    long double closeX = max(xs, min(cx, xe));
    long double closeY = max(ys, min(cy, ye));

    if((cx - closeX) * (cx - closeX) + (cy - closeY) * (cy - closeY) <= r * r) {
        cout << "The given circle and rectangle overlap.\n";
        return;
    }

    cout << "The given circle and rectangle do not overlap.\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}