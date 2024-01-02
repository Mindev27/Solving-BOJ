#include <iostream>

#include <cstring>

#include <queue>

#include <vector>

#include <algorithm>

using namespace std;

vector<int> v, keyV;

queue<int> q;

bool visited[8];

int mydata[8] = {};

int link[8][8] = {

  {0, 1, 0, 0, 0, 0, 0, 1},

  {1, 0, 1, 0, 0, 0, 0, 0},

  {0, 1, 0, 1, 0, 0, 0, 0},

  {0, 0, 1, 0, 1, 0, 0, 0},

  {0, 0, 0, 1, 0, 1, 0, 0},

  {0, 0, 0, 0, 1, 0, 1, 0},

  {0, 0, 0, 0, 0, 1, 0, 1},

  {1, 0, 0, 0, 0, 0, 1, 0}

};

int bfs(int i);

int main() {

  int testCase;

  cin >> testCase;

  

  for(int s = 0; s < testCase; s++){

    int idx = 0;

    memset(visited, false, sizeof(visited));

  

    //첫째줄 입력

    char temp[4];

    cin >> temp;

    for(int j = 0; j < 3; j++){

      if(temp[j] == 'O') mydata[idx++] = 1;

      else if(temp[j] == 'X') mydata[idx++] = 0;

    }

    //둘째줄 입력

    cin >> temp;

    if(temp[0] == 'O') mydata[7] = 1;

    else if(temp[0] == 'X') mydata[7] = 0;

    if(temp[2] == 'O') mydata[3] = 1;

    else if(temp[2] == 'X') mydata[3] = 0;

  

    //셋째줄 입력

    cin >> temp;

    if(temp[0] == 'O') mydata[6] = 1;

    else if(temp[0] == 'X') mydata[6] = 0;

    if(temp[1] == 'O') mydata[5] = 1;

    else if(temp[1] == 'X') mydata[5] = 0;

    if(temp[2] == 'O') mydata[4] = 1;

    else if(temp[2] == 'X') mydata[4] = 0;

    v.clear();

    keyV.clear();

  

    for(int i = 0; i < 8; i++){

        if(mydata[i] == 1 && !visited[i])
            v.push_back(bfs(i));

    }

  

    sort(v.begin(), v.end());

    

    int keyNum;

    cin >> keyNum;

    for(int i = 0; i < keyNum; i++){

      int tempNum;

      cin >> tempNum;

      keyV.push_back(tempNum);

    }

    

    bool isCorrect = true;

    if(keyNum == v.size()){

      for(int i = 0; i < v.size(); i++){

        if(keyV[i] != v[i])

          isCorrect = false;

      }

    }

    else

      isCorrect = false;

    

    if(isCorrect)

      cout << "1" << "\n";

    else

      cout << "0" << "\n";

  }

}

int bfs(int i){

  int cnt = 1;

  visited[i] = true;

  q.push(i);

  while(!q.empty()){

    int temp = q.front();

    q.pop();

    for(int j = 0; j < 8; j++){

      if(link[temp][j] == 1 && mydata[j] == 1 && !visited[j]){

        q.push(j);

        cnt++;

        visited[j] = true;

      }

    }

  }

  return cnt;

      

}

