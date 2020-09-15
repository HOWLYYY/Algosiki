#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <bool> island;
vector <pair <long long, long long>> graph[1000000];

long long prim()
{
    long long ans = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> vertexQueue;
    vertexQueue.push(make_pair(0, 0));

    while (!vertexQueue.empty())
    {
        pair<long long, long long> vertexWeightPair = vertexQueue.top();
        vertexQueue.pop();
        long long dist = vertexWeightPair.first;
        long long vertex = vertexWeightPair.second;
        if (island[vertex]) continue;
        island[vertex] = true;
        ans += dist;
        for (long long i = 0; i < graph[vertex].size(); i++)
        {
            long long toVer = graph[vertex][i].first;
            long long toDis = graph[vertex][i].second;
            if (!island[toVer]) vertexQueue.push(make_pair(toDis, toVer));
        }
    }
    return ans;
}

int main()
{
    long long n, m;
    freopen("spantree3.in","r",stdin);
    freopen("spantree3.out","w",stdout);
    cin>>n>>m;
    island.resize(n, false);
    for (long long i = 0; i < m; i++)
    {
        long long a, b, dist;
        cin>>a>>b>>dist;
        graph[a - 1].emplace_back(b - 1, dist);
        graph[b - 1].emplace_back(a - 1, dist);
    }
    cout<<prim();
    return 0;
}