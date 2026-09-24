#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int **arr = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int d1 = 0;
    int d2 = 0;

    for (int i = 0; i < n; i++)
    {
        d1 += arr[i][i];
        d2 += arr[i][n - 1 - i];
    }

    printf("%d\n", abs(d1 - d2));

    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);

    return 0;
}
