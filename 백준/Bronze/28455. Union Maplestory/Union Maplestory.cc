#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> player; // 레벨, 능력치

    for (int i = 0; i < n; i++) {
        int level;
        cin >> level;

        int power = 0;
        if (level >= 250) power = 5;
        else if (level >= 200) power = 4;
        else if (level >= 140) power = 3;
        else if (level >= 100) power = 2;
        else if (level >= 60) power = 1;

        player.push_back({level, power});
    }

    sort(player.begin(), player.end(), greater<pair<int, int>>()); // 레벨을 내림차순으로 정렬

    int levelSum = 0, powerSum = 0;
    for (int i = 0; i < min(n, 42); i++) {
        levelSum += player[i].first;
        powerSum += player[i].second;
    }

    cout << levelSum << ' ' << powerSum;

    return 0;
}
