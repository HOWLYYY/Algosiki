#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector <int>> adjlist;
vector<bool> used;
vector<int> dist;
vector<int> path;
queue<int> q;

vector<int> pathfinder(int start, int end){
    vector<int> ans;
    for (int v = end; v != start; v = path[v])
    {
        ans.push_back(v);
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(n == 1 and m == 1) cout << -1;

    adjlist.resize(n * m);
    used.resize(n * m, false);
    dist.resize(n * m);
    path.resize(n * m);
    char graf[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> graf[i][j];
        }
    }

    int frst = -1;
    int lst = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int i2 = i + 1;
            int j2 = j + 1;
            if(graf[i][j] == 'T') lst = j + m * i;
            if(graf[i][j] == 'S') frst = j + m * i;
            if(i2 < n and graf[i][j] != '#' and graf[i2][j] != '#')
            {
                adjlist[j + i * m].push_back(j + m * i2);
                adjlist[j + i2 * m].push_back(j + m * i);
            }
            if(j2 < m and graf[i][j] != '#' and graf[i][j2] != '#')
            {
                adjlist[j + m * i].push_back(j2 + m * i);
                adjlist[j2 + m * i].push_back(j + m * i);
            }
        }
    }

    q.push(frst);
    dist[frst] = 0;
    used[frst] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int)adjlist[v].size(); i++)
        {
            int to = adjlist[v][i];
            if (used[to] == false)
            {
                path[to] = v;
                dist[to] = dist[v] + 1;
                used[to] = true;
                q.push(to);
            }
            if(to == lst){
                cout << dist[lst];
                cout << '\n';
                path = pathfinder(frst, lst);
                for(int i  = 1; i < path.size(); i++){
                    if(((path[i] - path[i - 1]) == 1) and m != 1) cout << 'R';
                    if(((path[i] - path[i - 1]) == -1) and m != 1) cout << 'L';
                    if((path[i] - path[i - 1]) == m) cout << 'D';
                    if((path[i] - path[i - 1]) == -m) cout << 'U';
                }
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}