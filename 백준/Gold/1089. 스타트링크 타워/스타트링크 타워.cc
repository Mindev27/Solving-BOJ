#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

char num[10][5][3] = {
    { {'#','#','#'}, {'#','.','#'}, {'#','.','#'}, {'#','.','#'}, {'#','#','#'} }, // 0
    { {'.','.','#'}, {'.','.','#'}, {'.','.','#'}, {'.','.','#'}, {'.','.','#'} }, // 1
    { {'#','#','#'}, {'.','.','#'}, {'#','#','#'}, {'#','.','.'}, {'#','#','#'} }, // 2
    { {'#','#','#'}, {'.','.','#'}, {'#','#','#'}, {'.','.','#'}, {'#','#','#'} }, // 3
    { {'#','.','#'}, {'#','.','#'}, {'#','#','#'}, {'.','.','#'}, {'.','.','#'} }, // 4
    { {'#','#','#'}, {'#','.','.'}, {'#','#','#'}, {'.','.','#'}, {'#','#','#'} }, // 5
    { {'#','#','#'}, {'#','.','.'}, {'#','#','#'}, {'#','.','#'}, {'#','#','#'} }, // 6
    { {'#','#','#'}, {'.','.','#'}, {'.','.','#'}, {'.','.','#'}, {'.','.','#'} }, // 7
    { {'#','#','#'}, {'#','.','#'}, {'#','#','#'}, {'#','.','#'}, {'#','#','#'} }, // 8
    { {'#','#','#'}, {'#','.','#'}, {'#','#','#'}, {'.','.','#'}, {'#','#','#'} }  // 9
};

void solve() {
    int n;
    cin >> n;

    vector<string> board(5);
    for (int i = 0; i < 5; i++) {
        cin >> board[i];
    }

    vector<vector<int>> possible(n);
    for (int i = 0; i < n; i++) {
        int sy = i * 4;
        for (int target = 0; target <= 9; target++) { // 확인 할 수
            bool flag = true;

            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 3; y++) {
                    if (num[target][x][y] == '.' && board[x][sy + y] == '#') { // 없는데 있는경우
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }

            if (flag) {
                possible[i].push_back(target);
            }
        }

        if (possible[i].empty()) {
            cout << -1 << '\n';
            return;
        }

    }

    ll totalSum = 0;
    ll totalMul = 1;

    for (int i = 0; i < n; i++) {
        totalMul *= possible[i].size();
    }

    for (int i = 0; i < n; i++) {
        ll offset = pow(10, n - 1 - i);
        ll curSum = 0;

        for (int x : possible[i]) {
            curSum += x;
        }
        ll times = totalMul / possible[i].size(); // 등장 횟수

        totalSum += curSum * offset * times;
    }


    cout << fixed << setprecision(5) << (double)totalSum / totalMul << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) {
        solve();
    }

    return 0;
}
