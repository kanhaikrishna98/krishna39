#include <stdio.h>

int main()
{
    int n, key;
    int linear = 0, binary = 0;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    // Linear search
    for (int i = 0; i < n; i++)
    {
        linear++;

        if (a[i] == key)
            break;
    }

    // Binary search
    int low = 0, high = n - 1;
    int found = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        binary++;

        if (a[mid] == key)
        {
            found = 1;
            break;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Linear = %d, Binary = %d\n", linear, binary);

    return 0;
}