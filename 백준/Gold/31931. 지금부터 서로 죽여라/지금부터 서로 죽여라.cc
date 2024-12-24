#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Player {
    ll hp, atk, heal;
}N, S;

void solve() {
    cin >> N.hp >> S.hp;
    cin >> N.atk >> N.heal >> S.atk >> S.heal;

    // 나루토 원콤
    if (N.atk >= S.hp) {
        cout << "NARUTO\n"; return;
    }

    // 나루토가 이기는지 확인

    // 원콤을 못내면 나루토가 때리는게 사스케 힐보다 커야 승산이 있다. 아님 못이김
    if (N.atk > S.heal) {
        // 중간에 힐을 섞어가면서 때리는게 이득인가
        if (N.heal > S.atk) {
            cout << "NARUTO\n"; return;
        }

        __int128 canHit = (N.hp + S.atk - 1) / S.atk; // 몇번 때릴 수 있는가
        if (canHit * N.atk >= S.hp) {
            cout << "NARUTO\n"; return;
        }
    }

    // 이제 나루토가 이기는 미래는 없다.


    // 사스케 원콤
    if (S.atk >= N.hp + N.heal) {
        cout << "SASUKE\n"; return;
    }

    // 사스케 공격 > 나루토 힐 (이렇게 해야 공격이 의미가 있다.)
    if (S.atk > N.heal) {
        // 힐하면서 때리기
        if (S.heal > N.atk) {
            cout << "SASUKE\n"; return;
        }

        __int128 canHit = (S.hp + N.atk - 1) / N.atk - 1; // 한대 맞음음
        if (canHit * S.atk >= N.hp) {
            cout << "SASUKE\n"; return;
        }

    }

    // 아무도 못이김
    cout << "DRAW\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    while (Tc--) {
        solve();
    }

    return 0;
}
