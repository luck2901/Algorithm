#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int up[4] = {0, 0, 0, 0};
int ri[4] = {2, 2, 2, 2};
int le[4] = {6, 6, 6, 6};
int connect[4];
int ar[4][8] = {0};

void change(int cmd, int index)
{
    if (cmd == -1)
    {
        up[index] = (up[index] + 1) % 8;
        ri[index] = (ri[index] + 1) % 8;
        le[index] = (le[index] + 1) % 8;
    }
    else
    {
        if (up[index] == 0)
            up[index] = 8;
        if (ri[index] == 0)
            ri[index] = 8;
        if (le[index] == 0)
            le[index] = 8;

        up[index] = (up[index] - 1);
        ri[index] = (ri[index] - 1);
        le[index] = (le[index] - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, result = 0;

    for (int i = 0; i < 4; i++)
    {
        string num;
        cin >> num;
        for (int j = 0; j < 8; j++)
            ar[i][j] = (num[j] - '0');
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int index, direction;
        cin >> index >> direction;
        int temp = direction;
        for (int j = 0; j < 3; j++)
        {
            connect[j] = (ar[j][ri[j]] == ar[j + 1][le[j + 1]]) ? 0 : 1;
        }
        for (int j = index - 1; j < 3; j++)
        {
            change(direction, j);
            direction *= -1;
            if (connect[j] == 0)
                break;
            if (j == 2)
                change(direction, 3);
        }
        if (index == 4)
            direction = temp;
        else
            direction = -1 * temp;
        for (int j = index - 2; j >= 0; j--)
        {
            if (j == 2)
            {
                change(direction, 3);
                direction *= -1;
            }
            if (connect[j] == 0)
                break;
            change(direction, j);
            direction *= -1;
        }
    }
    if (ar[0][up[0]] == 1)
        result += 1;
    if (ar[1][up[1]] == 1)
        result += 2;
    if (ar[2][up[2]] == 1)
        result += 4;
    if (ar[3][up[3]] == 1)
        result += 8;
    cout << result << "\n";
}