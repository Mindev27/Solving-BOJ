#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int L, N;
vector<string> s;
bool visited[25];
bool flag = false;


bool check(vector<string> &v) {
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < L; j++) {
            if(v[i][j] != v[j][i]) return false;
        }
    }
    return true;
}

// 현재 마방진을 구성하는 문자열, 채운 개수
void backTrack(vector<string> &v) {
    if(flag) return;

    if(v.size() == L) {
        flag = check(v);

        if(flag) {
            for(int i = 0; i < L; i++) {
                for(int j = 0; j < L; j++) {
                    cout << v[i][j];
                }
                cout << '\n';
            }
        }

        return;
    }

    for(int i = 0; i < N; i++) {
        if(flag) return;
        if(visited[i]) continue;

        v.push_back(s[i]);
        visited[i] = true;

        backTrack(v);

        v.pop_back();
        visited[i] = false;
    }
}
void solve() {
    cin >> L >> N;
    s.resize(N);
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    vector<string> v;

    backTrack(v);

    if(!flag) cout << "NONE";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}