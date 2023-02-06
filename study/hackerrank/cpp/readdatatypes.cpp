#include <cstdio>

int main()
{
  // it is more performant using scanf and printf
  // read space separated int, long, char, float and double

  int n;
  long l;
  char c;
  float f;
  double d;

  scanf("%d %ld %c %f %lf", &n, &l, &c, &f, &d);
  printf("%d\n%ld\n%c\n%f\n%lf", n, l, c, f, d);

  return 0;
}
