#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct ArrayInfo {
  int baseAddress;
  int sizePerElement;
  int dimension;
  vector<int> lowerBounds;
  vector<int> upperBounds;
};

map<string, ArrayInfo> arrayDefinitions;
vector<pair<string, vector<int>>> arrayReferences;

void input() {
  int N, R;
  cin >> N >> R;

  string name;
  for (int i = 0; i < N; ++i) {
    cin >> name;
    ArrayInfo info;
    cin >> info.baseAddress >> info.sizePerElement >> info.dimension;
    info.lowerBounds.resize(info.dimension);
    info.upperBounds.resize(info.dimension);
    for (int d = 0; d < info.dimension; ++d) {
      cin >> info.lowerBounds[d] >> info.upperBounds[d];
    }
    arrayDefinitions[name] = info;
  }

  for (int i = 0; i < R; ++i) {
    cin >> name;
    vector<int> indices(arrayDefinitions[name].dimension);
    for (int j = 0; j < arrayDefinitions[name].dimension; ++j) {
      cin >> indices[j];
    }
    arrayReferences.push_back({name, indices});
  }
}

void solve() {
  for (const auto &ref : arrayReferences) {
    const string &name = ref.first;
    const vector<int> &indices = ref.second;
    const ArrayInfo &info = arrayDefinitions[name];

    vector<int> C(info.dimension + 1);
    C[info.dimension] = info.sizePerElement;
    for (int d = info.dimension - 1; d > 0; --d) {
      C[d] = C[d + 1] * (info.upperBounds[d] - info.lowerBounds[d] + 1);
    }

    int C0 = info.baseAddress;
    for (int d = 1; d <= info.dimension; ++d) {
      C0 -= C[d] * info.lowerBounds[d - 1];
    }

    int physicalAddress = C0;
    for (int d = 0; d < info.dimension; ++d) {
      physicalAddress += C[d + 1] * indices[d];
    }

    cout << name << "[";
    for (size_t i = 0; i < indices.size(); ++i) {
      if (i > 0)
        cout << ", ";
      cout << indices[i];
    }
    cout << "] = " << physicalAddress << "\n";
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
