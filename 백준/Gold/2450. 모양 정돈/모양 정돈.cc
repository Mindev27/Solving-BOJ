#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
일단 생각 해볼만한게 123의 조합이 몇개 없다
이걸 다 만들어두고 교환하는걸로 만들자
즉 111222333, 111333222, 222111333, 222333111, 333222111, 333111222
이런느낌을 다 해보면 될듯

바꾸는건 어떻게 해야 최적이지?
1 3- 3- 2 1- 1- 3 2-


1 1- 1- 2 2- 3- 3 3-

3 1
1 2
2 3

바꿔야하는거 만들기 O(N)이고, 사이클 생기는거랑 쌍 없애기 O(1)
3가지로 다해보자
*/

int N, cnt[5]; // i개수
vector<int> v;
vector<int> target;

// a b c 조합으로 만들어줌
vector<int> makeTarget(int a, int b, int c) {
    vector<int> ans;
    for(int i = 0; i < cnt[a]; i++) ans.push_back(a);
    for(int i = 0; i < cnt[b]; i++) ans.push_back(b);
    for(int i = 0; i < cnt[c]; i++) ans.push_back(c);

    return ans;
}

// v랑 target 차이 구하기
int getDiff() {
    // cout << "v: ";
    // for(int &i : v) cout << i << ' ';
    // cout << '\n';
    // cout << "t: ";
    // for(int &i : target) cout << i << ' ';
    // cout << '\n';
    
    int change[5][5]; // i에서 j로 바꿔야함
    memset(change, 0, sizeof(change));

    for(int i = 0; i < N; i++) {
        if(v[i] == target[i]) continue;
        change[v[i]][target[i]]++;
    }

    int ans = 0;

    // 1 3 <-> 3 1
    int diff = min(change[1][3], change[3][1]);
    change[1][3] -= diff;
    change[3][1] -= diff;
    ans += diff;

    // 2 3 <-> 3 2
    diff = min(change[2][3], change[3][2]);
    change[2][3] -= diff;
    change[3][2] -= diff;
    ans += diff;

    // 2 1 <-> 1 2
    diff = min(change[2][1], change[1][2]);
    change[2][1] -= diff;
    change[1][2] -= diff;
    ans += diff;

    // 1 3, 2 1, 3 2
    ans += change[1][3] * 2;
    // 3 1, 1 2, 2 3
    ans += change[3][1] * 2;

    // cout << "ans : " << ans << '\n'; 
    // cout << '\n';
    return ans;
}

void solve() {
    cin >> N;
    v.resize(N);
    
    for(int &i : v) {
        cin >> i;
        cnt[i]++;
    }

    int ans = 999999;

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                if(i == j || j == k || k == i) continue;

                // 1 2 3의 다른 조합
                target = makeTarget(i, j, k);
                ans = min(ans, getDiff());
            }
        }
    }
    cout << ans << '\n';
    
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
