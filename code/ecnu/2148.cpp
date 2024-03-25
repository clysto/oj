#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// 和 2848 一样

inline bool is_item(char c) {
  if (isalpha(c)) {
    return true;
  } else if (isdigit(c)) {
    return c != '0';
  }
  return false;
}

int count_building_size(int col, char t, vector<bool> &visit, const vector<char> &m, int index) {
  if (m[index] != t || visit[index]) {
    return 0;
  }
  int s = 1;
  visit[index] = true;
  if (index - col >= 0) s += count_building_size(col, t, visit, m, index - col);
  if (index + col < m.size()) s += count_building_size(col, t, visit, m, index + col);
  if (index % col != 0) s += count_building_size(col, t, visit, m, index - 1);
  if (index % col != col - 1) s += count_building_size(col, t, visit, m, index + 1);
  return s;
}

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  for (int n = 0; n < N; n++) {
    int row, col;
    cin >> row >> col;
    vector<char> google_map;
    char p;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> p;
        google_map.push_back(p);
      }
    }
    vector<bool> visit(google_map.size(), false);
    int item_n = 0;
    for (int i = 0; i < google_map.size(); i++) {
      if (is_item(google_map[i]) && !visit[i]) {
        count_building_size(col, google_map[i], visit, google_map, i);
        item_n++;
      }
    }
    cout << item_n << endl;
  }
  return 0;
}
