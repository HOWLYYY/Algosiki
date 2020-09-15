#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cyclic (int v, int &cycle_st, vector <int> *graph, vector <int> &color )
{
    color[v] = 1;
    for (size_t i = 0; i < graph[v].size(); ++i)
    {
        int to = graph[v][i];
        if (color[to] == 0)
        {
            if (cyclic (to, cycle_st, graph,  color))  return true;
        }
        else if (color[to] == 1)
        {
            cycle_st = to;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
void dfs (int v, vector <int> *graph, vector<bool> &used, vector <int> &summary)
{
    used[v] = true;
    for (int i=0; i < graph[v].size(); i++)
    {
        int to = graph[v][i];
        if (!used[to]) dfs (to, graph, used, summary);
    }
    summary.push_back (v+1);
}

void topsort(int n, vector <int> *graph, vector<bool> &used, vector <int> &summary)
{
    for (int i = 0; i < n; i++)
        used[i] = false;
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs (i, graph, used, summary);
    reverse (summary.begin(), summary.end());
}

int main()
{
    int n, m;
    freopen("topsort.in","r",stdin);
    freopen("topsort.out","w",stdout);
    cin>>n>>m;
    int a, b;
    vector <int> graph[100001];
    vector <bool> used (n);
    vector<int> summary;
    vector<int> color (n,0);
    int cycle_st = -1;
    for (int i = 0; i < m; i++){
        cin>>a>>b;
        graph[a-1].push_back(b-1);
    }
    for (int i = 0; i < n; i++){
        if (cyclic(i, cycle_st, graph, color))
            break;
    }
    if (cycle_st != -1) cout << "-1";
    else
    {
        topsort(n, graph, used, summary);
        for (int i = 0; i < summary.size(); i++)
        {
            cout<<summary[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}