#include <iostream>

using namespace std;

void counting_paper(int **paper, int startX, int startY, int size, int(&cnt)[2]){

  if(size == 1){ //종이 크기가 1이면
    int color = paper[startX][startY];
    cnt[color] += 1;
  }
  else{ //모든 칸을 확인
    int first_color = paper[startX][startY];
    
    for(int i = startX; i < startX + size; i++){
      for(int j = startY; j < startY +size; j++){
        
        if(first_color != paper[i][j]) { //다르다면 4분할하여 호출
          counting_paper(paper, startX,          startY,          size/2, cnt);
          counting_paper(paper, startX + size/2, startY,          size/2, cnt);
          counting_paper(paper, startX,          startY + size/2, size/2, cnt);
          counting_paper(paper, startX + size/2, startY + size/2, size/2, cnt);
          return;
        }
        
      }
    }

    //다 같다면 색종이 +1
    cnt[first_color] += 1;
  }
}

int main() {
  const int SIZE = 128;
  int n, cnt[] = {0, 0}; //0번째는 흰, 1번째는 파
  
  cin >> n;

  //2차원 배열 동적 할당
  int **paper = new int*[n];
  for(int i = 0; i < n; i++){
    paper[i] = new int[n];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> paper[i][j];
    }
  }
  
  counting_paper(paper, 0, 0, n, cnt);

  cout << cnt[0] << "\n" << cnt[1];
}