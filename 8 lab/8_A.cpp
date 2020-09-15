#include<iostream>

using namespace std;

int main()
{
    int n,m,i,j,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;

    int AdjacencyMatrix[100][100];
    for (int i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            AdjacencyMatrix[i][j]=0;
        }
    }

    for (int k=0; k<m; k++)
    {
        cin>>i>>j;
        AdjacencyMatrix[i-1][j-1]=1;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << AdjacencyMatrix[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}