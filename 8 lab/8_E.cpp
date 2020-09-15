#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100000];
int dest[100000];
bool used[100000];


int main()
{
    int n,m;
    queue<int> q;
    freopen("pathbge1.in","r",stdin);
    freopen("pathbge1.out","w",stdout);
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        used[i]=false;
    for(int i=1;i<=n;i++)
        dest[i]=-1;
    q.push(1);
    used[1]=true;
    dest[1]=0;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i:graph[curr])
        {
            if(used[i]==false)
            {
                q.push(i);
                used[i]=true;
                dest[i]=dest[curr]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dest[i]!=-1)
            cout<<dest[i]<<" ";
        else
            cout<<0<<" ";
    }
    return 0;
}