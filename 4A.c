#include <stdio.h>
#include <time.h>

// 線形探索
int linerSearch(int A[], int n, int key)
{
  int i = 0;
  A[n] = key;
  while (A[i] != key)
  {
    i++;
  }
  // iがnになると、keyが見つからなかったことを示す
  return i != n;
}

int main(void)
{
  int n, A[10000 + 1], q, key, count = 0;

  scanf("%d", &n);
  for (int i; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);
  for (int i; i < q; i++)
  {
    scanf("%d", &key);
    if (linerSearch(A, n, key))
    {
      count++;
    }
  }
  printf("%d\n", count);

  return 0;
}