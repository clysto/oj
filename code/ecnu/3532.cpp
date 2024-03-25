#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
int main(void) {
  vector<ll> cumulation_table(50000);
  ll sum = 0, num = 1;
  while (sum <= 1000000000) {
    sum += num;
    cumulation_table.push_back(sum);
    num++;
  }
  ll n;
  ll ai;
  scanf("%lld", &n);
  for (ll i = 0; i < n; ++i) {
    scanf("%lld", &ai);
    auto it = lower_bound(cumulation_table.begin(), cumulation_table.end(), ai - 1);
    if (*it == ai - 1) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
  return 0;
}
