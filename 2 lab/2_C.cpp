#include<iostream>
using namespace std;
int Merge(int A[],int l, int mid,int r)
{

    int n1,n2,i,j,k;
    n1=mid-l+1;
    n2=r-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=A[l+i];
    }

    for(j=0;j<n2;j++)
    {
        R[j]=A[mid+j+1];
    }
    i=0,j=0;

    for(k=l;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
        }
    }
    while(i<n1)
    {
        A[k++]=L[i++];
    }
    while(j<n2)
    {
        A[k++]=R[j++];
    }
}

int MergeSort(int A[],int l,int r)
{
    int mid, count = 0  ;
    if(l<r)
    {
        mid=(l+r)/2;
        count = MergeSort(A,l,mid);
        count += MergeSort(A,mid+1,r);
        count += Merge(A,l,mid+1,r);
    }
    return count;
}
int AInversion(int A[], int n)
{
    return MergeSort(A,0,n - 1);
}
int main()
{
    int n, i;
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    cin>>n;
    int arr[n];
    for(i = 0; i < n; i++)
        cin>>arr[i];
    cout<<AInversionInversion(arr, n);;

    return 0;
}