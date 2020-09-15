#include <iostream>
#include <vector>
using namespace std;

vector <int> G[100010];
vector <int> Gt[100010];
vector<bool> used;
vector<int> order, component;
int res[100010];
int n, m, num=1;

void dfs_1 (int u)
{
    used[u]=1;
    for (int i=0; i<G[u].size(); i++)
    {
        if (used[G[u][i]]==0) dfs_1(G[u][i]);
    }
    order.push_back(u);
}

void dfs_2 (int u)
{
    used[u]=1;
    component.push_back(u);
    for (int i=0; i<Gt[u].size(); i++) {
        if (used[Gt[u][i]]==0) dfs_2 (Gt[u][i]);
    }
}

int main()
{
    freopen("cond.in","r",stdin);
    freopen("cond.out","w",stdout);
    cin>>n>>m;

    while (m--)
    {
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        Gt[b].push_back(a);
    }

    used.assign (n, false);

    for (int i=0; i<n; i++)
    {
        if (used[i]==0) dfs_1(i);
    }

    used.assign (n, false);

    for (int i=0; i<n; i++)
    {
        int v=order[n-1-i];
        if (used[v]==0)
        {
            dfs_2 (v);
            for(auto I=component.begin(); I!=component.end(); I++)
                res[*I]=num;
            num++;
            component.clear();
        }
    }

    cout<<num-1<<endl;
    for (int i=0; i<n-1; i++) cout << res[i] << " ";
    cout<<res[n-1]<<endl;
    return 0;
}