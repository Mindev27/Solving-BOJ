// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>


const int DIV = 1000000007;

// x행렬에 y행렬을 곱하는 함수 (2x2)
void multMatrix(ll x[2][2], ll y[2][2]) {
    ll temp[2][2] = {};

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            temp[i][j] = 0;
            for(int k = 0; k < 2; k++){
                temp[i][j] += x[i][k] * y[k][j];
                temp[i][j] %= DIV;
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            x[i][j] = temp[i][j];
        }
    }
}

void powMatrix(ll base[2][2], ll e, ll out[2][2]) {
    ll a[2][2], result[2][2];

    // base 복사
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            a[i][j] = base[i][j];

    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;

    while(e > 0){
        if(e & 1){
            multMatrix(result, a);
        }
        e >>= 1;
        if(e) multMatrix(a, a);
    }

    // out에 복사
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            out[i][j] = result[i][j];
}

void solve() {
    ll n, k;
    cin >> n >> k;

    if(n == 0){
        cout << "0 1\n";
        return;
    }
    if(n == 1){
        cout << 1 % DIV << " 0\n";
        return;
    }

    ll fibM[2][2] = {{1, 1}, {1, 0}};
    ll fibRes[2][2];
    powMatrix(fibM, k, fibRes);

    ll fk1 = fibRes[0][0]; // F_k+1
    ll fk = fibRes[0][1]; // F_k
    ll fk_1 = fibRes[1][1]; // F_k-1

    ll Lk = (fk_1 + fk1) % DIV;

    ll c;
    if(k & 1){
        c = 1;
    }
    else{
        c = DIV - 1;
    }

    ll M[2][2] = {{Lk, c}, {1, 0}};
    ll MP[2][2];
    powMatrix(M, n - 1, MP);

    ll A = MP[0][0] % DIV;
    ll B = MP[0][1] % DIV;

    if(A < 0) A += DIV;
    if(B < 0) B += DIV;

    cout << A << ' ' << B << '\n';
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
