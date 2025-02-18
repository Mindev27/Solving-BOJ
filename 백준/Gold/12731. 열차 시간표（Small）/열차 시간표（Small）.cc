#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int convertTime(string s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');

    return h * 60 + m;
}

void solve() {
    int T; // 회차시간
    int na, nb;
    vector<tuple<int, int, int>> time; // 시작, 끝, 열차타입 1:a 2:b
    cin >> T;
    cin >> na >> nb;

    for(int i = 0; i < na; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        time.push_back({convertTime(s1), convertTime(s2), 1});
    }

    for(int i = 0; i < nb; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        time.push_back({convertTime(s1), convertTime(s2), 2});
    }

    sort(time.begin(), time.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<0>(a) < get<0>(b);
    });

    // 각 역에 출발할수있는 열차의 시간을 저장
    priority_queue<int, vector<int>, greater<int>> pqA, pqB;
    int startA = 0, startB = 0;

    for (auto &[s, e, type] : time) {
        // cout << s << ' ' << e << type << '\n';
        if(type == 1) {
            if (!pqA.empty() && pqA.top() <= s) {
                pqA.pop(); // 기존 열차
            } else {
                startA++; // 새거 
            }
            pqB.push(e + T);
        }
        else { // b
            if (!pqB.empty() && pqB.top() <= s) {
                pqB.pop(); // 기존 열차
            } else {
                startB++; // 새거
            }
            pqA.push(e + T);
        }
    }

    cout << startA << " " << startB << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}
