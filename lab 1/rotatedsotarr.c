#include <stdio.h>

int main()
{
    int n, key;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
        {
            result = mid;
            break;
        }

        // Left half is sorted
        if (a[low] <= a[mid])
        {
            if (key >= a[low] && key < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (key > a[mid] && key <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    if (result == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", result);

    return 0;
}