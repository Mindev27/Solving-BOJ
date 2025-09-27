#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
일단 쉽게 말해서 모든 쌍에 대해서 
Y를 swap할때 그 값이 있어야함

x가 같으면 어차피 둘이 바꾸는거라 상관없음
x가 다를때가 좀 복잡

a b
c d
-> (a, d) (c, b) 이런게 있어야함

그러면 일단 a b가 있어

a랑 다른 x좌표에 n m k가 있으면
n b / m b / k b 다 있어야함

2 3
-2 3 이거 되잖아

x좌표 기준으로 모았을때 있는것들이 같으면 무조건 되는듯

*/

void solve() {
    int N;
    map<int, vector<int>> p; // x좌표에 해당하는 y들

    cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        p[x].push_back(y);
    }


    for (auto &kv : p) {
        sort(kv.Y.begin(), kv.Y.end());
    }

    auto it = p.begin();
    vector<int> base = it->Y;
    bool ok = true;

    for (++it; it != p.end(); ++it) {
        if (it->Y != base) {
            ok = false;
            break;
        }
    }

    if (ok) cout << "BALANCED\n";
    else cout << "NOT BALANCED\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc;
    cin >> Tc;
    while (Tc--) solve();
    return 0;
}