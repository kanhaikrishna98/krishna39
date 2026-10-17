#include <stdio.h>

int countKey(int a[], int n, int key)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
            count++;
    }

    return count;
}

int main()
{
    int n, key;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    printf("%d appears %d times\n",
           key, countKey(a, n, key));

    return 0;
}