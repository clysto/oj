#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  for (int n = 0; n < N; n++) {
    vector<int> items;
    int items_n, item_size;
    cin >> items_n;
    for (int i = 0; i < items_n; i++) {
      cin >> item_size;
      items.push_back(item_size);
    }
    bool find = false;
    for (int c = 0; c < 1 << items_n; c++) {
      int size_0 = 0, size_1 = 0;
      if (c == 0 || c == (1 << items_n) - 1) {
        continue;
      }
      for (int j = 0; j < items_n; j++) {
        if (c >> j & 1) {
          size_0 ^= items[j];
        } else {
          size_1 ^= items[j];
        }
      }
      if (size_0 == size_1) {
        find = true;
        cout << "Yes" << endl;
        for (int j = 0; j < items_n; j++) {
          if (c >> j & 1) {
            cout << "1";
          } else {
            cout << "0";
          }
        }
        cout << endl;
        break;
      }
    }
    if (!find) cout << "No" << endl;
  }
  return 0;
}
