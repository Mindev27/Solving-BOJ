#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
아오 구현
일단 사전순 앞서는거니까 .빼고 싹 모아서 집어넣고
남은문자열들 순열로 돌려 12! 3628800 * 11 * 12
애매한데;;
중간에 미리 가지치기를 좀 하자

   0 
1 2 3 4
  5 6
7 8 9 10
   11


*/

int chk[6][4] = { // 이거만 체크하면 댐
    {0,3,6,10},
    {10,9,8,7},
    {7,5,2,0},
    {1,2,3,4},
    {4,6,9,11},
    {11,8,5,1}
};

vector<char> v;
bool visited[15];
bool found = false;

void printStar() {
    cout << "...." << v[0] << "....\n";
    cout <<'.'<<v[1]<<'.'<<v[2]<<'.'<<v[3]<<'.'<< v[4]<<'.'<<'\n';
    cout << ".." << v[5] << "..." <<v[6] << "..\n";
    cout <<'.'<<v[7]<<'.'<<v[8]<<'.'<<v[9]<<'.'<< v[10]<<'.'<<'\n';
    cout << "...." << v[11] << "....\n";
    found = true;
}

bool check() {
    for(int i = 0; i < 6; i++) {
        int sum = 0;
        for(int j = 0; j < 4; j++) {
            int cur = chk[i][j];
            if(v[cur] == 'x') return true; // 미완성
            sum += (v[cur] - 'A' + 1);
        }

        if(sum != 26) return false;
    }

    return true;
}

void dfs(int depth) {
    if (found) return;
    if(!check()) return; // 미리 가지치기
    if(depth == 12) {
        if(check()) printStar();
        return;
    }

    if(v[depth] != 'x') {
        dfs(depth + 1);
        return;
    }

    for(int i = 0; i < 12; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v[depth] = 'A' + i;

        dfs(depth + 1);

        v[depth] = 'x';
        visited[i] = false;
    }
}

void solve() {
    for(int i = 0; i < 6; i++) {
        string s; cin >> s;
        for(char &c : s) {
            if(c != '.') v.push_back(c);
        }
    }

    memset(visited, false, sizeof(visited));
    for(char &c : v) {
        if(c == 'x') continue;

        visited[c - 'A'] = true;
    }

    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc=1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}