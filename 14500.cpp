#include <stdio.h>
#include <stdlib.h>

int paper[501][501];

int main()
{
    int N, M, max = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &paper[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M - 3; j++)
            if (max < paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3])
                max = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];

    for (int i = 0; i < N - 3; i++)
        for (int j = 0; j < M; j++)
            if (max < paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j])
                max = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M - 1; j++)
            if (max < paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1])
                max = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1];

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M - 2; j++)
        {
            if (max < paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2])
                max = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2];
            if (max < paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2] + paper[i][j + 2])
                max = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2] + paper[i][j + 2];
            if (max < paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2])
                max = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
            if (max < paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2])
                max = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
            if (max < paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2])
                max = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2];
            if (max < paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i + 1][j + 2])
                max = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i + 1][j + 2];
            if (max < paper[i][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2])
                max = paper[i][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2];
            if (max < paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i][j + 2])
                max = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i][j + 2];
        }

    for (int i = 0; i < N - 2; i++)
        for (int j = 0; j < M - 1; j++)
        {
            if (max < paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 2][j])
                max = paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 2][j];
            if (max < paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j])
                max = paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j];
            if (max < paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 2][j])
                max = paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 2][j];
            if (max < paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j])
                max = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j];
            if (max < paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1])
                max = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
            if (max < paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1])
                max = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
            if (max < paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1])
                max = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
            if (max < paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1])
                max = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1];
        }

    printf("%d", max);
}