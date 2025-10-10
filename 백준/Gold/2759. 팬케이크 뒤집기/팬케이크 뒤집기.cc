#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N;
vector<int> v;


void solve() {
    cin >> N;
    v.resize(N);
    for(int &i : v) cin >> i;
    
    if(N==1) {
        cout << "0\n";
        return;
    }

    vector<int> ans;

    for(int i = N-1; i >= 2; i--) {
        // i번째를 맞추려면 i+1인걸 찾고 젤위로 올리고 원래자리로 두기
        if(v[i] == i+1) continue;

        int x = -1;
        for(int j = 0; j < i; j++) if(v[j] == i+1) {
            x = j;
            break;
        }


        // 젤위로 올리기
        reverse(v.begin(), v.begin()+x+1);
        ans.push_back(x+1);

        // cout << "k : " << x+1 << '\n';
        // for(int a : v) cout << a << ' ';
        // cout << '\n';

        // i자리에 넣기
        reverse(v.begin(), v.begin()+i+1);
        ans.push_back(i+1);

        // cout << "k : " << i +1 << '\n';
        // for(int a : v) cout << a << ' ';
        // cout << '\n';

    }

    // 2일때만하고 01은 보고 뒤집어주기 그래야 2n-3이됨
    if(v[0] > v[1]) ans.push_back(2);

    cout << ans.size() << ' ';
    for(int &i : ans) cout << i << ' ';
    cout << '\n';
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
