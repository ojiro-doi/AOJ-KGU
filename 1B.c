#include <stdio.h>

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    while (y != 0)
    {
        int a;
        a = x % y;
        x = y;
        y = a;
    }

    printf("%d\n", x);

    return 0;
}