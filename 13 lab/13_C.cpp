#include <iostream>
#include <vector>
 
using namespace std;
string search;
vector<int> prefix_function(string search)
{
    int n = (int) search.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && search[i] != search[j])
            j = pi[j - 1];
        if (search[i] == search[j]) ++j;
        pi[i] = j;
    }
    return pi;
}
 
int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    cin>>search;
    for(auto i : prefix_function(search))
        cout<<i<<' ';
    return 0;
}