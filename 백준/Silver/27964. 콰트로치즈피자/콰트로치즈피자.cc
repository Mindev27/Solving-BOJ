#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int numOfFood;
    cin >> numOfFood;
    set<string> cheeseTypes;

    for (int i = 0; i < numOfFood; i++) {
        string food;
        cin >> food;
        // 치즈 토핑인지 확인하고, 집합에 추가
        if (food.length() >= 6 && food.substr(food.length() - 6) == "Cheese") {
            cheeseTypes.insert(food);
        }
    }

    // 집합의 크기가 4 이상인지 확인
    if (cheeseTypes.size() >= 4) {
        cout << "yummy";
    } else {
        cout << "sad";
    }

    return 0;
}
