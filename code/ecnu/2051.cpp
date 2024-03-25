#include <climits>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

typedef long long ll;

using namespace std;

// 可以直接算，比较无聊

int main(int argc, char const *argv[]) {
  int K, N;
  string buf;
  while (!cin.eof()) {
    getline(cin, buf);
    if (buf.size() == 0) {
      break;
    }
    stringstream ss(buf);
    ss >> K >> N;
    ll min_unhappy = __LONG_LONG_MAX__;
    ll L = 0;
    for (int i = 2; i <= K; i++) {
      ll unhappy = 0;
      for (int j = 2; j <= K; j++) {
        if (i < j) {
          unhappy += (j - i) * N;
        } else if (i > j) {
          unhappy += i - j;
        }
      }
      if (unhappy < min_unhappy) {
        L = i;
        min_unhappy = unhappy;
      }
    }
    cout << L << endl;
  }
  return 0;
}
