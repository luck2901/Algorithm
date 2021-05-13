#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<int> v[31];
    stack<int> result;

    for (int i = board.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 0)
                continue;
            v[j + 1].push_back(board[i][j]);
        }
    }

    for (int i = 0; i < moves.size(); i++)
    {
        if (v[moves[i]].size() == 0)
            continue;
        else
        {
            if (result.size() != 0 && result.top() == v[moves[i]].back())
            {
                result.pop();
                answer += 2;
            }
            else
                result.push(v[moves[i]].back());
            v[moves[i]].pop_back();
        }
    }

    return answer;
}