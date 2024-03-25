#include <cstdio>

using namespace std;

int main(void) {
  int n, d;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d %d", &d, &d, &d);
    sum += 2 * d;
  }
  printf("%d\n", sum);
  return 0;
}