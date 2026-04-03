// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
AB BC조합을 지울거임 떨어져있어도 된다.
최대횟수라고 함은 일단 A는 무조건 왼쪽 C는 무조건 오른쪽을 잡야야할것이다
A와 매칭되는B는 완전히 뒤 C보다 뒤부터일거고 C는 무조건 앞부터 일듯


BAAAABCCBBB

ABCBBACBABB
A    A  A
  C   C

A를 다씀으로써 C가 손해보는 그림이 있나?
A - B - C인거에서쓰는건데 어차피 상관없을듯
*/



void solve() {
    string s; cin >> s;
    vector<int> a, b, c;
    for(int i = 0; i < s.size(); i++) {
        char cur = s[i];
        if(cur == 'A') a.push_back(i);
        else if(cur == 'B') b.push_back(i);
        else c.push_back(i);
    }

    bool used[300005]{};
    int ans = 0;

    // A 다쓰기
    for(int i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--) {
        if(a[i] < b[j]) {
            // cout << a[i] << ' ' << b[j] << '\n';
            used[a[i]] = used[b[j]] = true;
            j--;
            ans++;
        }
    }

    // C 다쓰기
    for(int i = 0, j = 0; i < c.size() && j < b.size(); i++) {
        if(b[j] < c[i] && !used[b[j]]) {
            // cout << b[j] << ' ' << c[i] << '\n';
            used[c[i]] = used[b[j]] = true;
            j++;
            ans++;
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
    for (int tt = 1; tt <= Tc; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}