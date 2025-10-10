#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double
/*
적어보면 파스칼 삼각형임 
1 1
1 2 1
1 3 3 1

그럼 N만큼 반복해서 파스칼 삼각형의 줄을 만들고
어디에 속하는지 계산하면 되긴하는데

크기는 어캐 구하지
젤큰것에 대해서 몇번째인지 아니까 그걸로 구하자
넓이 비율은 a^2 : b^2 임

무조건 큰걸 b로 둔다면 
1등넓이 : 2등넓이 = b^2 : a^2
그러면 다음 넓이로 갈때 a^2/b^2 곱해주면 된다
그러면 K가 몇번째에 속하는지 확인하고 그 숫자등수만큼 곱해주기

*/

ll a, b, N ,K;

void solve() {
    ll x, y;
    cin >> x >> y >> N >> K;

    a = min(x, y);
    b = max(x, y);

    vector<ll> pascal[45];

    // 처음에는 1 1
    pascal[1].push_back(1);
    pascal[1].push_back(1);

    for(int i = 1; i < N; i++) {
        pascal[i+1].push_back(1);

        for(int j = 0; j < pascal[i].size() - 1; j++) {
            ll val = pascal[i][j] + pascal[i][j+1];
            pascal[i+1].push_back(val);
        }

        pascal[i+1].push_back(1);
    }

    // for(int i = 1; i <= N; i++) {
    //     cout << "i : " << i << '\n';
    //     for(int j = 0; j < pascal[i].size(); j++) {
    //         cout << pascal[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    ll sum = 0;
    ll rank = -1;
    for(int i = 0; i < pascal[N].size(); i++) {
        sum += pascal[N][i];

        if(sum >= K) { // 등수가 i+1번이라는거임
            rank = i+1;
            break;
        }
    }

    // cout << rank << '\n';

    // 1등 넓이 구하기
    ld firstS = (ld)a*b/2;
    ld tmp = ((ld)b*(ld)b/(a*a+b*b)); // 원본에서 가장 큰걸 기준으로 넘어가는 비율
    for(int i = 0; i < N; i++) {
        firstS *= tmp;
    }

    // cout << firstS << '\n';

    ld nxt = ((ld)a*a/(b*b)); // 다음등수로 갈때 곱해야하는거
    // cout << nxt << '\n';
    for(int i = 1; i < rank; i++) {
        firstS *= nxt;
    }

    cout << fixed << setprecision(15) << log(firstS) << '\n';
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
