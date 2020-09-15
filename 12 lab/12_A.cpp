#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector <vector <int>> &graph, int s, int t, vector <int> &parent)
{
    queue <int> q;
    vector <int> visited;
    visited.assign(graph.size(), false);
    q.push(s);
    visited[s] = true;

    int from;
    while (!q.empty())
    {
        from = q.front();
        q.pop();
        for (int to = 0; to < graph.size(); to++)
        {
            if (!visited[to] && graph[from][to] > 0)
            {
                q.push(to);
                visited[to] = true;
                parent[to] = from;
            }
        }
    }
    return visited[t];
}

int Ford_Fulkerson(vector <vector <int>> &graph, int s, int t)
{
    vector <int> parent (graph.size());
    int max_flow = 0;
    int path_flow = 0;
    int from;

    while (BFS(graph, s, t, parent))
    {
        path_flow = INT32_MAX;

        for (int to = t; to != s; to = parent[to])
        {
            from = parent[to];
            path_flow = std::min (path_flow, graph[from][to]);
        }

        for (int to = t; to != s; to = parent[to])
        {
            from = parent[to];
            graph[from][to] -= path_flow;
            graph[to][from] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() 
{
    freopen("maxflow.in","r",stdin);
    freopen("maxflow.out","w",stdout);
    int n, m;
    cin>>n>>m;

    vector <vector <int>> graph;
    graph.resize(n, vector <int> (n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int from, to, residual_flow;
    for (int i = 0; i < m; i++)
    {
        cin>>from>>to>>residual_flow;
        graph[from - 1][to - 1] = residual_flow;
    }
    cout<<Ford_Fulkerson(graph, 0, n - 1);
    return 0;
}





