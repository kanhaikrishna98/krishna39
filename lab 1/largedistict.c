#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    scanf("%d", &n);

    int a[n];
    int largest = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if (a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > second)
        {
            second = a[i];
        }
    }

    printf("Second largest = %d\n", second);

    return 0;
}