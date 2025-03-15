#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N, ans;
vector<int> cards;

bool canWin() {
    int winCnt = 0;
    for (int i = 0; i < N; i++) {
        int me = cards[i * 2];
        int you = cards[i * 2 + 1];

        if (me > you) winCnt++;
        else if (me < you) winCnt--;
    }

    // for (int& i : cards) cout << i << ' ';
    // cout << '\n';
    // cout << winCnt << '\n';
    if (winCnt > 0) return true;
    else return false;
}

// x번째를 앞으로 올릴때, 바꾼횟수 change
void DFS(int x, int change) {
    if (change >= ans) return;

    if (canWin()) {
        ans = min(ans, change);
        return;
    }

    for (int i = 1; i < 2 * N; i++) {
        int tmp = cards[i];
        cards.erase(cards.begin() + i);
        cards.insert(cards.begin(), tmp);

        DFS(i, change + 1); // i번째를 앞으로

        cards.erase(cards.begin());
        cards.insert(cards.begin() + i, tmp);
    }
}

void solve() {
    cin >> N;
    ans = 2 * N - 1;

    for (int i = 0; i < 2 * N; i++) {
        char x; cin >> x;
        if (x == 'X') cards.push_back(0);
        else cards.push_back(1);
    }

    if (canWin()) {
        cout << 0;
        return;
    }

    for (int i = 1; i < 2 * N; i++) {
        int tmp = cards[i];
        cards.erase(cards.begin() + i);
        cards.insert(cards.begin(), tmp);

        DFS(i, 1); // i번째를 앞으로

        cards.erase(cards.begin());
        cards.insert(cards.begin() + i, tmp);
    }

    cout << ans;
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
