#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

// 그냥 나이브 풀이를 떠올려볼까
// 100C2로 백트래킹 -> 5000가지 경우의 수 5000^10000 -> TLE
// 그리디? 일단 최대한 2번에 사용하면 좋다 많이 없애는게 이득인가?
// dp로 풀자
// dp[i] := 만든 짜장량 i일때 총 요리 횟수
// 어차피 이전에 주문을 처리한 정보는 상관없음
// 그러면 100C2 + 100개를 vector에 세두고 dp 전파

const int INF = 9999999;
int N, M;
vector<int> s;
bool can[20005]; // Si는 N이하이고 어차피 2개 합이라 2만이하
vector<int> canV;


void solve() {
    fill(can, can + 20005, false);

    cin >> N >> M;
    s.resize(M);
    for(int i = 0; i < M; i++) {
        cin >> s[i];
        can[s[i]] = true;
    }

    // 한턴에 뺄수있는 가지수 미리 계산
    for(int i = 0; i < s.size(); i++) {
        for(int j = i + 1; j < s.size(); j++) {
            int cur = s[i] + s[j];
            can[cur] = true;
        }
    }

    // 숫자만 따로 저장
    for(int i = 1; i <= 20000; i++) {
        if(can[i]) {
            canV.push_back(i);
            // cout << i << ' ';
        }
    }

    vector<int> dp(N+1, INF);
    dp[0] = 0;

    for(int d : canV){
        for(int x = d; x <= N; x++){
            if(dp[x - d] != INF){
                dp[x] = min(dp[x], dp[x - d] + 1);
            }
        }
    }

    if(dp[N] == INF) cout << -1 << "\n";
    else cout << dp[N] << "\n";

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
