#include <stdio.h>
#define MAX 100

struct Sparse {
  int row, col, value;
};

void sparseAddition(struct Sparse matrix_1[], struct Sparse matrix_2[], struct Sparse result[]) {
  result[0].row = matrix_1[0].row;
  result[0].col = matrix_1[0].col;

  int i = 1, j = 1, k = 1;

  while (i <= matrix_1[0].value && j <= matrix_2[0].value) {
    if (matrix_1[i].row == matrix_2[j].row && matrix_1[i].col == matrix_2[j].col) {
      result[k].row = matrix_1[i].row;
      result[k].col = matrix_1[i].col;
      result[k].value = matrix_1[i].value + matrix_2[j].value;
      i++; j++; k++;
    } else if (matrix_1[i].row > matrix_2[j].row || (matrix_1[i].row == matrix_2[j].row && matrix_1[i].col > matrix_2[j].col)) {
      result[k] = matrix_2[j];
      j++; k++;
    } else {
      result[k] = matrix_1[i];
      i++; k++;
    }
  }

  while (i <= matrix_1[0].value) {
    result[k] = matrix_1[i];
    i++; k++;
  }

  while (j <= matrix_2[0].value) {
    result[k] = matrix_2[j];
    j++; k++;
  }

  result[0].value = k - 1;
}

int main() {
  struct Sparse matrix_1[MAX], matrix_2[MAX], result[MAX];

  printf("Enter the number of rows, columns, and non-zero values in the first matrix: ");
  scanf("%d %d %d", &matrix_1[0].row, &matrix_1[0].col, &matrix_1[0].value);

  printf("Enter the number of rows, columns, and non-zero values in the second matrix: ");
  scanf("%d %d %d", &matrix_2[0].row, &matrix_2[0].col, &matrix_2[0].value);

  if (matrix_1[0].row != matrix_2[0].row || matrix_1[0].col != matrix_2[0].col) {
    printf("Invalid dimensions!");
    return -1;
  }

  printf("Enter all the rows, columns, values in the first matrix:\n");
  for (int i = 1; i <= matrix_1[0].value; i++) {
    scanf("%d %d %d", &matrix_1[i].row, &matrix_1[i].col, &matrix_1[i].value);
  }

  printf("Enter all the rows, columns, values in the second matrix:\n");
  for (int i = 1; i <= matrix_2[0].value; i++) {
    scanf("%d %d %d", &matrix_2[i].row, &matrix_2[i].col, &matrix_2[i].value);
  }

  sparseAddition(matrix_1, matrix_2, result);

  printf("Result Matrix:\n");
  printf("row\tcol\tval\n");
  for (int i = 0; i <= result[0].value; i++) {
    printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
  }

  return 0;
}
