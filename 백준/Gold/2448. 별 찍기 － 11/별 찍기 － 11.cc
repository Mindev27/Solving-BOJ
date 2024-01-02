#include <iostream>

using namespace std;

char part[][6] = {"  *  ", " * * ", "*****"};
char board[3500][6500];

void solve(int n, int y, int x) {
  if (n == 1) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 5; j++)
        board[y + i][x + j] = part[i][j];
    return;
  }
  solve(n / 2, y, x + 3 * n / 2);
  solve(n / 2, y + 3 * n / 2, x);
  solve(n / 2, y + 3 * n / 2, x + 3 * n);
}

int main() {
  int n;
  cin >> n;
  solve(n / 3, 0, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      if (board[i][j] == '*')
        cout << '*';
      else
        cout << ' ';
    }
    cout << endl;
  }

  return 0;
}
