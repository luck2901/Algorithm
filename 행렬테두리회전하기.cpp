#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[102][102];

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    int index = 1;

    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            arr[i][j] = index++;

    for (int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];

        int num = arr[x1][y1];
        int minNum = 987654321;

        for (int j = x1; j < x2; j++)
        {
            arr[j][y1] = arr[j + 1][y1];
            minNum = min(minNum, arr[j][y1]);
        }
        for (int j = y1; j < y2; j++)
        {
            arr[x2][j] = arr[x2][j + 1];
            minNum = min(minNum, arr[x2][j]);
        }
        for (int j = x2; j > x1; j--)
        {
            arr[j][y2] = arr[j - 1][y2];
            minNum = min(minNum, arr[j][y2]);
        }
        for (int j = y2; j > y1 + 1; j--)
        {
            arr[x1][j] = arr[x1][j - 1];
            minNum = min(minNum, arr[x1][j]);
        }
        arr[x1][y1 + 1] = num;
        minNum = min(minNum, arr[x1][y1 + 1]);

        answer.push_back(minNum);
    }

    return answer;
}