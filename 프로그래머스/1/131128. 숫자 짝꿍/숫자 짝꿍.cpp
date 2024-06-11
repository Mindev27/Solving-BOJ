#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int xnum[10], ynum[10];
    for(int i = 0; i <= 9; i++) {
        xnum[i] = 0;
        ynum[i] = 0;
    }
    for(char &c : X) {
        xnum[c - '0']++;
    }
    for(char &c : Y) {
        ynum[c - '0']++;
    }
    
    for(int i = 9; i >= 0; i--) {
        int n = min(xnum[i], ynum[i]);
        for(int j = 0; j < n; j++) {
            answer += to_string(i);
        }
    }

    if(answer == "") return "-1";
    if(answer[0] == '0') return "0";
    return answer;
}