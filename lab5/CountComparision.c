#include <stdio.h>

long long comparisons;

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;

        if (a[j] <= pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void test(int n, int reverse)
{
    int a[n];

    for (int i = 0; i < n; i++)
        a[i] = reverse ? n - i : i + 1;

    comparisons = 0;
    quickSort(a, 0, n - 1);

    printf("%s: %lld\n",
           reverse ? "Reverse" : "Sorted",
           comparisons);
}

int main()
{
    int n;
    scanf("%d", &n);

    test(n, 0);
    test(n, 1);

    printf("n(n-1)/2 = %lld\n",
           (long long)n * (n - 1) / 2);

    return 0;
}