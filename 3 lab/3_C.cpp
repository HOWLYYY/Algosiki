#include <iostream>

using namespace std;

int main()
{
    int n;
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    cin >> n;

    int A[n];
    for (int i = 1; i <= n ; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i < (n / 2); i++)
    {
        if (A[i] >= A[2*i])
        {
            cout << "NO";
            return 0;
        }
        if (A[i] >= A[2*i + 1])
        {
            cout << "NO";
            return 0;
        }

    }
    cout << "YES";
    return 0;
}