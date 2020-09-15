#include <iostream>

using namespace std;

int heapbuild(int A[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapbuild(A, n, largest);
    }
}

int heapSort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapbuild(A, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp= A[0];
        A[0] = A[i];
        A[i] = temp;
        heapbuild(A, i, 0);
    }
}

int main()
{
    int n;
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    heapSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
