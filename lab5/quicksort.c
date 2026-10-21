
#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int partition(int a[], int low, int high, int n)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
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

    printf("Pivot = %d, position = %d: ", pivot, i + 1);
    printArray(a, n);

    return i + 1;
}

void quickSort(int a[], int low, int high, int n)
{
    if (low < high)
    {
        int pi = partition(a, low, high, n);
        quickSort(a, low, pi - 1, n);
        quickSort(a, pi + 1, high, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1, n);

    printf("Sorted array: ");
    printArray(a, n);

    return 0;
}
