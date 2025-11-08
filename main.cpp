#include <iostream>

int* resize(const int* a, size_t k, size_t d, int filler);
void resize2(int** a, size_t k, size_t d, int filler);
int* add_row(const int* a, size_t n, size_t m, int filler);
int* add_col(const int* a, size_t n, size_t m, int filler);
void add_col(int** a, size_t n, size_t m, int filler);
int* transpon(const int* a, size_t n, size_t m);

void show_matrix(int** a, size_t n, size_t m)
{
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      std::cout << a[i][j] <<'\t';
    }
    std::cout << '\n';
  }
}

int** concat_rows(const int* const* lhs, size_t n1, size_t m1,
const int* const* rhs, size_t n2, size_t m2)
{
  size_t newRows = std::max(n1,n2);
  int** matr = new int*[newRows];
  for (size_t i = 0; i < newRows; ++i) {
    matr[i] = new int[m1+m2]{};
  }

  for (size_t i = 0; i < n1; ++i) {
    for (size_t j = 0; j < m1; ++j) {
      matr[i][j] = lhs[i][j];
    }
  }

  for (size_t i = 0; i < n2; ++i) {
    for (size_t j = 0; j < m2; ++j) {
      if (i < n1) {
        matr[i][j+m1] = rhs[i][j];
      } else {
        matr[i][j] = rhs[i][j];
      }
    }
  }
  show_matrix(matr, newRows, m1+m2);

  return matr;
}


int main()
{
  int** a = new int*[2];
  int** b = new int*[2];


  a[0] = new int[3]{1,2,3};
  a[1] = new int[3]{6,7,8};

  b[0] = new int[3]{4,5,6};
  b[1] = new int[3]{9,10,11};

  show_matrix(a, 2, 3);
  show_matrix(b, 2, 3);

  int** n = concat_rows(a, 2, 3, b, 2, 3);

  delete[] a;
  delete[] b;
}

int* resize(const int* a, size_t k, size_t d, int filler)
{
  int* newArr = new int[d];
  if (d > k) {
    size_t i = 0;
    for (; i < k; i++) {
      newArr[i] = a[i];
    }
    for (; i < d; i++) {
      newArr[i] = filler;
    }
  } else {
    size_t i = 0;
    for (; i < d; i++) {
      newArr[i] = a[i];
    }
  }
  return newArr;
}

void resize2(int** a, size_t k, size_t d, int filler)
{
  int* narr = resize(*a, k, d, filler);
  delete[] *a;
  *a = narr;
}

int* add_row(const int* a, size_t n, size_t m, int filler)
{
  return resize(a, n*m, (n+1)*m, filler);
}

int* add_col(const int* a, size_t n, size_t m, int filler)
{
  int* narr = new int[n*(m+1)];
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j <= m; ++j) {
      narr[i*(m+1) + j] = a[i*m+j];
    }
    narr[i*(m+1) + m] = filler;
  }
  return narr;
}

int* transpon(const int* a, size_t n, size_t m)
{
  int* narr = new int[n*m];
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      narr[j*n + i] = a[i*m + j];
    }
  }
  return narr;
}
void add_col(int** a, size_t n, size_t m, int filler)
{
  for (size_t i = 0; i < n; ++i) {
     int* nt = resize(*(a + i), m, m+1, filler);
    delete[] a[i];
    a[i] = nt;
  }
}