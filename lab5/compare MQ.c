#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void merge(int a[], int temp[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l; i <= r; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int temp[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(a, temp, l, m);
        mergeSort(a, temp, m + 1, r);
        merge(a, temp, l, m, r);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[i + 1];
    a[i + 1] = a[high];
    a[high] = t;

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

int main()
{
    int a[N], b[N], temp[N];

    srand((unsigned)time(NULL));

    for (int i = 0; i < N; i++)
    {
        a[i] = rand();
        b[i] = a[i];
    }

    clock_t start = clock();
    mergeSort(a, temp, 0, N - 1);
    clock_t end = clock();

    double mergeTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    quickSort(b, 0, N - 1);
    end = clock();

    double quickTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("Merge sort: %.6f s\n", mergeTime);
    printf("Quick sort: %.6f s\n", quickTime);

    return 0;
}