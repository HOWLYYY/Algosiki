#include <iostream>
#include <vector>

using namespace std;

vector<int> color;
vector<vector<int>> graph;
vector<int> p;
bool cycle=false;
int cycle_st=-1, cycle_end;

bool dfs (int v)
{
    color[v] = 1;
    for (size_t i=0; i<graph[v].size(); ++i)
    {
        int to = graph[v][i];
        if (color[to] == 0) {
            p[to] = v;
            if (dfs (to))
                return true;
        }
        else if (color[to] == 1)
        {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    color[v] = 2;
    return false;
}


int main()
{
    int n, m;
    freopen("cycle.in","r",stdin);
    freopen("cycle.out","w",stdout);
    cin>>n>>m;
    graph.resize(n);
    color.resize(n);
    color.assign(n,0);
    p.assign(n,-1);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1 - 1].push_back(v2 - 1);
    }
    for(int i=0;i<n;i++)
        if(dfs(i)) break;
    if(cycle_st==-1) cout<<"NO";
    else
    {
        cout<<"YES"<<"\n";
        vector<int> CyclePath;
        CyclePath.push_back(cycle_st);
        for(int i=cycle_end;i!=cycle_st;i=p[i])
            CyclePath.push_back(i);
        CyclePath.push_back(cycle_st);
        for(int i = CyclePath.size()-2;i>=0;--i)
            cout<<CyclePath[i]+1<<" ";
    }
    return 0;
}