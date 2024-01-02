#include <string>

using namespace std;

// 길이 L로 압축할 때 문자열의 길이
int getLength(string s, int L) {
    string result = "";
    string curStr = s.substr(0, L);
    int sameStrNum = 1;
    
    // 문자열 압축
    for(int j = L; j < s.size(); j += L){
        if(curStr == s.substr(j, L)) // 같은 경우
            sameStrNum++;
        
        else{ // 디른 경우
            if(sameStrNum > 1) result += to_string(sameStrNum);
            result += curStr;
            sameStrNum = 1;
            curStr = s.substr(j, L);
        }
    }
    // 마지막 문자열 처리
    if(sameStrNum > 1) result += to_string(sameStrNum);
    result += curStr;
    
    return result.size();
}

int solution(string s) {
    int answer = s.size();
    
    // 문자열이 나눠질 때 answer업데이트
    for(int i = 1; i <= s.size(); i++)
        answer = min(answer, getLength(s, i));
    
    return answer;
}