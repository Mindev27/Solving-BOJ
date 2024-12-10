#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, L;
int board[105][105];

bool check(vector<int>& l) {
   int visited[105];
   memset(visited, false, sizeof(visited));

    for (int i = 0; i < N - 1; i++) {
        if (l[i] == l[i + 1]) continue;

        int diff = l[i + 1] - l[i];
        if (abs(diff) != 1) return false;

        if (diff == 1) {
            for (int j = 0; j < L; j++) {
                if (i - j < 0 || visited[i - j] || l[i - j] != l[i]) 
                    return false;
                visited[i - j] = true;
            }
        } else if (diff == -1) {
            for (int j = 0; j < L; j++) {
                if (i + 1 + j >= N || visited[i + 1 + j] || l[i + 1 + j] != l[i + 1]) 
                    return false;
                visited[i + 1 + j] = true;
            }
        }
    }
    return true;
}


void solve(){
    cin >> N >> L;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<int> x(N);
        for (int j = 0; j < N; j++) {
            x[j] = board[i][j];
        }
        if (check(x)) ans++;
    }

    for (int j = 0; j < N; j++) {
        vector<int> x(N);
        for (int i = 0; i < N; i++) {
            x[i] = board[i][j];
        }
        if (check(x)) ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}