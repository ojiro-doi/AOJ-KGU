#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int top;
int MAX = 1000;
int S[1000];

void initialize()
{
  top = 0;
}

int isEmpty()
{
  return top == 0;
}

int isFull()
{
  return top >= MAX - 1;
}

void push(int x)
{
  if(isFull())
  {
    printf("error: stack is full\n");
  }
  top++;
  S[top] = x;
}

int pop()
{
  if(isEmpty())
  {
    printf("error: stack is empty\n");
  }
  top--;
  return S[top + 1];
}

int main(void)
{
  int a, b;
  top = 0;
  char s[MAX];
  int i = 0;
  int c = 1;
  while (scanf("%s", s) != EOF)
  {
    if (s[i] == '+')
    {
      a = pop();
      b = pop();
      push(a + b);
      c++;
    }
    else if (s[i] == '-')
    {
      b = pop();
      a = pop();
      push(a - b);
      c++;
    }
    else if (s[i] == '*')
    {
      a = pop();
      b = pop();
      push(a * b);
      c++;
    }
    else if (s[i] == '/')
    {
      a = pop();
      b = pop();
      push(a / b);
      c++;
    }
    else
    {
      push(atoi(s));
    }
    if (c > 100)
    {
      return -1;
    }
  }
  printf("%d\n", pop());

  return 0;
}