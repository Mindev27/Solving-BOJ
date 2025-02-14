#include <bits/stdc++.h>
#define ll long long 
using namespace std;

// 결국 n뒤에 문자들은 밴되어도 문제가 없음
// 밴되는 문자들을 정렬하고 숫자로 바꿔서 n보다 앞이면 n++바로 해주기

ll StoLL(string s) {
    ll ans = 0;
    for (char c : s) {
        ans = ans * 26 + (c - 'a' + 1);
    }
    return ans;
}


// k를 알파벳으로 만듦
string LLtoS(ll k) {
    string ans;
    while (k > 0) {
        ll r = k % 26;
        if (r == 0) {
            ans.push_back('z');
            k = (k / 26) - 1; 
        } else {
            ans.push_back('a' + r - 1);
            k /= 26;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string solution(ll n, vector<string> bans) {
    sort(bans.begin(), bans.end(), [&](string a, string b) {
        return StoLL(a) < StoLL(b);
    });

    ll target = n;
    for (string &s : bans) {
        ll curBan = StoLL(s);
        if (curBan <= target) target++;
        else break;
    }

    return LLtoS(target);
}