#include <math.h>

unsigned long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  };

  unsigned long long result = 1;

  for (int i = 2; i <= n; i++) {
    result *= i;
  }

  return result;
}

double sin(double x) {
  double term = x; 
  double sum = term;
  int n = 1;

  while (n < MAX_TERMS) {
    term *= -x * x / ((2 * n) * (2 * n + 1));
    sum += term; 
    if (fabs(term) < PRECISION) {
      break;
    } 
    n++;
  }

  return sum;
}

double cos(double x) {
  double term = 1; 
  double sum = term;
  int n = 1;

  while (n < MAX_TERMS) {
    term *= -x * x / ((2 * n - 1) * (2 * n));
    sum += term;
    if (fabs(term) < PRECISION) {
      break;
    };
    n++;
  }

  return sum;
}

double fabs(double x) {
  return (x < 0) ? -x : x;
}

