#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
int n,m;
int amount=1;
bool used[100001];
int components[100001];

void dfs(int i,int a)
{
    used[i]=true;
    components[i]=a;
    for(int k=0;k<graph[i].size();k++)
    {
        int next = graph[i][k];
        if(used[next]==false)
            dfs(next,a);
    }
}


int main()
{
    freopen("components.in","r",stdin);
    freopen("components.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        used[i]=false;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==false)
        {
            dfs(i,amount);
            amount++;
        }
    }
    cout<<amount-1<<"\n";
    for(int i=1;i<=n;i++)
        cout<<components[i]<<" ";
    return 0;
}