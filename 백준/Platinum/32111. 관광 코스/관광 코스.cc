// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
OXOXO
+-+-+

이걸 어떻게 찾는가?
-가 있으면 그자리는 X임

일단 되는지 안되는지 구별법부터 생각해보자
한바퀴를 돌았다고 했을때 한바퀴의 전체 합이 -라면 
모든칸이 X일거임

안되는 조합이 있나 하나만 O인경우는 안되네

----+
XXXXX

---+++
XXXOXX

+가 과반이어야한다.

N이 홀일때는 O가 하나인게 불가능하고
N이 짝일때는 O가 하나인게 가능

OOOOXO

O인경우에는 +여야한다. 반드시 이건 확정임
X인 경우에는 바로 그자리에서 -로 죽거나 가다가 죽거나

X가 연속된다면 XXX +--로 되잖아
짝수면 안되는듯 XXXX ++--이거 앞에사는데






*/

void solve() {
    int N; cin >> N;
    string s; cin >> s;

    
    bool hasO = false;
    for (char c : s) if (c == 'O') { hasO = true; break; }
    if (!hasO) {
        cout << "YES\n";
        cout << string(N, '-') << "\n";
        return;
    }

    string ans(N, '?');
    for (int i = 0; i < N; i++) if (s[i] == 'O') ans[i] = '+';

    int start = -1;
    for (int i = 0; i < N; i++) if (s[i] == 'O') { start = i; break; }

    int i = (start + 1) % N;
    while (i != start) {
        if (s[i] == 'O') {
            i = (i + 1) % N;
            continue;
        }

        
        vector<int> pos;
        while (s[i] == 'X') {
            pos.push_back(i);
            i = (i + 1) % N;
            if (i == start) break; 
        }

        int L = (int)pos.size();
        if (L % 2 == 0) {
            cout << "NO\n";
            return;
        }

        for (int k = 0; k < L; k++) {
            if (k == L - 1) ans[pos[k]] = '-';
            else ans[pos[k]] = (k % 2 == 0 ? '+' : '-');
        }
    }

    cout << "YES\n";
    cout << ans << "\n";
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
