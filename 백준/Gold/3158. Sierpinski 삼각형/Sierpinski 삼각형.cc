#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

string s;

void solve() {
    cin >> s;
    if(s[s.size() - 1] == '4') {
        string sub = s.substr(0, s.size() - 1);
        cout << sub << "1\n";
        cout << sub << "2\n";
        cout << sub << "3\n";
        return;
    }

    bool one = false, two = false, three = false;
    for(int i = s.size() - 1; i >= 1; i--) {
        if(!one && s[i] == '1') {
            one = true;
            for(int j = 0; j < i; j++) {
                cout << s[j];
            }
            cout << "4\n";
        }
        if(!two && s[i] == '2') {
            two = true;
            for(int j = 0; j < i; j++) {
                cout << s[j];
            }
            cout << "4\n";
        }
        if(!three && s[i] == '3') {
            three = true;
            for(int j = 0; j < i; j++) {
                cout << s[j];
            }
            cout << "4\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    return 0;
}
