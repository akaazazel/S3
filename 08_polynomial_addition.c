#include <stdio.h>
#define MAX 100

struct Poly {
  int coeff, exp;
};

int polynomialAddition(struct Poly poly_1[], struct Poly poly_2[], int n1, int n2, struct Poly result[]) {
  int i = 0, j = 0, k = 0;

  while (i < n1 && j < n2) {
    if (poly_1[i].exp == poly_2[j].exp) {
      result[k].exp = poly_1[i].exp;
      result[k].coeff = poly_1[i].coeff + poly_2[j].coeff;
      i++; j++; k++;
    } else if (poly_1[i].exp > poly_2[j].exp) {
      result[k] = poly_1[i];
      i++; k++;
    } else {
      result[k] = poly_2[j];
      j++; k++;
    }
  }

  while (i < n1) {
    result[k] = poly_1[i];
    i++; k++;
  }

  while (j < n2) {
    result[k] = poly_2[j];
    j++; k++;
  }

  return k;
}

void printPolynomial(struct Poly result[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%dx^%d", result[i].coeff, result[i].exp);
    if (i < size - 1) {
      printf(" + ");
    }
  }
  printf("\n");
}

int main() {
  struct Poly poly_1[MAX], poly_2[MAX], result[MAX];
  int n1, n2, n3;

  printf("Enter the number of terms in first polynomial: ");
  scanf("%d", &n1);

  printf("Enter the coefficient and exponent for each term in the first polynomial:\n");
  for (int i = 0; i < n1; i++) {
    scanf("%d %d", &poly_1[i].coeff, &poly_1[i].exp);
  }

  printf("Enter the number of terms in second polynomial: ");
  scanf("%d", &n2);

  printf("Enter the coefficient and exponent for each term in the second polynomial:\n");
  for (int i = 0; i < n2; i++) {
    scanf("%d %d", &poly_2[i].coeff, &poly_2[i].exp);
  }

  n3 = polynomialAddition(poly_1, poly_2, n1, n2, result);

  printf("Resulting Polynomial: ");
  printPolynomial(result, n3);

  return 0;
}