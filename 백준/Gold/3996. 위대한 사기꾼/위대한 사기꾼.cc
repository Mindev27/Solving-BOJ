#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
짝수 인덱스에만 숫자가 없으면 되는듯
특정 k진법일때 짝수인덱스에 숫자가 없으려면 어떻게 해야할까
직접 만들면 안되긴함
특정 수가 있는지 어캐 쉽게 판별할건데

3진법일때
0 1 2
3 4 5 6 7 8
9 10 11
12 13 14 15 16 17
18 19 20
21 22 23 24 25 26
27부터 아래가 반복

k진법
k개
k*(k-1) 개 안됨

결국 vector에 넣자
012
돌면서 +i[1..k) * k^2한거
81	부터 됨

0 1 2 9 10 11 18 19 20
+81
+162

그럼 [1, k)까지 반복
vector에 대해서 싹 돌면서 
K^2를 곱한걸 집어넣기
넣는게 N이상이라면 종료
끝나면 K^2해주기

k^2 진법으로 표현할때 넘길수 있는거 체크

*/

ll N, k;
vector<int> v;

void solve() {
    cin >> N >> k;

    while(N > 0) {
        v.push_back(N % (k * k));
        N /= (k*k);
    }

    bool flag = false; // true면 뒤에 무조건 다 채움
    ll ans = 0;

    for(int i = v.size()-1; i >= 0; i--) {
        if(flag) { ans *= k; continue; }

        int cur = v[i];
        if(cur >= k) {
            ans += k;
            flag = true;
        }
        else {
            ans += cur;
        }
        ans *= k;
    }
    ans /= k;

    cout << (flag ? ans : ans + 1) << '\n';
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