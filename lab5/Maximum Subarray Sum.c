#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int current = a[0];
    int maximum = a[0];

    for (int i = 1; i < n; i++)
    {
        if (current < 0)
            current = a[i];
        else
            current += a[i];

        if (current > maximum)
            maximum = current;
    }

    printf("Max sum = %d\n", maximum);

    return 0;
}