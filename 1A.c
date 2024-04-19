#include <stdio.h>

void insertionSort(int A[], int N)
{
    for (int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        for (int i = 0; i < N - 1; i++)
        {
            printf("%d ", A[i]);
        }
        printf("%d\n", A[N-1]);
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
    insertionSort(A, N);

    return 0;
}