#include <iostream>

using namespace std;


int main()
{
    long n;
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    cin>>n;
    long A[n],i;
    for(i=0;i<n;i++)
        A[i]=i+1;
    for(i=0;i<n;i++)
        swap(A[i],A[i/2]);
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
