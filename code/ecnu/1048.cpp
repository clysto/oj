#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    vector<ll> time;
    for (int j = 0; j < n; j++) {
      int t;
      cin >> t;
      time.push_back(t);
    }
    sort(time.begin(), time.end());
    ll sum = 0;
    for (int j = 0; j < time.size(); j++) {
      sum += time[j] * (time.size() - j - 1);
    }
    cout << sum << endl;
  }
  return 0;
}