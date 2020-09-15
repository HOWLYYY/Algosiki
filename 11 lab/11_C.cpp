#include <iostream>
#include <vector>
#include <set>

using namespace std;
const long long MAX = 1000000;


void Dijkstra (const vector <vector <pair <int, int>>> &graph,vector <long long> &dist,set <pair <long long, int>> &q,int vertex)
{
dist[vertex] = 0;
q.insert ({0, vertex});
while (!q.empty())
{
vertex = q.begin()->second;
q.erase(q.begin());
for (size_t j = 0; j < graph[vertex].size(); j++)
{
int to = graph[vertex][j].second;
int weight = graph[vertex][j].first;
if (dist[to] > dist[vertex] + weight)
{
q.erase({dist[to], to});
dist[to] = dist[vertex] + weight;
q.insert({dist[to], to});
}
}
}
}


int main ()
{
    int n, m, startR, finishR, weight;
    freopen("pathbgep.in","r",stdin);
    freopen("pathbgep.out","w",stdout);
    cin>>n>>m;

    vector <vector <pair <int, int>>> graph (n);
    for (int i = 0; i < m; i++)
    {
        cin>>startR>>finishR>>weight;
        graph[startR - 1].push_back({weight, finishR - 1});
        graph[finishR - 1].push_back({weight, startR - 1});
    }

    vector <bool> used;
    used.assign(n, false);
    vector <long long> dist;
    dist.assign(n, MAX);
    set <pair <long long, int>> q;

    Dijkstra(graph, dist, q, 0);

    for (int i = 0; i < n; i++)
        cout<<dist[i]<<" ";

    return 0;
}