#include <stdio.h>
#include <stdlib.h>

int person[5001];

int main()
{
    int N, K;
    int start = 0, end = 0;

    scanf("%d %d", &N, &K);

    end = N;

    for (int i = 0; i < N; i++)
        person[i] = i + 1;

    printf("<");
    while (N--)
    {
        if (start != end)
        {
            for (int i = 0; i < K; i++)
            {
                int temp = person[start];
                start += 1;
                if (i == K - 1)
                {
                    printf("%d", temp);
                }
                else
                {
                    person[end] = temp;
                    end += 1;
                }
                if (end == 5001)
                    end = 0;
                if (start == 5001)
                    start = 0;
            }
            if (N != 0)
            {
                printf(", ");
            }
        }
    }
    printf(">");
}