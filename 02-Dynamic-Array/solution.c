#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int **arr = malloc(n * sizeof(int *));
    int *size = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        arr[i] = NULL;

    int lastAnswer = 0;

    for (int i = 0; i < q; i++)
    {
        int type, x, y;

        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1)
        {
            size[idx]++;

            arr[idx] = realloc(
                arr[idx],
                size[idx] * sizeof(int)
            );

            arr[idx][size[idx] - 1] = y;
        }
        else if (type == 2)
        {
            lastAnswer = arr[idx][y % size[idx]];

            printf("%d\n", lastAnswer);
        }
    }

    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);
    free(size);

    return 0;
}
