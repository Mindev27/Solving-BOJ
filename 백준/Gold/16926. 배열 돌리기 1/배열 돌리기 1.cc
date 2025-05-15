#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double, double>

void solve() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int layers = min(N, M) / 2;
    for (int l = 0; l < layers; l++) {
        vector<int> temp;
        int top = l, bottom = N - l - 1;
        int left = l, right = M - l - 1;

        for (int j = left; j <= right; j++) temp.push_back(A[top][j]);
        for (int i = top + 1; i < bottom; i++) temp.push_back(A[i][right]);
        for (int j = right; j >= left; j--) temp.push_back(A[bottom][j]);
        for (int i = bottom - 1; i > top; i--) temp.push_back(A[i][left]);

        int len = temp.size();
        int k = R % len;

        vector<int> rot(len);
        for (int i = 0; i < len; i++) {
            rot[i] = temp[(i + k) % len];
        }

        int idx = 0;
        for (int j = left; j <= right; j++) A[top][j] = rot[idx++];
        for (int i = top + 1; i < bottom; i++) A[i][right] = rot[idx++];
        for (int j = right; j >= left; j--) A[bottom][j] = rot[idx++];
        for (int i = bottom - 1; i > top; i--) A[i][left] = rot[idx++];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
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