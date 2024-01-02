#include <iostream>

using namespace std;

int main(){

  int T; cin >> T;

  while(T--){

    string s1, s2;

    int aPos[100005] = {};

    int cnt = 0;

  

    cin >> s1 >> s2;

  

    int index = 0;

    for(int i = 0; i < s1.size(); i++){

      if(s1[i] == 'a')

        aPos[index++] = i;

    }

    

    index = 0;

    for(int i = 0; i < s2.size(); i++){

      if(s2[i] == 'a')

        cnt += abs(aPos[index++] - i);

    }

  

    cout << cnt << '\n';

  }

  

  return 0;

}

