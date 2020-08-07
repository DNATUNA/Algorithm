#include<stdio.h>

int root(double n, double r);

int main() {
   int test = 0, n = 0, r = 0, ans = 0;
   scanf("%d", &test);

   for (int i = 0; i < test; ++i) {
      scanf("%d %d", &r, &n);

      ans = root(n, r);
      printf("%d\n", ans);
   }
}

int root(double n, double r) {
   int a = 1;
   if (n == 0 || r == 0 || n == r)
      return 1;
   if (r > n - r&&r != n) r = n - r;
   for (int i = 0; i < r; ++i) {
      a = a * n / (double)(i+1);
      n--;
   }

   return a;
}