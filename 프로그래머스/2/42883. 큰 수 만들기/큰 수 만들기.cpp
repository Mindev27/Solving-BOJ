#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n, i, cnt, input, max, index;
    string str, s;
    vector<int> num(500001);
    stack<int> stack, output;

    n = number.size();
    str = number;

    for(i = 0; i < n; i++){
        s = str[i];
        num[i] = stoi(s);
    }

    // 첫번째 숫자를 스택에 push
    stack.push(num[0]);
    index = 1;
    cnt = k;

    while(1){
        //cnt가 0이면 나머지 넣고 break
        if(cnt == 0){
            while(index <= n-1){
                stack.push(num[index]);
                index++;
            }
            break;
        }

        //숫자를 다 넣었는데 cnt 가 0이 아니라면 
        if(index == n && cnt != 0){
            //뒤에서부터 cnt 만큼 pop
            for(int j = 0; j < cnt; j++){
                stack.pop();
            }
            break;
        }

        //스택이 비었다면 push
        if(stack.empty()){
            stack.push(num[index]);
            index++;
        }
        //들어있는 숫자가 더 작으면 pop
        else if(stack.top() < num[index]){
            stack.pop();
            cnt--;
        }
        //들어있는 숫자가 더 크거나 같으면 push
        else if(stack.top() >= num[index]){
            stack.push(num[index]);
            index++;
        }
    }

    while(!stack.empty()){
        output.push(stack.top());
        stack.pop();
    }

    while(!output.empty()){
        answer += to_string(output.top());
        output.pop();
    }

    return answer;
}