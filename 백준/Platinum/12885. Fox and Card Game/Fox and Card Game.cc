#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double, double>

int N;
vector<int> cards[105];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int cnt; cin >> cnt;
        while (cnt--) {
            int x; cin >> x;
            cards[i].push_back(x);
        }
    }

    int a = 0, b = 0;
    vector<int> left;
    for (int i = 0; i < N; i++) {
        if (cards[i].size() % 2 == 0) { // 짝수면 무조건 반반임
            for (int j = 0; j < cards[i].size() / 2; j++) {
                a += cards[i][j];
                // cout << "a : " << a << '\n';
            }
            for (int j = 0; j < cards[i].size() / 2; j++) {
                b += cards[i][j + cards[i].size() / 2];
                // cout << "b : " << b << '\n';
            }
        }
        else { // 홀수면 양쪽 가져가고 가운뎃 값만 남을거임
            for (int j = 0; j < cards[i].size() / 2; j++) {
                a += cards[i][j];
                // cout << "a : " << a << '\n';
            }
            left.push_back(cards[i][cards[i].size() / 2]);
            for (int j = 0; j < cards[i].size() / 2; j++) {
                b += cards[i][j + cards[i].size() / 2 + 1];
                // cout << "b : " << b << '\n';
            }
        }
    }

    // 남은거 내림차순하고 하나씩 가져가는게 최선
    sort(left.rbegin(), left.rend());

    for (int i = 0; i < left.size(); i++) {
        // cout << left[i] << '\n';
        if (i % 2 == 0) a += left[i];
        else b += left[i];
    }

    cout << a << ' ' << b << '\n';
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
