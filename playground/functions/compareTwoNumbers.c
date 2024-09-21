#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max(int a, int b) {
  return a > b ? a : b;
}

int max_of_four(int a, int b, int c, int d) {
  int m = a;

  m = max(m, b);
  m = max(m, c);

  return max(m, d);
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}