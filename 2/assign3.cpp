#include <stdio.h>
int main() {

  int i, m;
  int s1 = 0, s2 = 1;
  int nextval = s1 + s2;
  printf("Enter the number of terms: ");
  scanf("%d", &m);
  printf("Fibonacci Series: %d, %d, ", s1, s2);
  for (i = 3; i <= m; ++i) {
    printf("%d, ", nextval);
    s1 = s2;
    s2 = nextval;
    nextval = s1 + s2;
  }
  return 0;
}
