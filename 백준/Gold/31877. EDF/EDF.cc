#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
/*
숫자가 크다 일단 10^9일일이 틱으로 돌리면 무조건 터지고
결국 나오는 숫자값들이 어떻지? 한 작업당 계산량이 2개니까
2 * 10^5정도 계산해야하는상황이 옴
그럼 pq를 써서 빠르게 일하는걸 관리하면 최대 MlogM 충분하네

일단 먼저 다 우큐에 넣고
하니씩 빼셈 

언제까지 함? 
1. 일을 끝내거나
2. 다음 새로운 일이 들어올때까지
새로운 일이 들어오면 일하던거 다시 큐에 넣고 top꺼내기
끝냈을때도 체크해서 넣자 ㅇㅇ
*/

void solve() {
    ll N; cin >> N;
    priority_queue<pll, vector<pll>, greater<pll>> pq; // 마감시간, 작업시간

    for(ll i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        pq.push({y, x});
    }

    ll M; cin >> M;
    vector<tuple<ll, ll, ll>> come; // 나중에 들어올 일
    for(ll i = 0; i < M; i++) {
        ll x, y, z; cin >> x >> y >> z;
        come.push_back({x, z , y}); // 시작시간, 마감시각, 걸리는 시간
    }

    sort(come.begin(), come.end());


    // 꺼내서 넣을때 뒤에 순서 조심하셈!!
    ll t = 0;
    ll comeIdx = 0;
    while(!pq.empty() || comeIdx < M) {
        

        auto [e, d] = pq.top();
        pq.pop();

        // 다음꺼 들어오는 시간
        ll nextT = (comeIdx < M ? get<0>(come[comeIdx]) : INT_MAX);

        if(t + d <= nextT) { // 일이 먼저 끝나는 경우
            // 일 끝내기
            if(t + d > e) { // 마감 넘음
                cout << "NO\n";
                return;
            }
            t += d;
        }
        else { // 일이 중간에 옴
            pq.push({e, d - (nextT - t)}); // 하다가 다시 넣기
            t = nextT;
        }

        // 현재시간에 대해서 일이 있는게 있다면 다 넣기
        while(comeIdx < M && get<0>(come[comeIdx]) <= t) {
            ll endTime = get<1>(come[comeIdx]);
            ll duration = get<2>(come[comeIdx]);
            pq.push({ endTime, duration });
            comeIdx++;
        }

        // 빈경우 다음걸로 점프하고 다 넣기
        if (pq.empty()) {
            ll nxt = get<0>(come[comeIdx]);
            t = max<ll>(t, nxt);
            while (comeIdx < M && get<0>(come[comeIdx]) <= t) {
                int endTime = get<1>(come[comeIdx]);
                int duration = get<2>(come[comeIdx]);
                pq.push({ endTime, duration });
                comeIdx++;
            }
            continue;
        }
    }

    cout << "YES\n";
    cout << t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}