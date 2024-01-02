#include <stdio.h>

int number[200001]= {};

//최대공약수 구하는 gcd함수
int gcd(int x, int y) {
    int gcdtemp;
    while (x % y != 0) {
        gcdtemp = x % y;
        x = y;
        y = gcdtemp;
    }
    return y;
}

//범위의 최대공약수 계산
int GetGCD(int start, int end){
  
    if (start == end)
        return number[start];
  
    if (start + 1 == end)
        return gcd(number[start], number[end]);
  
    int i, GetGCDtemp = number[start];
  
    for (i = start; i <= end; i++) {
        GetGCDtemp = gcd(GetGCDtemp, number[i]);
    }
  
    return GetGCDtemp;
}

int Beauty(int start, int end){

  //한개짜리일때 계산
  if(start == end)
    return number[start];

  //두개일때도 계산
  if(start + 1 == end)
    return number[start] + number[end];

  int left_alive, right_alive, result, mid;

  if((start + end) % 2 == 0)
    mid = (start + end) / 2 - 1;
  else
    mid = (start + end) / 2;

  //왼쪽을 살리고 오른쪽만 계산
  left_alive = Beauty(start, mid) + GetGCD(mid + 1, end);

  //오른쪽을 살리고 왼쪽만 계산
  right_alive = GetGCD(start, mid) + Beauty(mid + 1, end);
  
  //계산한 값중 큰값을 저장
  result = left_alive > right_alive ? left_alive : right_alive;
  return result;
}

int main(){
  int N, i;

  scanf("%d", &N);

  for(i=0 ; i<N ; i++){
    scanf("%d", &number[i]);
  }

  printf("%d" ,Beauty(0, N-1));


  
}
