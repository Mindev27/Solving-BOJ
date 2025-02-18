#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

const int INF = 1e9;
const int MAX = 205;
int N, S = 203, T = 204;
vector<int> v;
vector<int> globalAdj[MAX];     // 일반정점끼리의 adj
vector<int> adj[MAX];           // 플로우에 사용할 adj
int c[MAX][MAX], f[MAX][MAX];
int level[MAX];
int work[MAX];
bool isNear[MAX];

bool bfs(){
    fill(level, level+MAX, -1);
    level[S] = 0;
    
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(level[nxt] == -1 && c[cur][nxt] - f[cur][nxt] > 0){
                level[nxt] = level[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return level[T] != -1;
}

int dfs(int cur, int dest, int flow){
    if(cur == dest) return flow;

    for(int &i = work[cur]; i < adj[cur].size(); i++){
        int next = adj[cur][i];
        if(level[next] == level[cur]+1 && c[cur][next] - f[cur][next] > 0){
            int df = dfs(next, dest, min(c[cur][next]-f[cur][next], flow));
            if(df > 0){
                f[cur][next] += df;
                f[next][cur] -= df;
                return df;
            }
        }
    }
    return 0;
}

bool check(int mid) {
    // init
    memset(f, 0, sizeof(f));
    int expect = 0;
    
    for(int i = 0; i < N; i++) {
        if(v[i]) {
            if(isNear[i]) {
                c[i+101][T] = mid; // 취약한곳을 mid로 채움
                expect += mid;
            }
            else {
                c[i+101][T] = 1; // 나머지는 1명이상
                expect += 1;
            }
        }
    }

    int total = 0;
    while(bfs()){
        fill(work, work+MAX, 0);
        while(1){
            int flow = dfs(S, T, INF);
            if(flow == 0) break;
            total += flow; 
        }
    }

    // cout << mid << ':' << total << ' ' << expect << '\n';
    return total == expect;
}

void solve() {
    memset(c, 0, sizeof(c));
    for(int i = 0; i < MAX; i++) {
        globalAdj[i].clear();
        adj[i].clear();
    }
        
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // 인접정보 입력
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < N; j++) {
            if(s[j] == 'Y') {
                globalAdj[i].push_back(j);
            }
        }
    }

    // cout << "globalAdj\n";
    // for(int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for(int &nxt : globalAdj[i]) {
    //         cout << nxt << ' ';
    //     }
    //     cout << '\n';
    // }


    // 적군과 인접한 아군땅 메모
    for(int i = 0; i < N; i++) {
        if(v[i] == 0) continue;     // 적군땅은 패스
        bool isDanger = false;
        for(int &nxt : globalAdj[i]) {
            if(v[nxt] == 0) {
                isDanger = true;
                break;
            }
        }
        isNear[i] = isDanger;
    }

    // for(int i = 0; i < N; i++) {
    //     cout << isNear[i] << ' ';
    // }
    // cout << '\n';


    for(int i = 0; i < N; i++) {
        if(v[i] > 0) {
            // S -> 모든정점
            adj[S].push_back(i);
            adj[i].push_back(S);
            c[S][i] = v[i];

            // 현재턴 -> 다음턴
            adj[i].push_back(i+101);
            adj[i+101].push_back(i);
            c[i][i+101] = INF;
        }
    }

    // 현재정점 -> 다음 턴 인접한 정점
    for(int i = 0; i < N; i++) {
        for(int &nxt : globalAdj[i]) {
            if(v[i] > 0 && v[nxt] > 0) {
                adj[i].push_back(nxt + 101);
                adj[nxt+101].push_back(i);
                c[i][nxt+101] = INF;
            }
        }
    }

    // 다음턴에서 T로 연결만하기 c는 check에서 변경
    for(int i = 0; i < N; i++) {
        if(v[i] > 0) {
            adj[i+101].push_back(T);
            adj[T].push_back(i+101);
        }
    }

    // cout << "adj\n";
    // for(int i = 0; i < MAX; i++) {
    //     if(adj[i].size() == 0) continue;
    //     cout << i << ": ";
    //     for(int &nxt : adj[i]) {
    //         cout << nxt << ' ';
    //     }
    //     cout << '\n';
    // }
    

    int lo = -1, hi = 100000;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}