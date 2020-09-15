#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, m;
    int a[100][100];
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int b, c;
        cin >> b >> c;
        if(a[b-1][c-1]==1)
        {
            cout<<"YES";
            return 0;
        }
        a[b - 1][c - 1] = 1;
        if(a[c-1][b-1]==1 && b!=c)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}