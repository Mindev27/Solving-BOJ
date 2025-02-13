#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

// 일단 일반적인 방식으로는 무조건 터짐
// 동생이 있는 시간을 미리 표시하자
// 01BFS로 돌려도 방문한곳을 또 해야함;;
// 한번 방문했을때 동생이 오는 시간을 보고 좌우무빙을 치자 ㅇㅇ

// 1. 01BFS로 탐색하면서 각 노드를 한번만 방문
// 2. 현재 방문한곳에 동생이 온다면 그리고 내가 빨리 도착했다면
//      -> 두 시간의 기우성이 같은지를 체크하자

// 같은 칸인데 홀짝을 뒤집을 수 있나? 2 -> 4 -> 3이랑 2 -> 3있으니까 가능
// 홀짝 방문을 따로 처리해야할듯

const int MAX = 500000;
int N, K;
int sister[MAX + 5];
queue<pii> q; // (위치, 시간)
bool visited[MAX + 5][2]; // 위치와 홀짝성 0 : 짝, 1 : 홀

void solve() {
    cin >> N >> K;

    fill(sister, sister + MAX + 5, -1);
    memset(visited, false, sizeof(visited));

    int tmp = 0;
    while (K <= MAX) {
        // cout << K << ' ' << tmp + 1 << '\n';
        sister[K] = tmp++;
        K += tmp;
    }

    q.push({ N, 0 });
    visited[N][0] = true;

    int ans = INT_MAX;
    while (!q.empty()) {
        auto [cur, time] = q.front();
        q.pop();

        // cout << cur << ' ' << time << '\n';

        // 현재칸에서 동생을 잡을 수 있는지 확인
        if (sister[cur] != -1 && sister[cur] >= time) {
            if (time % 2 == sister[cur] % 2) { // 기우성이 같다면
                ans = min(ans, sister[cur]);
                continue;
            }
        }

        // 2X
        if (cur * 2 <= MAX && !visited[cur * 2][(time + 1) % 2]) {
            visited[cur * 2][(time + 1) % 2] = true;
            q.push({ cur * 2, time + 1 });
        }

        // X+1
        if (cur + 1 <= MAX && !visited[cur + 1][(time + 1) % 2]) {
            visited[cur + 1][(time + 1) % 2] = true;
            q.push({ cur + 1, time + 1 });
        }

        // X-1
        if (cur - 1 >= 0 && !visited[cur - 1][(time + 1) % 2]) {
            visited[cur - 1][(time + 1) % 2] = true;
            q.push({ cur - 1, time + 1 });
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
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