// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
kevinlys00님이 공유해준 풀이 코드 보고 풂

star 모양 그래프 기준 F를 둘때 인접한 F개수 * T개수이고 총 노드는 1+F+T임
최솟값을 미리 전처리해두고
F-F-F-F 꼴에서 T들을 적절히 붙여야함
dp로 이 star그래프를 연결시킨다 붙일때는 F를 서로 겹쳐서 -2가됨

*/

const int MAX = 1000005;

int base[MAX], baseT[MAX], dp[MAX], cut[MAX];

vector<int> block;
vector<pii> edges;
string state;

void init() {
    for(int i = 1; i < MAX; i++) {
        base[i] = i + 2;
        baseT[i] = 1;
    }

    for(int i = 2; 1LL * i * i < MAX; i++) {
        for(int j = i * i; j < MAX; j += i) {
            int curCost = 1 + i + j / i;
            if(base[j] > curCost) {
                base[j] = curCost;
                baseT[j] = i;
            }
        }
    }

    for(int i = 1; i < MAX; i++) {
        dp[i] = base[i];
        cut[i] = 0;
    }

    for(int i = 4; i < MAX; i++) {
        for(int j = 1; 1LL * j * j < i; j++) {
            int cand = dp[j] + dp[i - j] - 2;
            if(dp[i] >= cand) {
                dp[i] = cand;
                cut[i] = i - j;
            }
        }
    }
}

void recover(int cur) {
    if(cut[cur] == 0) {
        block.push_back(cur);
        return;
    }
    recover(cut[cur]);
    recover(cur - cut[cur]);
}

void solve() {
    int k;
    cin >> k;

    block.clear();
    edges.clear();
    state = "F";

    recover(k);
    sort(block.rbegin(), block.rend());

    int center = 1;
    int cnt = 1;

    for(int z : block) {
        int tCnt = baseT[z];
        int fCnt = z / tCnt;

        int newFCnt = fCnt - (center > 1);

        for(int i = 0; i < tCnt; i++) {
            cnt++;
            state += 'T';
            edges.push_back({center, cnt});
        }

        for(int i = 0; i < newFCnt; i++) {
            cnt++;
            state += 'F';
            edges.push_back({center, cnt});
        }

        center += tCnt + fCnt - (center > 1);
    }

    cout << cnt << '\n';
    cout << state << '\n';
    for(pii e : edges) cout << e.X << ' ' << e.Y << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}