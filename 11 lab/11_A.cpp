#include <iostream>
#include <vector>

using namespace std;
const long long MAX = 2e18;


void Dijkstra (const vector <vector <pair <int, int>>> &graph,vector <char> &used,vector <long long> &dist,int n,int vertex) 
{
    dist[vertex] = 0;
    for (int i = 0; i < n; i++) 
    {
        vertex = -1;
        for (int j = 0; j < n; j++) 
        {
            if (!used[j] && (vertex == -1 || dist[j] < dist[vertex])) vertex = j;
        }
        used[vertex] = true;
        for (int j = 0; j < graph[vertex].size(); j++) 
        {
            int to = graph[vertex][j].second;
            int weight = graph[vertex][j].first;
            dist[to] = min (dist[to], dist[vertex] + weight);
        }
    }
}


int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, startv, finishv;
    freopen("pathmgep.in","r",stdin);
    freopen("pathmgep.out","w",stdout);
    
    cin>>n>>startv>>finishv;
    vector <vector <pair <int, int>>> graph (n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            int weight;
            cin>>weight;
            if (weight != -1) graph[i].push_back({weight, j});
        }
    }
    vector <char> used;
    used.assign(n, false);
    vector <long long> dist;
    dist.assign(n, MAX);

    Dijkstra(graph, used, dist, n, startv - 1);

    if (dist[finishv - 1] != MAX) cout<<dist[finishv - 1];
    else cout<<-1;
    return 0;
}