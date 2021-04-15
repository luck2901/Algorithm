#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>
#include <set>

using namespace std;

#define endl "\n"

int parent[51];
vector<int> v[51];
vector<int> truth;
bool check[51];

int find(int node)
{
    if(parent[node]==node)
        return node;
    else
        return find(parent[node]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    parent[a] = b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, truePerson, result = 0;

    cin >> N >> M;

    for (int i = 0; i <= N;i++)
    {
        parent[i] = i;
    }

    cin >> truePerson;
    for (int i = 0; i < truePerson; i++)
    {
        int num;
        cin >> num;
        truth.push_back(num);
    }
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int person;
            cin >> person;
            v[i].push_back(person);
        }
    }
    for (int i = 0; i < M;i++)
    {
        int N1 = v[i][0];
        for (int j = 1; j < v[i].size(); j++)
        {
            int N2 = v[i][j];
            Union(N1, N2);
        }
    }
        for (int i = 0; i < M; i++)
        {
            bool tag = true;
            for (int j = 0; j < v[i].size(); j++)
            {
                for (int k = 0; k < truth.size(); k++)
                {
                    if(find(truth[k]) == find(v[i][j]))
                    {
                        tag = false;
                        break;
                    }
                    if(tag == false)
                        break;
                }
            }
            if (tag == true)
                result++;
        }
    cout << result << endl;
}