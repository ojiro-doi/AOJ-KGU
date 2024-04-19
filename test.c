#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int n, number, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        if (is_prime(number))
        {
            c++;
        }
    }
    printf("%d\n", c);

    return 0;
}
