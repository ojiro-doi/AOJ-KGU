#include <stdio.h>
#define MAX 100005
// NIL:節点番号として使われない値を設定
#define NIL -1

// p:親 l:左の子 r:右の子
struct Node
{
  int p, l, r;
};

// T:節点のリスト
struct Node T[MAX];

// n:節点の個数 D:深さ
int n, D[MAX];

// 子のリストを表示
void printChildren(int u)
{
  int i, c;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].p);
  printf("depth = %d, ", D[u]);

  if (T[u].p == NIL)
  {
    printf("root, ");
  }
  else if (T[u].l == NIL)
  {
    printf("leaf, ");
  }
  else
  {
    printf("internal node, ");
  }
  printf("[");

  for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r)
  {
    if (i != 0)
    {
      printf(", ");
    }
    printf("%d", c);
  }
  printf("]\n");
}

// 節点の深さ(再帰)
void setDepth(int u, int p)
{
  D[u] = p;
  if (T[u].r != NIL)
  {
    setDepth(T[u].r, p);
  }
  if (T[u].l != NIL)
  {
    setDepth(T[u].l, p + 1);
  }
}

int main()
{
  int i, j, d, v, c, l, r;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  for (i = 0; i < n; i++)
  {
    scanf("%d %d", &v, &d);
    for (j = 0; j < d; j++)
    {
      scanf("%d", &c);
      if (j == 0)
      {
        T[v].l = c;
      }
      else
      {
        T[l].r = c;
      }
      l = c;
      T[c].p = v;
    }
  }
  for (i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      r = i;
    }
  }
  setDepth(r, 0);
  for (i = 0; i < n; i++)
  {
    printChildren(i);
  }

  return 0;
}