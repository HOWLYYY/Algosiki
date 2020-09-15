#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& matrix, vector<int>& check, int pos, stack<int>& newStack)
{
    check[pos] = 1;
    for (int i = 0; i < matrix[pos].size(); i++)
    {
        if (check[matrix[pos][i]] == 0)
            if(!dfs(matrix, check, matrix[pos][i], newStack))
                return false;
        if (check[matrix[pos][i]] == 1)  return false;
    }
    newStack.push(pos);
    check[pos] = 2;
    return true;
}

int main()
{
    int n, m, v1, v2;
    freopen("hamiltonian.in","r",stdin);
    freopen("hamiltonian.out","w",stdout);
    cin>>n>>m;

    vector<vector<int>> matrix(n);
    for (int i = 0; i < m; i++)
    {
        cin>>v1>>v2;
        v1--, v2--;
        matrix[v1].push_back(v2);
    }

    vector<int> color(n);

    for (int i = 0; i < n; i++)
        color[i] = 0;
    stack<int> sort;

    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            dfs(matrix, color, i, sort);

    bool flag = true;

    while ((sort.size() > 1) && (flag))
    {
        v1 = sort.top();
        sort.pop();
        flag = false;

        for (int i : matrix[v1])
            if (i == sort.top())
                flag = true;
    }

    if (flag) cout << "YES";
    else cout << "NO";

    return 0;
}