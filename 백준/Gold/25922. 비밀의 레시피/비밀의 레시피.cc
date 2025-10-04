#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(), (v).end()
using namespace std;

void solve(void){
    ll N;cin>>N;
    string str;
    // for(int i=0;i<N+1;i++){
        cout<<"? 1000000000\n";
        cout<<flush;
        cin>>str;
    // }
    cout<<"! ";
    reverse(str.begin(), str.end());
    vl v;
    for(ll i=0;i<str.size();i+=9){
        ll tmp=0;
        for(ll j=i;j<min(i+9,(ll)str.size());j++){
            tmp+=(str[j]-'0')*pow(10,j-i);
        }
        v.push_back(tmp);
        // cout<<tmp<<" ";
    }
    while(v.size()!=N+1)v.push_back(0);
    for(ll &i : v) cout << i << ' ';
    // for(auto c:v)cout<<c<<" ";
    cout<<"\n";
    cout<<flush;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cout<<(1LL<<31);
    // cin>>T;
    while(T--)solve();
}