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
    int floor = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] <= key)
        {
            floor = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (floor == -1)
        printf("none\n");
    else
        printf("Floor = %d\n", a[floor]);

    return 0;
}