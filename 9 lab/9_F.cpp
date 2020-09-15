#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs2(vector<vector<int>>& matrix, vector<int>& check, int pos, stack<int>& myStack);
void dfs1(vector<vector<int>>& matrix, vector<int>& check, int pos, stack<int>& myStack)
{
    if (matrix.empty())
    {
        check[pos] = 2;
        return;
    }
    for (int i = 0; i < matrix[pos].size(); i++)
    {
        if (check[matrix[pos][i]] == 2)
        {
            check[pos] = 1;
            return;
        }
        if (check[matrix[pos][i]] == 0) dfs2(matrix, check, matrix[pos][i], myStack);
        if (check[matrix[pos][i]] == 1)
        {
            check[pos] = 1;
            return;
        }
    }
    check[pos] = 2;
}

void dfs2(vector<vector<int>>& matrix, vector<int>& check, int pos, stack<int>& myStack)
{
    if (matrix.empty())
    {
        check[pos] = 1;
        return;
    }
    for (int i = 0; i < matrix[pos].size(); i++)
    {
        if (check[matrix[pos][i]] == 1)
        {
            check[pos] = 2;
            return;
        }
        if (check[matrix[pos][i]] == 0) dfs1(matrix, check, matrix[pos][i], myStack);
        if (check[matrix[pos][i]] == 2)
        {
            check[pos] = 2;
            return;
        }
    }
    check[pos] = 1;
}

int main()
{
    int n, m, start;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>m>>start;
    vector<vector<int>> matrix(n);
    vector<int> check(n);
    start--;
    for (int i = 0; i < n; i++)
        check[i] = 0;
    int v1,v2;
    for (int i = 0; i < m; i++) {
        cin>>v1>>v2;
        v1--, v2--;
        matrix[v1].push_back(v2);
    }
    stack<int> myStack;
    dfs1(matrix, check, start, myStack);
    if (check[start] % 2 != 0)
        cout << "First player wins";
    else
        cout << "Second player wins";
    return 0;
}