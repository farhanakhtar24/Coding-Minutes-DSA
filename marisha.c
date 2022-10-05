#include <stdio.h>

int main()
{
    int i, n, a[10];
    printf("Enter the value of n :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Element %d :", i);
        scanf("%d", &a[i]);
    }

    for (i = 1; i <= n; i++)
    {
        printf("%d ,", 2 * a[i]);
    }

    printf("\nPrinting Again :");
    for (i = 1; i <= n; i++)
    {
        printf("%d ,", a[i]);
    }

    return 0;
}