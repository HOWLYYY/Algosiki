#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

void FloydWarshall(int n)
{
    for(int k = 0; k<n; k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
}

int main()
{
    int n,m;
    freopen("pathsg.in","r",stdin);
    freopen("pathsg.out","w",stdout);
    cin>>n>>m;
    graph.assign(n,vector<int>(n,10001));
    for(int i=0;i<m;i++)
    {
        int start,finish,weight;
        cin>>start>>finish>>weight;
        graph[start-1][finish-1] = weight;
    }
    FloydWarshall(n);
    for(int i=0;i<n;i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j) cout<<0<<" ";
            else cout<<graph[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}