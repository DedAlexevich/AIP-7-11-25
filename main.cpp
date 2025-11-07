#include <iostream>

int* resize(const int* a, size_t k, size_t d, int filler);
void resize2(int** a, size_t k, size_t d, int filler);
int* add_row(const int* a, size_t n, size_t m, int filler);

int main()
{
  int* a = new int[5]{1,2,3,4,5};
  int d = 15;
  resize2(&a, 5, d, 3);

  for (size_t i = 0; i < d; ++i ) {
    std::cout << a[i] << '\n';
  }
  delete[] a;
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