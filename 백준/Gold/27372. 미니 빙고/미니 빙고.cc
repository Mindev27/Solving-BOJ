#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
S의 점수 문자열을 먼저 구하고
next permutation으로 점수문자열 하나씩 구해보기

0 1 2
3 4 5
6 7 8

*/
int chk[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
};

string scoreS;
string board;

// 점수 만들기
string get(string s) {
    bool scored[10]; // chk[i] 칸 점수 냈는가
    bool visited[10];
    memset(scored, false, sizeof(scored));
    memset(visited, false, sizeof(visited));

    string ret = "";
    for(char &c : s) {
        // 찾기
        int cur = -1;
        for(int i = 0; i < board.size(); i++)  if(c == board[i]) {
            cur = i;
            break;
        }

        visited[cur] = true;

        int curScore = 0;
        for(int i = 0; i < 8; i++) {
            if(scored[i]) continue; // 점수냈으면 끝


            // 점수낼수있는지 확인
            bool ok = true;
            for(int j = 0; j < 3; j++) {
                if(!visited[chk[i][j]]) { 
                    ok = false;
                }
            }

            if(ok) {
                curScore++;
                scored[i] = true;
            }
        }

        ret += ('0' + curScore);

        // cout << "ret : " << ret << '\n';
    }

    return ret;
}


void solve() {
    string S;
    

    cin >> S;
    cin >> board;
    string tmp;
    cin >> tmp; board += tmp;
    cin >> tmp; board += tmp;


    scoreS = get(S);
    // cout << scoreS << '\n';

    sort(S.begin(), S.end());

    do {
        string curS = get(S);
        if(curS == scoreS) {
            cout << curS << ' ' << S << '\n';
            break;
        }
    } while(next_permutation(S.begin(), S.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}
