#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    freopen("search1.in","r",stdin);
    freopen("search1.out","w",stdout);
    string ask, main;
    vector <int> ans;
    cin>>ask>>main;
    int flag = 0;
    for (int i = 0; i < main.size(); i++) 
    {
        if (main[i] == ask[0]) 
        {
            int p = i;
            for (int j = 0; j <= ask.size(); j++) 
            {
                if (j == ask.size()) 
                {
                    ans.push_back(i);
                    break;
                }
                if (ask[j] != main[p]) 
                {
                    flag = 0;
                    break;
                }
                p++;
            }
        }
    }
    cout<<ans.size()<<endl;
    for (int i : ans)
        cout<<i + 1<<" ";
    return 0;
}