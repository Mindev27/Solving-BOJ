#include <bits/stdc++.h>

using namespace std;

string tob(int x) {
    string ans = "";
    while(x > 0) {
        ans += (x % 2 == 1 ? '1' : '0');
        x /= 2;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int solution(int n) {
    int answer = 0;
    
    string target = tob(n);
    int want = 0;
    for(char &c : target) {
        if(c == '1') want++;
    }
    
    cout << target << ' ' << want << '\n';
    
    while(true) {
        n++;
        string s = tob(n);
        
        int cnt = 0;
        for(char &c : s) {
            if(c == '1') cnt++;
        }
        
        cout << n << ' ' << cnt << '\n';
        
        if(want == cnt) {return n; break; }
    }
    return -1;
}