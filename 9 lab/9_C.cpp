#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100000];
int color[100000];
bool bipartite=true;

void BiCheck(int start)
{
    for (int i=0; i< graph[start].size(); ++i)
        if (color[graph[start][i]]==0)
        {
            color[graph[start][i]]=3-color[start];
            BiCheck( graph[start][i]);
        }
        else if (color[graph[start][i]]==color[start]) bipartite=false;
}

int main()
{
    freopen("bipartite.in","r",stdin);
    freopen("bipartite.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
        {
            color[i]=1;
            BiCheck(i);
        }
    }
    if(!bipartite)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}