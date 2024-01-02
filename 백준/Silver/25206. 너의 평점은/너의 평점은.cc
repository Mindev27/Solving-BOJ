#include <stdio.h>

int main(void) {

  char subject[51] = {};
  int i, j;
  char grade[3] = {};
  double point, iGradeScore, dSum = 0, dSumPoint = 0;

  int map[4] = {'D', 'C', 'B', 'A'}; //앞문자 판별후 +, 0판별

  for (int i = 0; i < 20; i++) {
    scanf("%s", subject);
    scanf("%lf", &point);
    scanf("%s", grade);

    iGradeScore = 0;

    for (j = 0; j < 4; j++) {
      if (grade[0] == map[j]) { //학점 알파벳 일치시

        if (grade[1] == '+') {
          iGradeScore = j + 1.5;
          break;
        }

        else {
          iGradeScore = j + 1.0;
          break;
        }
      }
    }
    // P또는 F라면, iGradeScore = 0이다

    dSum += point * iGradeScore;

    if (grade[0] != 'P')
      dSumPoint += point;

  }
  printf("%lf", dSum / dSumPoint);
}