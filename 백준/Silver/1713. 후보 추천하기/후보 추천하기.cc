#include <iostream>
#include <algorithm>

using namespace std;

int pictureNum, studentNum;
int picture[21][3];
// 0: 후보 번호, 1: 득표수, 2: 시간 

int main() {
  // freopen("input.txt", "r", stdin);
  
  cin >> pictureNum >> studentNum;

  // 현재 넣을 그림판 번호, 붙인 시간, 존재하는 후보의 인덱스
  int idx = 0, time = 0, candidateIdx;

  while(studentNum--){
    int candidate; cin >> candidate;
    
    // 원래 후보에 있는지 확인
    bool isCandidate = false;
    for(int i = 0; i < idx; i++){
      if(picture[i][0] == candidate){
        isCandidate = true;
        candidateIdx = i;
      }
    }
    
    // 후보에 있다면 득표수 +1
    if(isCandidate){
      picture[candidateIdx][1]++;
    }

    // 후보에 없다면 사진틀 크기 확인
    else{
      
      // 비어있지 않은 경우 학생 빼고 넣기
      if(idx >= pictureNum){
        int target = 0; // 삭제될 인덱스
        int minGet = 1005; // 추천 횟수
        int oldTime = 1005;

        // 최소 추천수 확인
        for(int i = 0; i < pictureNum; i++){ 
          if(minGet >= picture[i][1]){
            target = i;
            minGet = picture[i][1];
            oldTime = picture[i][2];
          }
        }
        // 같은 추천수에 가장 오래된 사람 탐색
        for(int i = 0; i < pictureNum; i++){ 
          if(minGet == picture[i][1] && oldTime > picture[i][2]){
            target = i;
            oldTime = picture[i][2];
          }
        }

        // cout << "target: " << target << "\n";
        
        //삭제 후 앞에서부터 땡겨오기
        for(int i = target; i < pictureNum; i++){
          picture[i][0] = picture[i + 1][0];
          picture[i][1] = picture[i + 1][1];
          picture[i][2] = picture[i + 1][2];
        }

        //가장 끝에 넣기
        picture[idx - 1][0] = candidate;
        picture[idx - 1][1] = 1;
        picture[idx - 1][2] = time; 
      }
        
      // 비어있는 경우 그냥 넣기
      else{
        picture[idx][0] = candidate;
        picture[idx][1] = 1;
        picture[idx][2] = time;
        idx++;
      }
    }
    
    time++;

    // for(int i = 0; i < idx; i++){
    //   cout << picture[i][0] << ' ';
    // }
    // cout << "\n";
  }

  int result[21]; // 최종 후보
  for(int i = 0; i < idx; i++){
    result[i] = picture[i][0];
  }

  sort(result, result + idx);

  // 답 출력
  for(int i = 0; i < idx; i++){
    cout << result[i] << ' ';
  }
}