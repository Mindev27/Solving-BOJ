#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int K, N;
vector<pii> v;
int ans[5][100005]; // 1-base

void solve() {
    v.push_back({ 0,0 }); // 인덱스 맞추기 

    cin >> K >> N;
    int a[300005];
    for (int i = 1; i <= K; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= K; i++) {
        int b; cin >> b;
        v.push_back({ a[i], b });
    }

    vector<int> xxxy, xxxyy, xxxyyy, xxy, xxyy, xy;

    // 개수 싹다 정리 
    for (int i = 1; i <= K; i++) {
        // cout << v[i].X << ' ' << v[i].Y << '\n';
        if (v[i].X == 3 && v[i].Y == 3) xxxyyy.push_back(i);
        else if (v[i].X == 2 && v[i].Y == 3) xxxyy.push_back(i);
        else if (v[i].X == 1 && v[i].Y == 3) xxxy.push_back(i);
        else if (v[i].X == 2 && v[i].Y == 2) xxyy.push_back(i);
        else if (v[i].X == 1 && v[i].Y == 2) xxy.push_back(i);
        else xy.push_back(i);
    }


    int idx = 1;

    // 3*3 다쓰기
    while (xxxyyy.size() > 0) {
        int x3y3 = xxxyyy.back(); xxxyyy.pop_back();
        for (int j = idx; j < idx + 3; j++) {
            ans[1][j] = ans[2][j] = ans[3][j] = x3y3;
        }
        idx += 3;
    }

    // 3*2 다쓰기
    while (xxxyy.size() > 0) {
        int x3y2 = xxxyy.back(); xxxyy.pop_back();
        for (int j = idx; j < idx + 2; j++) {
            ans[1][j] = ans[2][j] = ans[3][j] = x3y2;
        }
        idx += 2;
    }

    // 2*2랑 1*2를 먼저 치워야함
    while (xxyy.size() > 0 && xxy.size() > 0) {
        int idx22 = xxyy.back(); xxyy.pop_back();
        int idx12 = xxy.back(); xxy.pop_back();

        // 3 * 2넣기
        for (int j = idx; j < idx + 2; j++) {
            ans[1][j] = idx12;
            ans[2][j] = ans[3][j] = idx22;
        }
        idx += 2;
    }

    // 2*2 3개, 3*1 2개 치우기
    while (xxyy.size() >= 3 && xxxy.size() >= 2) {

        // 3 * 6넣기
        int idx22, idx31;
        for (int j = idx; j < idx + 6; j++) {
            if (j == idx || j == idx + 2 || j == idx + 4) { // 2칸마다
                idx22 = xxyy.back();
                xxyy.pop_back();
            }
            if (j == idx || j == idx + 3) { // 3칸마다
                idx31 = xxxy.back();
                xxxy.pop_back();
            }
            ans[1][j] = idx31;
            ans[2][j] = ans[3][j] = idx22;
        }
        idx += 6;
    }


    // 2*2 3개, 3*1 1개 1*1 1개 치우기
    while (xxyy.size() >= 3 && xxxy.size() >= 1 && xy.size() >= 1) {

        // 3 * 4넣기
        int idx22, idx31;
        idx31 = xxxy.back(); xxxy.pop_back();

        for (int j = idx; j < idx + 4; j++) {
            if ((j - idx) % 2 == 0) idx22 = xxyy.back(); xxyy.pop_back();

            ans[1][j] = idx31;
            ans[2][j] = ans[3][j] = idx22;
        }

        ans[1][idx + 3] = xy.back(); xy.pop_back();
        idx += 4;
    }


    // 2*2랑 1*1 치우기
    while (xxyy.size() > 0 && xy.size() >= 2) {
        int ttIdx = xxyy.back(); xxyy.pop_back();

        // 3 * 2넣기
        for (int j = idx; j < idx + 2; j++) {
            int ooIdx = xy.back(); xy.pop_back();
            ans[1][j] = ooIdx;
            ans[2][j] = ans[3][j] = ttIdx;
        }
        idx += 2;
    }

    // 3*1 다쓰기
    while (xxxy.size() > 0) {
        int x3y1 = xxxy.back(); xxxy.pop_back();
        ans[1][idx] = ans[2][idx] = ans[3][idx] = x3y1;
        idx += 1;
    }

    // 2*1랑 1*1 치우기
    while (xxy.size() > 0 && xy.size() > 0) {
        int otIdx = xxy.back(); xxy.pop_back();
        int ooIdx = xy.back(); xy.pop_back();

        // 3 * 1넣기
        ans[1][idx] = ooIdx;
        ans[2][idx] = ans[3][idx] = otIdx;
        idx += 1;
    }

    // 2*1 3개로 치우기
    while (xxy.size() >= 3) {

        // 3 * 2넣기
        for (int i = 1; i <= 3; i++) {
            int otIdx = xxy.back(); xxy.pop_back();
            ans[i][idx] = ans[i][idx + 1] = otIdx;
        }
        idx += 2;
    }

    // 1*1 다쓰기
    for (int j = idx; j <= N; j++) {
        for (int i = 1; i <= 3; i++) {
            int ooIdx = xy.back(); xy.pop_back();
            ans[i][j] = ooIdx;
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= N; j++) {
            cout << ans[i][j] << ' ';
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
    for (int tt = 1;tt <= Tc;tt++) {
        solve();
    }

    return 0;
}
