#include <iostream>

using namespace std;

int left(int A[], int supp, int n)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
        {
        int m = l + (r - l) / 2;
        if (A[m] >= supp)
            r = m;
        else
            l = m + 1;
        }
    return A[l] == supp ? (l + 1) : -1;
}

int right(int A[], int supp, int n)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
        {
        int m = r - (r - l) / 2;
        if (A[m] <= supp)
            l = m;
        else
            r = m - 1;
        }
    return A[l] == supp ? (l + 1) : -1;
}

int main()
{
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int n, m;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> m;
    int numb_ind[m];
    for(int i = 0; i < m; i++)
    {
        cin >> numb_ind[i];
    }

    for(int i = 0; i < m; i++)
    {
        cout << left(A, numb_ind[i], n) << " " << right(A, numb_ind[i], n) << "\n";
    }
    return 0;
}



