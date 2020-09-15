#include <iostream>

using namespace std;

string a[1000], result[1000];
long n, len, m;

int Radix_sort(int pl)
{
    char letters = 'a';
    int k = 0;
    for (int i = 1; i <= 26; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j][pl] == letters)
            {
                result[k] = a[j];
                k++;
            }
        }
        letters++;
    }
    for (int i = 0; i < n; i++)
        a[i]=result[i];
}

int main()
{
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    cin >> n >> len >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = len - 1; i >= len - m; i--)
        Radix_sort(i);

    for (int i = 0; i < n; i++)
        cout << a[i] << '\n';
    return 0;
}