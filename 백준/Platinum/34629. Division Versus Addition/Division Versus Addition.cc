#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
일단 +1을 어디할거냐가 관건인데 +1을 했을때 레벨이 달라지는걸 먼저해야함

일단 나누는 순간 2^k니까 손이 닿기전에 +1을 해줘야한다 
그러면 특정 숫자가 있을때 +1로 되냐를 봐야함
일단 각숫자마다 다음 레벨로 가기위해서 필요한 1개수를 세자

1 1 3 4 이러면 하나 올리고 나머지 하나를 없애겠지
1 1 1 이면 2번까지 올릴수있음

2번걸쳐서 올리는걸 쓸수있을까?

올려야하는 횟수
1 1 1 1 1 2
1이 졸라많아도 결국 턴에 1짜리를 올려야하니까 2는 신경쓸겨를이 없음

걍 1인거만 세자

일단 각 값마다 레벨이랑 1인지 아닌지 계산하고
범위에 대해서 각 개수를 누적해. 그리고 1인거 개수도 누적해
각 개수합 + 1인거 개수 / 2 ? 근데 12면 6 3 -> 4 -> 2 -> 1이 됨


3 7 15 31 63 같은거의 2^k 곱한수면 나누면서 이걸만나고 
결국 시행횟수를 더할수잇음
5에서 6만들기 이런거 

그럼 +1 차례에 이런 숫자를 한번에 못만들면 계속 못만드는게 맞고
한번 건드린수에만 계속 +1을 하는게 맞는듯

그럼 초기수에서 +1을 했을때도 고려해야함
x+1 이랑 x 에 대해서 각각 다시행해봐야함
늘어나는 횟수가 많아질수도있음 이 횟수랑 그냥 x랑 저장해두고 



*/

ll mylog2(ll y) {
    if (y <= 1) return 0;
    ll lv = 0;
    while ((1LL << (lv+1)) <= y - 1) lv++;
    return lv + 1;
}

bool isPow2(ll x){
    if(x == 0) return 0;

    return ((x & (x-1)) == 0);
}

void solve() {
    int N, Q; 
    cin >> N >> Q;
    vector<ll> a(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];


    vector<ll> prefG(N+1, 0);
    vector<ll> prefB(N+1, 0); // 경계 개수 누적

    for (int i = 1; i <= N; i++) {
        ll x = a[i];
        ll g = max(1LL, mylog2(x - 1));
        prefG[i] = prefG[i-1] + g;

        ll isB = (x != 2 && isPow2(x - 1)) ? 1 : 0;
        prefB[i] = prefB[i-1] + isB;
    }

    while (Q--) {
        int a, b; cin >> a >> b;
        ll sumG = prefG[b] - prefG[a-1];
        ll cntB = prefB[b] - prefB[a-1];

        cout << sumG + max(0LL, (cntB) / 2) << '\n';
    }
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