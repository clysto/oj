#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int count_building_size(int col, vector<bool> &visit, const vector<char> &m, int index) {
  if (m[index] == '.' || visit[index]) {
    return 0;
  }
  int s = 1;
  visit[index] = true;
  if (index - col >= 0) s += count_building_size(col, visit, m, index - col);
  if (index + col < m.size()) s += count_building_size(col, visit, m, index + col);
  if (index % col != 0) s += count_building_size(col, visit, m, index - 1);
  if (index % col != col - 1) s += count_building_size(col, visit, m, index + 1);
  return s;
}

int main(int argc, char const *argv[]) {
  int row, col;
  cin >> col >> row;
  vector<char> google_map;
  char p;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> p;
      google_map.push_back(p);
    }
  }
  vector<bool> visit(google_map.size(), false);
  int max_size = 0;
  for (int i = 0; i < google_map.size(); i++) {
    if (google_map[i] == '*' && !visit[i]) {
      max_size = max(max_size, count_building_size(col, visit, google_map, i));
    }
  }
  cout << max_size << endl;
  return 0;
}
