#include <iostream>
#include <queue>

using namespace std;

const int MAX = 45;
int n, W, G, I;
queue<pair<int, bool>> dice; // 두 숫자합, 주사위가 같은지 여부 T:같다
queue<pair<int ,int>> goldKey; // 황금열쇠 정보 저장
int board[MAX] = {}; // -1:황금열쇠, -2 :무인도, -3:사회복지기금, -4:우주여행, -5:시작점, 0: 이미 산 땅

long long int socialMoney = 0; // 사회복지기금
long long int money = 0;
int playerPosition = 0;
int imprisonedTurns = 0;
int buildingNum = 0; // 사지않은 빌딩 개수
bool isLose = false;

void input(){
  cin >> n >> money >> W >> G;

  // 황금열쇠 정보저장
  while(G--){
    int a, b;
    cin >> a >> b;
    goldKey.push({a, b});
  }

  // 보드판 정보 입력
  board[0] = -5; // 시작점
  board[n - 1] = -2; // 무인도
  board[2 * n - 2] = -3; // 사회복지기금
  board[3 * n - 3] = -4; // 우주여행
  
  for(int i = 0; i < 4 * n - 4; i++){
    if(board[i] == 0){ // 특수칸이 아니면
      string type; cin >> type;
      
      if(type == "L"){ // 건물
        int price; cin >> price;
        board[i] = price;
        buildingNum++;
      }
      else // 황금열쇠
        board[i] = -1;
    }
  }

  // 주사위 정보 입력
  cin >> I;
  for(int i = 0; i < I; i++){
    int a, b;
    cin >> a >> b;
    if(a == b) dice.push({a + b, true});
    else dice.push({a + b, false});
  }
}

void move() {
  playerPosition = (playerPosition + 1) % (4 * n - 4);
  if(board[playerPosition] == -5) {
    money += W;
  }
}

void act(){
  if(board[playerPosition] == -2){
    imprisonedTurns = 3;
  }
      
  else if(board[playerPosition] == -3){
    money += socialMoney;
    socialMoney = 0;
  }

  else if(board[playerPosition] > 0){ // 일반 건물
    if(money >= board[playerPosition]){
      money -= board[playerPosition];
      buildingNum--;
      board[playerPosition] = 0;
    }
  }
}

// 황금 키를 뽑을때
bool playGoldkey(){
  int type = goldKey.front().first;
  int value = goldKey.front().second;
  goldKey.pop();
  goldKey.push({type, value});

  if(type == 1){ // 은행에서 돈 받기
    money += value;
  }
  else if(type == 2){ // 은행에 돈주기
    money -= value;

    if(money < 0){
      return false;
    }
  }
  else if(type == 3){ // 사회 복지기금 내기
    money -= value;
    socialMoney += value;
    
    if(money < 0){
      return false;
    }
  }
  else{ // 움직이기
    int temp = value;
    while(temp--){
      move();
    }
    act();
  }

  return true;
}

void playGame(){
  while(!dice.empty() && isLose == false){
    int value = dice.front().first;
    bool isSame = dice.front().second;
    dice.pop();

    if(imprisonedTurns > 0){ // 감옥
      if(!isSame)
        imprisonedTurns--;
      else
        imprisonedTurns = 0;

      continue;
    }

    // 우주여행 보내기
    if(board[playerPosition] == -4){
      while(board[playerPosition] != -5)
        move();
    }

    int moveValue = value;
    while(moveValue--)
      move();

    if(board[playerPosition] == -1){ // 황금열쇠
      bool isOk = playGoldkey();
      if(!isOk)
        isLose = true;
    }
    else act(); // 열쇠아니면 행동
  }
  
  
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  input();

  playGame();

  if(isLose){
    cout << "LOSE";
  }
  else{
    if(buildingNum != 0)
      cout << "LOSE";
    else
      cout << "WIN";
  }
  return 0;
}
