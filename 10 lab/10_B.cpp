#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct Point
{
    int x;
    int y;

    double DistBetPoints(const Point& a)
    {
        return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
    }
};

int main()
{
    int n;
    freopen("spantree.in","r",stdin);
    freopen("spantree.out","w",stdout);
    cin>>n;
    vector<Point> Vertex;
    bool visit[10000];
    double EdgeLen[10000];
    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
        int x, y;
        cin>>x>>y;
        Point a{ x, y };
        Vertex.push_back(a);
        if (i > 0) EdgeLen[i] = Vertex[0].DistBetPoints(a);
    }
    visit[0] = true;

    for (int i = 1; i < n; i++)
    {
        double MinLen = INT_MAX;
        int help = 0;
        for (int j = 1; j < n; j++)
        {
            if (EdgeLen[j] < MinLen && !visit[j])
            {
                MinLen = EdgeLen[j];
                help = j;
            }
        }
        visit[help] = true;
        ans += MinLen;
        for (int k = 0; k < n; k++)
        {
            if (!visit[k])
            {
                double len = Vertex[help].DistBetPoints(Vertex[k]);
                if (len < EdgeLen[k])
                    EdgeLen[k] = len;
            }
        }
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}