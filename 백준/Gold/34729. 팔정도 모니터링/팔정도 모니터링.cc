// codeforce polygon main_solution.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
static inline ll A(ll x){ return x < 0 ? -x : x; }
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N; ll R;
    if(!(cin >> N >> R)) return 0;
 
    vector<ll> X(N), Y(N);
    ll sumAbsX = 0, sumAbsY = 0;
    for(int i=0;i<N;++i){
        cin >> X[i] >> Y[i];
        sumAbsX += A(X[i]);
        sumAbsY += A(Y[i]);
    }
 
    vector<ll> V;
    for(int i=0;i<N;++i){
        V.push_back(X[i]); V.push_back(X[i]); V.push_back(X[i]); // 3 * |t - x_i|
        V.push_back(Y[i]); V.push_back(Y[i]);                   // 2 * |t - y_i|
        V.push_back(-Y[i]);                                     // 1 * |t + y_i|
    }
 
    int k = (int)V.size() - 1; k /= 2;
    nth_element(V.begin(), V.begin()+k, V.end());
    ll t = V[k];
    if (t < -R) t = -R;
    if (t >  R) t =  R;
 
    // G(t) = sum|x_i| + sum|y_i| + sum(3|t-x_i| + 2|t-y_i| + |t+y_i|)
    long long ans = sumAbsX + sumAbsY;
    for(int i=0;i<N;++i){
        ans += 3LL*A(t - X[i]) + 2LL*A(t - Y[i]) + A(t + Y[i]);
    }
 
    cout << ans << '\n';
    return 0;
}