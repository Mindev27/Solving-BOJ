/*
일단 2 ~ 9진법에 대해서 모든 문자열들을 검사함
그럼 되는 진법들만 남겠지.. 여러개일수도

그러면 X가 들어있는 문자열에 대해서 
1. 모든 진법에 대해 같은 답이나오면 X바꾸고
2. 모든 진법에 대해 다른 답이 나오면 ?
*/

#include <bits/stdc++.h>

using namespace std;

// k진법 x를 10진법으로
int change(string x, int k) {
    int res = 0;
    for (char c : x) {
        if(c - '0' >= k) return -1;
        res = res * k + (c - '0');
    }
    return res;
}


// k진법으로 나타냈을때 맞는가
bool isRight(tuple<string, char, string, string> t, int k) {
    string a = get<0>(t);
    char   op = get<1>(t);
    string b = get<2>(t);
    string c = get<3>(t);
    
    int na = change(a, k);
    int nb = change(b, k);
    
    if (na == -1 || nb == -1) {
        return false;
    }

    if (c == "X") {
        return true;
    }

    int nc = change(c, k);
    if (nc == -1) return false;
    
    if (op == '+') {
        return (na + nb == nc);
    } else { // '-'
        return (na - nb == nc);
    }
}


// 파싱
tuple<string, char, string, string> parse (string s) {
    char op;
    string a = "", b="", c="";   // a + b = c
    int idx = 0;
    
    // a
    for(int i = idx; i < s.size(); i++) {
        if(s[i] == ' ') {
            idx = i + 3;   // idx는 b의 시작
            op = s[i+1]; 
            break; 
        } 
        a += s[i];
    }
    
    // b
    for(int i = idx; i < s.size(); i++) {
        if(s[i] == ' ') {
            idx = i + 3;   // idx는 c의 시작
            break;
        }
        b += s[i];
    }
    
    if(s[idx] == 'X') return {a, op, b, "X"}; // X면 C는 X
    
    // c
    for(int i = idx; i < s.size(); i++) {
        if(s[i] == ' ') {
            idx = i + 3;   // idx는 c의 시작
            break;
        }
        c += s[i];
    }
    
    cout << a << ' ' << op << ' ' << b << ' ' << c << '\n';
    return {a, op, b, c};
}

string toBase(int num, int base) {
    if (num == 0) return "0";
    string ret;
    while (num > 0) {
        int digit = num % base;
        num /= base;
        ret.push_back(char(digit + '0'));
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// 수식을 k진법으로 할때 x값 계산
string calcX(tuple<string, char, string, string> t, int k) {
    string a = get<0>(t);
    char  op = get<1>(t);
    string b = get<2>(t);
    
    int na = change(a, k);
    int nb = change(b, k);
    
    if(na == -1 || nb == -1) return "";
    
    int resK = (op == '+' ? na + nb : na - nb); // K진법일때 답
    
    return toBase(resK, k);
}
    
vector<string> solution(vector<string> ex) {
    vector<string> ans;
    bool can[10]; // 가능한 진법의 여부
    vector<tuple<string, char, string, string>> v; // 파싱된거
    
    fill(can, can + 10, true);
    
    for(string &s : ex) {
        v.push_back(parse(s));
    }
    
    // 각 진법이 가능한지 확인
    for(auto &x : v) {
        for(int i = 2; i <= 9; i++) {
            if(!isRight(x, i)) can[i] = false;
        }
    }
    
    for(int i = 2; i <= 9; i++) {
        cout << can[i] << ' ';
    }
    cout << '\n';
    
    // 이제 X있는 수식을 잡고 가능한 진법에 대해서 같은 값이 나오는지 체크해야겠지
    for(auto &x : v) {
        string a = get<0>(x);
        char  op = get<1>(x);
        string b = get<2>(x);
        string c = get<3>(x);
        
        cout << a << ' ' << op << ' ' << b << " = " << c << '\n';
        
        if(c != "X") continue; // X없는건 패스
        string key = "";
        bool allSame = true;
        for(int i = 2; i <= 9; i++) {
            if(!can[i]) continue;
            
            string cur = calcX(x, i);
            if(cur == "") continue;
            
            cout << "i: " << i << " cur : " << cur << '\n';
            if(key == "") key = cur;
            else {
                if(key != cur) {allSame = false; break; }
            }
        }
        
        string tmp = "";
        tmp += a; tmp += " ";
        tmp += op; tmp += " ";
        tmp += b; tmp += " = ";

        if(allSame) tmp +=  key;
        else tmp += "?";
        
        ans.push_back(tmp);
    }
    
    return ans;
    
}