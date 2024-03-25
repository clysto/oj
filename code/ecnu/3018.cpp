#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

inline bool same_string(string a, string b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (int i = 0; i < a.size(); i++) {
    if (tolower(a[i]) != tolower(b[i])) {
      return false;
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  string W, S;
  getline(cin, W);
  for (int i = 0; i < T; i++) {
    cout << "case #" << i << ":" << endl;
    getline(cin, W);
    getline(cin, S);
    S += ".";
    string word = "";
    int IDX = 0;
    bool find = false;
    for (auto c : S) {
      IDX += 1;
      if (c == ' ' || c == '.') {
        if (same_string(word, W)) {
          cout << IDX - word.size() << endl;
          find = true;
          break;
        }
        word = "";
        continue;
      }
      word += c;
    }
    if (!find) {
      cout << "None" << endl;
    }
  }
  return 0;
}
