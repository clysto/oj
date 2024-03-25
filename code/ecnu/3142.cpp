#include <cstdio>
#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

/**
 * size_t - 1 不会变成负数
 */

int main(int argc, char const *argv[]) {
  string a, b;
  while (true) {
    cin >> a >> b;
    if (a == "0" && b == "0") {
      break;
    }
    int carry = 0;
    int carry_n = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
      int c = ((int)a.size() - i - 1) >= 0 ? a[a.size() - i - 1] - '0' : 0;
      int d = ((int)b.size() - i - 1) >= 0 ? b[b.size() - i - 1] - '0' : 0;
      if (c + d + carry > 9) {
        carry = (c + d + carry) / 10;
        carry_n++;
      } else {
        carry = 0;
      }
    }
    cout << carry_n << endl;
  }
  return 0;
}
