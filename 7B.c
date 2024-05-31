#include <stdio.h>
#define MAX 10000
#define NIL -1

struct Node
{
  int parent;
  int left;
  int right;
};

struct Node T[MAX];
// n:節点の数 D:深さ H:高さ
int n, D[MAX], H[MAX];

// 深さを設定
void setDepth(int node_num, int d)
{
  if (node_num == NIL)
  {
    return;
  }
  D[node_num] = d;
  setDepth(T[node_num].left, d + 1);
  setDepth(T[node_num].right, d + 1);
}

// 高さを設定
int setHeight(int node_num)
{
  int h1 = 0, h2 = 0;
  if (T[node_num].left != NIL)
  {
    h1 = setHeight(T[node_num].left) + 1;
  }
  if (T[node_num].right != NIL)
  {
    h2 = setHeight(T[node_num].right) + 1;
  }
  // 左右で高さの大きい方を返す
  return H[node_num] = (h1 > h2 ? h1 : h2);
}

// 兄弟の節点番号を返す
int getSibling(int node_num)
{
  if (T[node_num].parent == NIL)
  {
    return NIL;
  }
  if (T[T[node_num].parent].left != node_num && T[T[node_num].parent].left != NIL)
  {
    return T[T[node_num].parent].left;
  }
  if (T[T[node_num].parent].right != node_num && T[T[node_num].parent].right != NIL)
  {
    return T[T[node_num].parent].right;
  }
  return NIL;
}

void print(int node_num)
{
  printf("node %d: ", node_num);
  printf("parent = %d, ", T[node_num].parent);
  printf("sibling = %d, ", getSibling(node_num));
  int deg = 0;
  if (T[node_num].left != NIL)
  {
    deg++;
  }
  if (T[node_num].right != NIL)
  {
    deg++;
  }
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[node_num]);
  printf("height = %d, ", H[node_num]);

  //ルートノードのとき
  if (T[node_num].parent == NIL)
  {
    printf("root\n");
  }
  // 葉ノードのとき
  else if (T[node_num].left == NIL && T[node_num].right == NIL)
  {
    printf("leaf\n");
  }
  //　内部ノードのとき
  else
  {
    printf("internal node\n");
  }
}

int main()
{
  // v:節点番号 l:左の子 r:右の子 root:根
  int v, l, r, root = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    T[i].parent = NIL;
  }

  for (int i = 0; i < n; i++)
  {
    scanf("%d %d %d", &v, &l, &r);
    T[v].left = l;
    T[v].right = r;
    if (l != NIL)
    {
      T[l].parent = v;
    }
    if (r != NIL)
    {
      T[r].parent = v;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (T[i].parent == NIL)
    {
      root = i;
    }
  }

  setDepth(root, 0);
  setHeight(root);

  for (int i = 0; i < n; i++)
  {
    print(i);
  }

  return 0;
}
