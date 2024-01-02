#include <iostream>

using namespace std;

long long a[3][3] = {};
long long b[3] = {};
long long arr[3][3] = {}; // 새로 계산 할 행렬
long long detA, detA1, detA2, detA3;

void input() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int num;
      cin >> num;
      a[i][j] = num;
      arr[i][j] = num;
    }
    cin >> b[i];
  }
}

long long calc() {
  long long l1 = arr[0][0] * (arr[1][1] * arr[2][2] - arr[2][1] * arr[1][2]);
  long long l2 = arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]);
  long long l3 = arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);

  long long result = l1 - l2 + l3;

  return result;
}

double convert(int k) {
  double result = (double)k / detA;

  if (-0.0005 < result && result < 0.0005)
    return 0;
  else
    return result;
}

void printAnswer() {
  cout << detA1 << ' ' << detA2 << ' ' << detA3 << ' ' << detA << "\n";

  if (detA == 0)
    cout << "No unique solution\n\n";
  else {
    cout << "Unique solution: ";
    cout << fixed;
    cout.precision(3);

    cout << convert(detA1) << ' ' << convert(detA2) << ' ' << convert(detA3);
    cout << "\n\n";
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    input();

    detA = calc(); // a의 행렬식 계산

    for (int i = 0; i < 3; i++)
      arr[i][0] = b[i];

    detA1 = calc();

    for (int i = 0; i < 3; i++) {
      arr[i][0] = a[i][0];
      arr[i][1] = b[i];
    }

    detA2 = calc();

    for (int i = 0; i < 3; i++) {
      arr[i][1] = a[i][1];
      arr[i][2] = b[i];
    }

    detA3 = calc();

    printAnswer();
  }
}