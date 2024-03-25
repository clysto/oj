#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/**
 * DP 问题
 * 求区间最大和
*/

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> A;
  int flip_sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a) {
      flip_sum++;
      A.push_back(-1);
    } else {
      A.push_back(1);
    }
  }
  vector<int> DP(A.size());
  DP[0] = A[0];
  int max_flip = A[0];
  for (int i = 1; i < DP.size(); i++) {
    DP[i] = max(DP[i - 1] + A[i], A[i]);
    max_flip = max(max_flip, DP[i]);
  }
  cout << flip_sum + max_flip << endl;
  return 0;
}
